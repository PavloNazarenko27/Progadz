public class Main {
    interface Publication {
        void printInfo();
    }

    static abstract class Book implements Publication {
        private String title;
        private String author;

        Book(String title, String author) {
            this.title = title;
            this.author = author;
        }

        public String getTitle() { return title; }
        public String getAuthor() { return author; }
    }

    static class ReferenceBook extends Book {
        ReferenceBook(String title, String author) {
            super(title, author);
        }
        public void printInfo() {
            System.out.println("Довідник: " + getTitle() + " (" + getAuthor() + ")");
        }
    }

    static class Encyclopedia extends Book {
        Encyclopedia(String title, String author) {
            super(title, author);
        }
        public void printInfo() {
            System.out.println("Енциклопедія: " + getTitle() + " (" + getAuthor() + ")");
        }
    }

    public static void main(String[] args) {
        Publication ref = new ReferenceBook("C++ Довідник", "Страуструп");
        Publication enc = new Encyclopedia("Британіка", "Колектив");
        ref.printInfo();
        enc.printInfo();
    }
}