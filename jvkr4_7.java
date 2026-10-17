import java.util.ArrayList;
import java.util.List;

public class Main {
    static class Point {
        double x, y;
        Point(double x, double y) { this.x = x; this.y = y; }
    }

    static class Quad {
        Point a, b, c, d;
        Quad(Point a, Point b, Point c, Point d) {
            this.a = a; this.b = b; this.c = c; this.d = d;
        }

        double dist(Point p1, Point p2) {
            return Math.sqrt(Math.pow(p2.x - p1.x, 2) + Math.pow(p2.y - p1.y, 2));
        }

        double perimeter() {
            return dist(a, b) + dist(b, c) + dist(c, d) + dist(d, a);
        }

        double area() {
            return Math.abs(a.x * (b.y - d.y) + b.x * (c.y - a.y) + c.x * (d.y - b.y) + d.x * (a.y - c.y)) / 2.0;
        }

        String getType() {
            double ab = dist(a, b), bc = dist(b, c), cd = dist(c, d), da = dist(d, a);
            double ac = dist(a, c), bd = dist(b, d);
            boolean eqSides = Math.abs(ab - bc) < 1e-5 && Math.abs(bc - cd) < 1e-5 && Math.abs(cd - da) < 1e-5;
            boolean eqDiag = Math.abs(ac - bd) < 1e-5;
            boolean oppSides = Math.abs(ab - cd) < 1e-5 && Math.abs(bc - da) < 1e-5;
            if (eqSides && eqDiag) return "Квадрат";
            if (eqSides) return "Ромб";
            if (oppSides && eqDiag) return "Прямокутник";
            return "Довільний";
        }
    }

    public static void main(String[] args) {
        List<Quad> quads = new ArrayList<>();
        quads.add(new Quad(new Point(0,0), new Point(0,2), new Point(2,2), new Point(2,0)));
        quads.add(new Quad(new Point(0,0), new Point(0,3), new Point(4,3), new Point(4,0)));
        quads.add(new Quad(new Point(0,0), new Point(1,2), new Point(2,0), new Point(1,-2)));
        quads.add(new Quad(new Point(0,0), new Point(1,4), new Point(5,3), new Point(3,0)));

        String[] types = {"Квадрат", "Прямокутник", "Ромб", "Довільний"};
        for (String type : types) {
            int count = 0;
            Quad minQ = null, maxQ = null;
            for (Quad q : quads) {
                if (q.getType().equals(type)) {
                    count++;
                    if (minQ == null || q.area() < minQ.area()) minQ = q;
                    if (maxQ == null || q.area() > maxQ.area()) maxQ = q;
                }
            }
            System.out.println(type + ": " + count);
            if (minQ != null) {
                System.out.println("  Мін. площа: " + minQ.area());
                System.out.println("  Макс. площа: " + maxQ.area());
            }
        }
    }
}