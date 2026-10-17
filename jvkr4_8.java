class Connection {
    private Connection() {}
    static Connection makeConnection() {
        return new Connection();
    }
}

public class Main {
    private static Connection[] pool = new Connection[3];
    private static int count = 0;

    static {
        for (int i = 0; i < pool.length; i++) {
            pool[i] = Connection.makeConnection();
        }
    }

    public static Connection getConnection() {
        if (count >= pool.length) {
            System.out.println("Об'єкти закінчилися. Завершення роботи.");
            System.exit(0);
        }
        return pool[count++];
    }

    public static void main(String[] args) {
        for (int i = 0; i < 4; i++) {
            Connection c = getConnection();
            System.out.println("Отримано з'єднання: " + c);
        }
    }
}