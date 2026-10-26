import java.io.*;

public class Main {
    static class Faculty implements Serializable {
        private String name;

        public Faculty(String name) {
            this.name = name;
        }

        public String getName() {
            return name;
        }
    }

    static class Institute implements Serializable {
        private String name;
        private Faculty[] faculties;

        public Institute(String name, Faculty[] faculties) {
            this.name = name;
            this.faculties = faculties;
        }

        public void printInfo() {
            System.out.println("Інститут: " + name);
            for (Faculty f : faculties) {
                System.out.println(" Факультет: " + f.getName());
            }
        }
    }

    public static void main(String[] args) {
        try {
            Faculty[] facs = {new Faculty("ФІОТ"), new Faculty("ТЕФ")};
            Institute inst = new Institute("КПІ", facs);

            ObjectOutputStream oos = new ObjectOutputStream(new FileOutputStream("institute.ser"));
            oos.writeObject(inst);
            oos.close();

            ObjectInputStream ois = new ObjectInputStream(new FileInputStream("institute.ser"));
            Institute restored = (Institute) ois.readObject();
            ois.close();

            restored.printInfo();
        } catch (Exception e) {
        }
    }
}