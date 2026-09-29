import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        double x = scanner.nextDouble();
        double res = Math.pow(x, 8);
        System.out.printf("%025.4f\n", res);
    }
}