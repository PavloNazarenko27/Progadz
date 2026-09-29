import java.util.Scanner;

public class Main {
    public static double sideLength(double x1, double y1, double x2, double y2) {
        return Math.sqrt(Math.pow(x2 - x1, 2) + Math.pow(y2 - y1, 2));
    }
    public static double areaBySides(double a, double b, double c) {
        double p = (a + b + c) / 2;
        return Math.sqrt(p * (p - a) * (p - b) * (p - c));
    }
    public static void main(String[] args) {
        double a = 3;
        double b = 3.5 + 3.0 * 2 - 11;
        double c = b;
        double p1 = a + b + c;
        double s1 = areaBySides(a, b, c);
        System.out.println(p1);
        System.out.println(s1);
        Scanner scanner = new Scanner(System.in);
        double ax = scanner.nextDouble();
        double ay = scanner.nextDouble();
        if (scanner.hasNextLine()) scanner.nextLine();
        if (scanner.hasNextLine()) scanner.nextLine();
        double bx = scanner.nextDouble();
        double by = scanner.nextDouble();
        if (scanner.hasNextLine()) scanner.nextLine();
        if (scanner.hasNextLine()) scanner.nextLine();
        double cx = scanner.nextDouble();
        double cy = scanner.nextDouble();
        double sideA = sideLength(bx, by, cx, cy);
        double sideB = sideLength(ax, ay, cx, cy);
        double sideC = sideLength(ax, ay, bx, by);
        double s2 = areaBySides(sideA, sideB, sideC);
        System.out.println(s2);
    }
}