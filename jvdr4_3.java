import java.util.Scanner;

public class Main {
    static class Bus {
        private String driver;
        private String busNumber;
        private int routeNumber;
        private String brand;
        private int startYear;
        private double mileage;

        public Bus(String driver, String busNumber, int routeNumber, String brand, int startYear, double mileage) {
            this.driver = driver;
            this.busNumber = busNumber;
            this.routeNumber = routeNumber;
            this.brand = brand;
            this.startYear = startYear;
            this.mileage = mileage;
        }

        public int getRouteNumber() { return routeNumber; }
        public int getStartYear() { return startYear; }
        public double getMileage() { return mileage; }

        public void printInfo() {
            System.out.println(driver + " | " + busNumber + " | Маршрут: " + routeNumber + " | " + brand + " | Рік: " + startYear + " | Пробіг: " + mileage);
        }
    }

    public static void main(String[] args) {
        Bus[] buses = {
            new Bus("Іванов І.І.", "AA1234AA", 10, "Volvo", 2015, 150000),
            new Bus("Петров П.П.", "AA5678AA", 10, "Mercedes", 2018, 90000),
            new Bus("Сидоров С.С.", "AA9012AA", 25, "MAN", 2010, 250000),
            new Bus("Ковальчук К.К.", "AA3456AA", 25, "Isuzu", 2020, 45000)
        };

        Scanner scanner = new Scanner(System.in);
        
        int targetRoute = scanner.nextInt();
        for (Bus b : buses) {
            if (b.getRouteNumber() == targetRoute) b.printInfo();
        }

        int currentYear = 2026;
        int targetYears = scanner.nextInt();
        for (Bus b : buses) {
            if ((currentYear - b.getStartYear()) > targetYears) b.printInfo();
        }

        double targetMileage = scanner.nextDouble();
        for (Bus b : buses) {
            if (b.getMileage() > targetMileage) b.printInfo();
        }
    }
}