import java.util.concurrent.ArrayBlockingQueue;
import java.util.concurrent.BlockingQueue;
public class Main {
    public static void main(String[] args) {
        long t1 = 200;
        long t2 = 300;
        BlockingQueue<String> queue = new ArrayBlockingQueue<>(100);
        Thread producer = new Thread(() -> {
            int id = 1;
            try {
                while (!Thread.currentThread().isInterrupted()) {
                    Thread.sleep(t1);
                    queue.put("Msg-" + id++);
                }
            } catch (InterruptedException e) {
                Thread.currentThread().interrupt();
            }
        });
        Thread consumer = new Thread(() -> {
            try {
                while (!Thread.currentThread().isInterrupted()) {
                    String msg = queue.take();
                    Thread.sleep(t2);
                    System.out.println("Processed: " + msg);
                }
            } catch (InterruptedException e) {
                Thread.currentThread().interrupt();
            }
        });
        producer.start();
        consumer.start();
        try {
            Thread.sleep(2000);
        } catch (InterruptedException e) {
            Thread.currentThread().interrupt();
        }
        producer.interrupt();
        consumer.interrupt();
    }
}