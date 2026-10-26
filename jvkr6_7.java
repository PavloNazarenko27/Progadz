import java.io.*;

public class Main {
    public static void main(String[] args) {
        try {
            DataInputStream dis = new DataInputStream(new FileInputStream("data.bin"));
            double sum = 0;
            try {
                while (true) {
                    sum += dis.readDouble();
                }
            } catch (EOFException e) {
            }
            dis.close();
            System.out.println(sum);
        } catch (Exception e) {
        }
    }
}