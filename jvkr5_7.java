import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        if (!scanner.hasNextLine()) return;
        String text = scanner.nextLine();
        String res = text.replaceAll("\\b(small|large)\\b", "very $1");
        System.out.println(res);
    }
}