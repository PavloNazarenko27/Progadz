import java.io.*;
import java.util.*;

public class Main {
    static class LineKey {
        double a;
        double b;
        double c;

        LineKey(double x1, double y1, double x2, double y2) {
            double dx = x1 - x2;
            double dy = y1 - y2;
            if (Math.abs(dx) < 1e-9) {
                this.a = 1.0;
                this.b = 0.0;
                this.c = -x1;
            } else {
                double k = dy / dx;
                double m = y1 - k * x1;
                this.a = -k;
                this.b = 1.0;
                this.c = -m;
            }
            double norm = Math.hypot(this.a, this.b);
            if (norm > 0) {
                this.a = Math.round((this.a / norm) * 1e6) / 1e6;
                this.b = Math.round((this.b / norm) * 1e6) / 1e6;
                this.c = Math.round((this.c / norm) * 1e6) / 1e6;
                if (this.a < 0 || (Math.abs(this.a) < 1e-9 && this.b < 0)) {
                    this.a = -this.a;
                    this.b = -this.b;
                    this.c = -this.c;
                }
            }
        }

        @Override
        public boolean equals(Object o) {
            if (this == o) return true;
            if (!(o instanceof LineKey)) return false;
            LineKey lk = (LineKey) o;
            return Double.compare(lk.a, a) == 0 && Double.compare(lk.b, b) == 0 && Double.compare(lk.c, c) == 0;
        }

        @Override
        public int hashCode() {
            return Objects.hash(a, b, c);
        }
    }

    public static void main(String[] args) {
        try {
            Scanner sc = new Scanner(System.in);
            int n = sc.nextInt();
            double[] x = new double[n];
            double[] y = new double[n];
            for (int i = 0; i < n; i++) {
                x[i] = sc.nextDouble();
                y[i] = sc.nextDouble();
            }

            Map<LineKey, Set<Integer>> map = new HashMap<>();
            for (int i = 0; i < n; i++) {
                for (int j = i + 1; j < n; j++) {
                    LineKey key = new LineKey(x[i], y[i], x[j], y[j]);
                    map.computeIfAbsent(key, k -> new HashSet<>()).add(i);
                    map.get(key).add(j);
                }
            }

            PrintWriter pw = new PrintWriter(new File("lines.txt"));
            for (Map.Entry<LineKey, Set<Integer>> e : map.entrySet()) {
                int cnt = e.getValue().size();
                if (cnt > 1) {
                    LineKey lk = e.getKey();
                    pw.println(lk.a + "x + " + lk.b + "y + " + lk.c + " = 0 -> " + cnt);
                }
            }
            pw.close();
        } catch (Exception e) {
        }
    }
}