import java.util.ArrayList;
import java.util.List;
import java.util.concurrent.BlockingQueue;
import java.util.concurrent.LinkedBlockingQueue;
import java.util.concurrent.ThreadLocalRandom;
import java.util.concurrent.TimeUnit;
public class Main {
    static class Customer {
        final int id;
        Customer(int id) {
            this.id = id;
        }
    }
    public static void main(String[] args) {
        int cashiers = 3;
        int customersCount = 12;
        List<BlockingQueue<Customer>> queues = new ArrayList<>();
        for (int i = 0; i < cashiers; i++) {
            queues.add(new LinkedBlockingQueue<>());
        }
        List<Thread> cashierThreads = new ArrayList<>();
        for (int i = 0; i < cashiers; i++) {
            final int idx = i;
            Thread t = new Thread(() -> {
                ThreadLocalRandom rnd = ThreadLocalRandom.current();
                try {
                    while (!Thread.currentThread().isInterrupted()) {
                        Customer c = queues.get(idx).poll(200, TimeUnit.MILLISECONDS);
                        if (c != null) {
                            System.out.println("Cashier " + idx + " serving customer " + c.id);
                            Thread.sleep(rnd.nextLong(250, 600));
                            System.out.println("Cashier " + idx + " finished customer " + c.id);
                        }
                    }
                } catch (InterruptedException e) {
                    Thread.currentThread().interrupt();
                }
            });
            cashierThreads.add(t);
            t.start();
        }
        List<Thread> customerThreads = new ArrayList<>();
        for (int i = 1; i <= customersCount; i++) {
            final int id = i;
            Thread t = new Thread(() -> {
                ThreadLocalRandom rnd = ThreadLocalRandom.current();
                try {
                    Thread.sleep(rnd.nextLong(50, 400));
                    int cur = 0;
                    for (int q = 1; q < queues.size(); q++) {
                        if (queues.get(q).size() < queues.get(cur).size()) {
                            cur = q;
                        }
                    }
                    Customer me = new Customer(id);
                    queues.get(cur).put(me);
                    System.out.println("Customer " + id + " joined queue " + cur);
                    while (queues.get(cur).contains(me)) {
                        int best = cur;
                        for (int q = 0; q < queues.size(); q++) {
                            if (queues.get(q).size() + 1 < queues.get(best).size()) {
                                best = q;
                            }
                        }
                        if (best != cur && queues.get(cur).remove(me)) {
                            queues.get(best).put(me);
                            System.out.println("Customer " + id + " switched from queue " + cur + " to " + best);
                            cur = best;
                        }
                        Thread.sleep(100);
                    }
                } catch (InterruptedException e) {
                    Thread.currentThread().interrupt();
                }
            });
            customerThreads.add(t);
            t.start();
        }
        try {
            for (Thread t : customerThreads) {
                t.join();
            }
            Thread.sleep(1500);
        } catch (InterruptedException e) {
            Thread.currentThread().interrupt();
        }
        for (Thread t : cashierThreads) {
            t.interrupt();
        }
    }
}