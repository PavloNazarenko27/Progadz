import java.util.Scanner;

public class Main {
    public static long factLoop(int n) {
        long res = 1;
        for (int i = 1; i <= n; i++) res *= i;
        return res;
    }

    public static long factRec(int n) {
        if (n <= 1) return 1;
        return n * factRec(n - 1);
    }

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        if (!scanner.hasNextInt()) {
            System.out.println("Число не натуральне!");
            return;
        }
        int n = scanner.nextInt();
        if (n <= 0) {
            System.out.println("Число не натуральне!");
            return;
        }
        System.out.println(factLoop(n));
        System.out.println(factRec(n));
    }
}