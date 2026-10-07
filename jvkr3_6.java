public class Main {
    public static void main(String[] args) {
        String[] arr = {"java", "code", "array", "string"};
        for (int i = 0; i < arr.length; i++) {
            System.out.print(arr[i] + (i == arr.length - 1 ? "" : ", "));
        }
        System.out.println();
        for (int i = 0; i < arr.length; i++) {
            System.out.println("[" + i + "] " + arr[i]);
        }
    }
}