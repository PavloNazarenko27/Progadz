import java.util.Scanner;

public class Main {
    public static int parseAndAdd(String s1, String s2) {
        String num1Str = s1.replaceAll("[^0-9]", "");
        String num2Str = s2.replaceAll("[^0-9]", "");
        int n1 = num1Str.isEmpty() ? 0 : Integer.parseInt(num1Str);
        int n2 = num2Str.isEmpty() ? 0 : Integer.parseInt(num2Str);
        return n1 + n2;
    }

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        if (!scanner.hasNextLine()) return;
        String s1 = scanner.nextLine();
        if (!scanner.hasNextLine()) return;
        String s2 = scanner.nextLine();
        System.out.println(parseAndAdd(s1, s2));
    }
}