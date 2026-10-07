public class Main {
    public static void main(String[] args) {
        if (args.length == 0) return;
        long num = Long.parseLong(args[0]);
        long temp = num;
        long sumEven = 0;
        long sumOdd = 0;
        for (int i = 2; i <= 12; i++) {
            long digit = temp % 10;
            if (i % 2 == 0) {
                sumEven += digit;
            } else {
                sumOdd += digit;
            }
            temp /= 10;
        }
        long total = 3 * sumEven + sumOdd;
        long d1 = (10 - (total % 10)) % 10;
        System.out.println(args[0] + d1);
    }
}