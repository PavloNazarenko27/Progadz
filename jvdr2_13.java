public class Main {
    public static void main(String[] args) {
        int r = (int) (Math.random() * 8) + 1;
        int res = (r >= 6) ? 6 : r;
        System.out.println(res);
    }
}