public class Main {
    public static void main(String[] args) {
        long n = args.length > 0 ? Long.parseLong(args[0]) : 87539319;
        long limit = (long) Math.cbrt(n);
        for (long a = 1; a <= limit; a++) {
            long a3 = a * a * a;
            for (long b = a + 1; b <= limit; b++) {
                long sum1 = a3 + b * b * b;
                if (sum1 > n) break;
                for (long c = a + 1; c <= limit; c++) {
                    long c3 = c * c * c;
                    if (c3 >= sum1) break;
                    for (long d = c + 1; d <= limit; d++) {
                        long sum2 = c3 + d * d * d;
                        if (sum2 > sum1) break;
                        if (sum1 == sum2) {
                            System.out.println(sum1 + " = " + a + "^3 + " + b + "^3 = " + c + "^3 + " + d + "^3");
                        }
                    }
                }
            }
        }
    }
}