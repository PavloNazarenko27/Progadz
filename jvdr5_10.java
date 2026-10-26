import java.util.Scanner;

public class Main {
    public static String shiftText(String text, int key) {
        StringBuilder res = new StringBuilder();
        for (int i = 0; i < text.length(); i++) {
            char ch = text.charAt(i);
            if (ch >= 'a' && ch <= 'z') {
                char shifted = (char) ('a' + (ch - 'a' + key) % 26);
                res.append(shifted);
            } else if (ch >= 'а' && ch <= 'і' || ch == 'ї' || ch == 'є' || ch == 'ґ') {
                String ua = "абвгґдежзиіїйклмнопрстуфхцчшщьюя";
                int idx = ua.indexOf(ch);
                if (idx != -1) {
                    int newIdx = (idx + key) % ua.length();
                    if (newIdx < 0) newIdx += ua.length();
                    res.append(ua.charAt(newIdx));
                } else {
                    res.append(ch);
                }
            } else {
                res.append(ch);
            }
        }
        return res.toString();
    }

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        if (!scanner.hasNextLine()) return;
        String text = scanner.nextLine();
        if (!scanner.hasNextInt()) return;
        int key = scanner.nextInt();
        System.out.println(shiftText(text, key));
    }
}