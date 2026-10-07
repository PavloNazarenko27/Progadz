import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int low = 1;
        int high = 1000000;
        while (low <= high) {
            int mid = low + (high - low) / 2;
            System.out.println("Це число " + mid + "? (Введіть '=', '>', або '<'):");
            String ans = scanner.next();
            if (ans.equals("=")) {
                System.out.println("Загадане число: " + mid);
                break;
            } else if (ans.equals(">")) {
                low = mid + 1;
            } else if (ans.equals("<")) {
                high = mid - 1;
            }
        }
    }
}