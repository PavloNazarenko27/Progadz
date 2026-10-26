import java.io.*;
import java.util.*;

public class Main {
    public static void main(String[] args) {
        try {
            int n = 3;
            Scanner scanner = new Scanner(new File("input.txt"));
            List<Integer> nums = new ArrayList<>();
            while (scanner.hasNextInt()) {
                nums.add(scanner.nextInt());
            }
            scanner.close();

            PrintWriter writer = new PrintWriter(new File("output.txt"));
            int maxGlobal = nums.isEmpty() ? 0 : nums.get(0);
            for (int i = 0; i < nums.size(); i += n) {
                int localMax = nums.get(i);
                for (int j = i; j < Math.min(i + n, nums.size()); j++) {
                    if (nums.get(j) > localMax) localMax = nums.get(j);
                    if (nums.get(j) > maxGlobal) maxGlobal = nums.get(j);
                }
                writer.println(localMax);
            }
            writer.println(maxGlobal);
            writer.close();
        } catch (Exception e) {
        }
    }
}