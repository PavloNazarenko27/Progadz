import java.util.*;

public class Main {
    static class Car {
        double p;
        double v;

        Car(double p, double v) {
            this.p = p;
            this.v = v;
        }
    }

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        if (!sc.hasNextInt()) return;
        int n = sc.nextInt();
        Car[] cars = new Car[n];
        for (int i = 0; i < n; i++) {
            double p = sc.nextDouble();
            double v = sc.nextDouble();
            cars[i] = new Car(p, v);
        }
        Arrays.sort(cars, Comparator.comparingDouble(c -> c.p));
        long cnt = 0;
        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                if (cars[i].v > cars[j].v) {
                    cnt++;
                }
            }
        }
        System.out.println(cnt);
    }
}