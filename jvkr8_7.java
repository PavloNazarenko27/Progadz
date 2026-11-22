import java.util.concurrent.Semaphore;
import java.util.concurrent.ThreadLocalRandom;
public class Main {
    public static void main(String[] args) {
        int operators = 3;
        int clientsCount = 6;
        long t1 = 100, t2 = 300;
        long t3 = 300, t4 = 700;
        long t5 = 200, t6 = 500;
        Semaphore availableOperators = new Semaphore(operators, true);
        for (int i = 1; i <= clientsCount; i++) {
            final int id = i;
            new Thread(() -> {
                ThreadLocalRandom rnd = ThreadLocalRandom.current();
                try {
                    Thread.sleep(rnd.nextLong(t1, t2 + 1));
                    while (!Thread.currentThread().isInterrupted()) {
                        if (availableOperators.tryAcquire()) {
                            try {
                                System.out.println("Client " + id + " connected to operator");
                                Thread.sleep(rnd.nextLong(t3, t4 + 1));
                                System.out.println("Client " + id + " finished call");
                                break;
                            } finally {
                                availableOperators.release();
                            }
                        } else {
                            System.out.println("Client " + id + " busy, redialing...");
                            Thread.sleep(rnd.nextLong(t5, t6 + 1));
                        }
                    }
                } catch (InterruptedException e) {
                    Thread.currentThread().interrupt();
                }
            }).start();
        }
    }
}