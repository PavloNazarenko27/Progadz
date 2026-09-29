public class Main {
    public static void main(String[] args) {
        int a = 0b0101;
        int b = 0b1010;
        System.out.println(Integer.toBinaryString(a & b));
        System.out.println(Integer.toBinaryString(a | b));
        System.out.println(Integer.toBinaryString(a ^ b));
        System.out.println(Integer.toBinaryString(~a));
        System.out.println(Integer.toBinaryString(~b));
        System.out.println(Integer.toBinaryString(a << 1));
        System.out.println(Integer.toBinaryString(b >> 1));
        System.out.println(Integer.toBinaryString(b >>> 1));
    }
}