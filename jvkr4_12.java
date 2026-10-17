import java.util.ArrayList;
import java.util.List;

public class Main {
    static class Payment {
        private List<Item> items = new ArrayList<>();

        class Item {
            private String name;
            private double price;

            Item(String name, double price) {
                this.name = name;
                this.price = price;
            }

            public double getPrice() { return price; }
            public String getName() { return name; }
        }

        public void addItem(String name, double price) {
            items.add(new Item(name, price));
        }

        public double calculateTotal() {
            double total = 0;
            for (Item item : items) total += item.getPrice();
            return total;
        }

        public void printInvoice() {
            for (Item item : items) {
                System.out.println(item.getName() + ": " + item.getPrice());
            }
            System.out.println("Всього: " + calculateTotal());
        }
    }

    public static void main(String[] args) {
        Payment payment = new Payment();
        payment.addItem("Ноутбук", 25000);
        payment.addItem("Мишка", 500);
        payment.printInvoice();
    }
}