import java.util.ArrayList;
import java.util.Arrays;
import java.util.List;
import java.util.Scanner;
import java.util.stream.IntStream;

public class Main {
    private record ExtremaPoint(int index, double value) {}
    private record AscendingSegment(int start, int end, int length, double[] values) {}

    public static void main(String[] args) {
        double[] sequence = readSequence();
        if (sequence.length == 0) {
            throw new IllegalArgumentException("Sequence must not be empty.");
        }
        int n = sequence.length;
        List<ExtremaPoint> localMaxima = IntStream.range(1, n - 1)
                .filter(i -> sequence[i] > sequence[i - 1] && sequence[i] > sequence[i + 1])
                .mapToObj(i -> new ExtremaPoint(i, sequence[i]))
                .toList();
        List<ExtremaPoint> localMinima = IntStream.range(1, n - 1)
                .filter(i -> sequence[i] < sequence[i - 1] && sequence[i] < sequence[i + 1])
                .mapToObj(i -> new ExtremaPoint(i, sequence[i]))
                .toList();
        long upToDownTransitions = IntStream.range(1, n - 1)
                .filter(i -> sequence[i] > sequence[i - 1] && sequence[i] > sequence[i + 1])
                .count();
        long downToUpTransitions = IntStream.range(1, n - 1)
                .filter(i -> sequence[i] < sequence[i - 1] && sequence[i] < sequence[i + 1])
                .count();
        AscendingSegment longest = findLongestAscending(sequence);
        System.out.println("Local maxima: " + localMaxima);
        System.out.println("Local minima: " + localMinima);
        System.out.println("Up-to-down transitions: " + upToDownTransitions);
        System.out.println("Down-to-up transitions: " + downToUpTransitions);
        System.out.println("Longest ascending segment: start=" + longest.start()
                + ", end=" + longest.end()
                + ", length=" + longest.length()
                + ", values=" + Arrays.toString(longest.values()));
    }

    private static AscendingSegment findLongestAscending(double[] seq) {
        int bestStart = 0;
        int bestLen = 1;
        int curStart = 0;
        int curLen = 1;
        for (int i = 1; i < seq.length; i++) {
            if (seq[i] > seq[i - 1]) {
                curLen++;
            } else {
                if (curLen > bestLen) {
                    bestLen = curLen;
                    bestStart = curStart;
                }
                curStart = i;
                curLen = 1;
            }
        }
        if (curLen > bestLen) {
            bestLen = curLen;
            bestStart = curStart;
        }
        int bestEnd = bestStart + bestLen - 1;
        double[] sub = IntStream.rangeClosed(bestStart, bestEnd)
                .mapToDouble(i -> seq[i])
                .toArray();
        return new AscendingSegment(bestStart, bestEnd, bestLen, sub);
    }

    private static double[] readSequence() {
        Scanner scanner = new Scanner(System.in);
        List<Double> list = new ArrayList<>();
        while (scanner.hasNext()) {
            String token = scanner.next();
            double val = Double.parseDouble(token);
            if (!Double.isFinite(val)) {
                throw new IllegalArgumentException("Non-finite value in sequence: " + token);
            }
            list.add(val);
        }
        return list.stream().mapToDouble(Double::doubleValue).toArray();
    }
}