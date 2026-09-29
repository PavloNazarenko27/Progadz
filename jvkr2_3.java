import java.util.Scanner;

public class Main {
    public static void permute(int[] arr, boolean[] used, int index) {
        if (index == arr.length) {
            for (int i : arr) System.out.print(i);
            System.out.println();
            return;
        }
        for (int i = 1; i <= arr.length; i++) {
            if (!used[i]) {
                used[i] = true;
                arr[index] = i;
                permute(arr, used, index + 1);
                used[i] = false;
            }
        }
    }

    public static void arrange(int n, int k, int[] arr, boolean[] used, int index) {
        if (index == k) {
            for (int i = 0; i < k; i++) System.out.print(arr[i] + (i == k - 1 ? "" : " "));
            System.out.println();
            return;
        }
        for (int i = 1; i <= n; i++) {
            if (!used[i]) {
                used[i] = true;
                arr[index] = i;
                arrange(n, k, arr, used, index + 1);
                used[i] = false;
            }
        }
    }

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int n = scanner.nextInt();
        int k = scanner.nextInt();
        permute(new int[n], new boolean[n + 1], 0);
        arrange(n, k, new int[k], new boolean[n + 1], 0);
    }
}