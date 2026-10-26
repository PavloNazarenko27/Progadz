import java.io.File;
import java.io.FileNotFoundException;
import java.io.PrintWriter;
import java.util.Scanner;

public class Main {
    public static int countWords(String filename) throws FileNotFoundException {
        Scanner scanner = new Scanner(new File(filename));
        int count = 0;
        while (scanner.hasNext()) {
            scanner.next();
            count++;
        }
        scanner.close();
        return count;
    }

    public static void cleanFile(String inputFilename, String outputFilename) throws FileNotFoundException {
        Scanner scanner = new Scanner(new File(inputFilename));
        PrintWriter writer = new PrintWriter(new File(outputFilename));
        boolean first = true;
        while (scanner.hasNext()) {
            String word = scanner.next();
            if (word.length() > 1 || !Character.isLetter(word.charAt(0))) {
                if (!first) {
                    writer.print(" ");
                }
                writer.print(word);
                first = false;
            }
        }
        writer.println();
        scanner.close();
        writer.close();
    }

    public static void main(String[] args) {
        try {
            String inputFile = "input.txt";
            String outputFile = "output.txt";
            System.out.println(countWords(inputFile));
            cleanFile(inputFile, outputFile);
        } catch (FileNotFoundException e) {
            System.out.println("Файл не знайдено!");
        }
    }
}