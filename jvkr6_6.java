import java.io.*;
import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        try {
            Scanner scanner = new Scanner(new File("f.txt"));
            PrintWriter writer = new PrintWriter(new File("g.txt"));
            while (scanner.hasNextLine()) {
                String line = scanner.nextLine();
                StringBuilder sb = new StringBuilder();
                for (int i = 0; i < line.length(); i++) {
                    char ch = line.charAt(i);
                    if (ch == '0') sb.append('1');
                    else if (ch == '1') sb.append('0');
                    else sb.append(ch);
                }
                writer.println(sb.toString());
            }
            scanner.close();
            writer.close();
        } catch (Exception e) {
        }
    }
}