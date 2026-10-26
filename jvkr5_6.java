import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        if (!scanner.hasNextLine()) return;
        String s = scanner.nextLine();
        StringBuilder r1 = new StringBuilder();
        for (int i = 0; i < s.length(); i++) {
            char ch = s.charAt(i);
            if (!Character.isDigit(ch)) {
                r1.append(ch);
                if (ch == '+' || ch == '-') {
                    r1.append(ch);
                }
            }
        }
        System.out.println(r1.toString());

        StringBuilder r2 = new StringBuilder();
        for (int i = 0; i < s.length(); i++) {
            char ch = s.charAt(i);
            if (ch == '+' && i + 1 < s.length() && Character.isDigit(s.charAt(i + 1))) {
                continue;
            }
            r2.append(ch);
        }
        System.out.println(r2.toString());

        StringBuilder r3 = new StringBuilder();
        for (int i = 0; i < s.length(); i++) {
            if (i > 0 && s.charAt(i - 1) == 'с' && s.charAt(i) == 'в') {
                continue;
            }
            r3.append(s.charAt(i));
        }
        System.out.println(r3.toString());

        String r4 = s.replace("ph", "f");
        System.out.println(r4);

        String r5 = s.replaceAll("\\s+", " ").trim();
        System.out.println(r5);
    }
}