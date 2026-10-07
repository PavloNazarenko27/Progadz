import java.util.Random;
import java.util.Scanner;

public class Main {
    public static void fillRandom(int[][] a, int n) {
        Random rand = new Random();
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                a[i][j] = rand.nextInt(2 * n + 1) - n;
            }
        }
    }

    public static void fillConsole(int[][] a, int n, Scanner scanner) {
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                a[i][j] = scanner.nextInt();
            }
        }
    }

    public static void printMatrix(int[][] a, int n) {
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                System.out.print(a[i][j] + (j == n - 1 ? "" : " "));
            }
            System.out.println();
        }
    }

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int n = scanner.nextInt();
        int[][] a = new int[n][n];
        fillRandom(a, n);
        printMatrix(a, n);
        fillConsole(a, n, scanner);
        printMatrix(a, n);
    }
}