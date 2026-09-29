import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        double r = scanner.nextDouble();
        double r2 = scanner.nextDouble();
        double rt = (r2 - r) / 2.0;
        double rc = (r2 + r) / 2.0;
        double v = 2 * Math.PI * rc * Math.PI  * rt * rt;
        System.out.println(v);
    }
}