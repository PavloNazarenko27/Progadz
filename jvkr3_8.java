import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        if (!scanner.hasNextInt()) return;
        int n = scanner.nextInt();
        int[] arr = new int[n];
        for (int i = 0; i < n; i++) arr[i] = scanner.nextInt();
        if (n == 0) return;
        if (n == 1) {
            System.out.println(arr[0]);
            return;
        }
        int max = 1;
        for (int i = 0; i < n; i++) {
            int inc = 1;
            while (i + inc < n && arr[i + inc - 1] < arr[i + inc]) inc++;
            if (inc > max) max = inc;
            int dec = 1;
            while (i + dec < n && arr[i + dec - 1] > arr[i + dec]) dec++;
            if (dec > max) max = dec;
        }
        for (int i = 0; i < n; i++) {
            int inc = 1;
            while (i + inc < n && arr[i + inc - 1] < arr[i + inc]) inc++;
            if (inc == max && max > 1) {
                for (int j = 0; j < max; j++) System.out.print(arr[i + j] + (j == max - 1 ? "" : " "));
                System.out.println();
            }
            int dec = 1;
            while (i + dec < n && arr[i + dec - 1] > arr[i + dec]) dec++;
            if (dec == max && max > 1) {
                for (int j = 0; j < max; j++) System.out.print(arr[i + j] + (j == max - 1 ? "" : " "));
                System.out.println();
            }
        }
    }
}