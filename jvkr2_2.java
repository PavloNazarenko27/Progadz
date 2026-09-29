import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int num = scanner.nextInt();
        int bit = scanner.nextInt();
        int val = scanner.nextInt();
        if (val == 1) {
            num |= (1 << bit);
        } else {
            num &= ~(1 << bit);
        }
        System.out.println(num + " 0x" + Integer.toHexString(num).toUpperCase() + " " + Integer.toBinaryString(num));
    }
}