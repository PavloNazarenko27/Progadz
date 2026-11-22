import java.io.*;

public class Main {
    public static void main(String[] args) {
        try {
            DataOutputStream dos = new DataOutputStream(new FileOutputStream("data.bin"));
            int[] vals = {100, 200, 300, 400, 500};
            for (int v : vals) {
                dos.writeInt(v);
            }
            dos.close();

            DataInputStream dis = new DataInputStream(new FileInputStream("data.bin"));
            long[] idx = new long[vals.length];
            long pos = 0;
            int k = 0;
            try {
                while (true) {
                    idx[k] = pos;
                    dis.readInt();
                    pos += 4;
                    k++;
                }
            } catch (EOFException e) {
            }
            dis.close();

            RandomAccessFile raf = new RandomAccessFile("data.bin", "r");
            int target = 2;
            raf.seek(idx[target]);
            System.out.println(raf.readInt());
            raf.close();
        } catch (Exception e) {
        }
    }
}