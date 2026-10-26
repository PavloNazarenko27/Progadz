import java.io.*;
import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        try {
            int[] nums = {10, 25, 30, 45, 50};
            DataOutputStream dos = new DataOutputStream(new FileOutputStream("numbers.bin"));
            for (int n : nums) {
                dos.writeInt(n);
            }
            dos.close();

            DataInputStream dis = new DataInputStream(new FileInputStream("numbers.bin"));
            PrintWriter writer = new PrintWriter(new File("numbers.txt"));
            int sum = 0;
            int count = 0;
            boolean first = true;
            try {
                while (true) {
                    int n = dis.readInt();
                    sum += n;
                    count++;
                    if (!first) {
                        writer.print(" ");
                    }
                    writer.print(n);
                    first = false;
                }
            } catch (EOFException e) {
            }
            dis.close();
            writer.println();
            writer.close();

            double avg = count == 0 ? 0 : (double) sum / count;
            System.out.println("Середнє арифметичне: " + avg);
        } catch (Exception e) {
        }
    }
}