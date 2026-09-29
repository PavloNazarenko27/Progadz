public class Main {
    public static void main(String[] args) {
        if (args.length >= 3) {
            System.out.println(args[0] + " " + args[1] + " " + args[2]);
        }
        double sum = 0;
        int count = 0;
        for (String arg : args) {
            try {
                sum += Double.parseDouble(arg);
                count++;
            } catch (NumberFormatException e) {
            }
        }
        System.out.println(sum);
        System.out.println(count);
    }
}