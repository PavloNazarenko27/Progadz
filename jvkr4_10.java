import java.util.ArrayList;
import java.util.Comparator;
import java.util.List;
import java.util.Scanner;

public class Main {
    static abstract class Flower {
        private String name;
        private double price;
        private int freshness;
        private double stemLength;

        Flower(String name, double price, int freshness, double stemLength) {
            this.name = name;
            this.price = price;
            this.freshness = freshness;
            this.stemLength = stemLength;
        }

        public double getPrice() { return price; }
        public int getFreshness() { return freshness; }
        public double getStemLength() { return stemLength; }
        public String getName() { return name; }
    }

    static class Rose extends Flower {
        Rose(double price, int freshness, double stemLength) {
            super("Троянда", price, freshness, stemLength);
        }
    }

    static class Tulip extends Flower {
        Tulip(double price, int freshness, double stemLength) {
            super("Тюльпан", price, freshness, stemLength);
        }
    }

    static class Bouquet {
        private List<Flower> flowers = new ArrayList<>();
        private double accessoryPrice = 50.0;

        void addFlower(Flower f) { flowers.add(f); }
        double getTotalPrice() {
            double total = accessoryPrice;
            for (Flower f : flowers) total += f.getPrice();
            return total;
        }

        void sortByFreshness() {
            flowers.sort(Comparator.comparingInt(Flower::getFreshness));
        }

        List<Flower> findByStemLength(double min, double max) {
            List<Flower> res = new ArrayList<>();
            for (Flower f : flowers) {
                if (f.getStemLength() >= min && f.getStemLength() <= max) res.add(f);
            }
            return res;
        }

        void printBouquet() {
            for (Flower f : flowers) {
                System.out.println(f.getName() + " | Свіжість: " + f.getFreshness() + " | Довжина: " + f.getStemLength() + " | Ціна: " + f.getPrice());
            }
        }
    }

    public static void main(String[] args) {
        Bouquet bouquet = new Bouquet();
        bouquet.addFlower(new Rose(100, 2, 50));
        bouquet.addFlower(new Tulip(60, 1, 35));
        bouquet.addFlower(new Rose(120, 3, 60));

        Scanner scanner = new Scanner(System.in);
        System.out.println("1 - Вартість, 2 - Сортувати, 3 - Пошук");
        if (scanner.hasNextInt()) {
            int opt = scanner.nextInt();
            if (opt == 1) {
                System.out.println("Вартість: " + bouquet.getTotalPrice());
            } else if (opt == 2) {
                bouquet.sortByFreshness();
                bouquet.printBouquet();
            } else if (opt == 3) {
                double min = scanner.nextDouble();
                double max = scanner.nextDouble();
                for (Flower f : bouquet.findByStemLength(min, max)) {
                    System.out.println(f.getName() + " " + f.getStemLength());
                }
            }
        }
    }
}