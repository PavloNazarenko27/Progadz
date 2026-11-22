import java.util.*;

public class Main {
    public static void main(String[] args) {
        int n = 50000;
        int step = 2;

        long t1 = System.nanoTime();
        List<Integer> al = new ArrayList<>();
        for (int i = 1; i <= n; i++) al.add(i);
        int idx1 = 0;
        while (al.size() > 1) {
            idx1 = (idx1 + step - 1) % al.size();
            al.remove(idx1);
        }
        long dt1 = System.nanoTime() - t1;

        long t2 = System.nanoTime();
        List<Integer> ll = new LinkedList<>();
        for (int i = 1; i <= n; i++) ll.add(i);
        int idx2 = 0;
        while (ll.size() > 1) {
            idx2 = (idx2 + step - 1) % ll.size();
            ll.remove(idx2);
        }
        long dt2 = System.nanoTime() - t2;

        System.out.println("ArrayList ns: " + dt1);
        System.out.println("LinkedList ns: " + dt2);
    }
}