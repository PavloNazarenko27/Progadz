import java.io.*;
import java.util.*;

public class Main {
    public static void main(String[] args) {
        try {
            List<String> list = new ArrayList<>();
            Scanner sc = new Scanner(new File("input.txt"));
            while (sc.hasNextLine()) {
                list.add(sc.nextLine());
            }
            sc.close();

            Collections.sort(list);

            for (String s : list) {
                System.out.println(s);
            }
        } catch (Exception e) {
        }
    }
}