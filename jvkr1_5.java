import java.util.Scanner;

public class Main {
    public static double f(double x) {
        double x3 = x * x * x;
        return x3 * (x3 * x3 + 1) + 1;
    }
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        double x = scanner.nextDouble();
        System.out.println(f(x));
    }
}