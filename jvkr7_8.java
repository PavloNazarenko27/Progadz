import java.util.*;

public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        if (!sc.hasNextLine()) return;
        String text = sc.nextLine();
        String[] words = text.toLowerCase().split("\\W+");
        int total = 0;
        for (String w : words) {
            if (!w.isEmpty()) total++;
        }
        Map<String, Integer> freq = new HashMap<>();
        for (String w : words) {
            if (!w.isEmpty()) {
                freq.put(w, freq.getOrDefault(w, 0) + 1);
            }
        }
        for (String target : args) {
            String key = target.toLowerCase();
            int c = freq.getOrDefault(key, 0);
            double rel = total == 0 ? 0.0 : (double) c / total;
            System.out.println(target + ": " + rel);
        }
    }
}