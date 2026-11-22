import java.io.IOException;
import java.io.UncheckedIOException;
import java.nio.charset.StandardCharsets;
import java.nio.file.Files;
import java.nio.file.Path;
import java.util.ArrayList;
import java.util.DoubleSummaryStatistics;
import java.util.List;
import java.util.Locale;
import java.util.stream.Stream;

public class Main {
    public static void main(String[] args) throws IOException {
        if (args.length != 2) {
            throw new IllegalArgumentException("Usage: java Main <directory> <delta>");
        }
        Path root = Path.of(args[0]);
        double delta = parseFiniteDouble(args[1], "delta");
        if (delta < 0) {
            throw new IllegalArgumentException("delta must be non-negative.");
        }
        if (!Files.isDirectory(root)) {
            throw new IllegalArgumentException("Directory does not exist or is not a directory: " + root);
        }
        List<Path> files;
        try (Stream<Path> walk = Files.walk(root)) {
            files = walk.filter(Files::isRegularFile)
                    .filter(Main::isMeasurementFile)
                    .sorted()
                    .toList();
        }
        List<Double> measurements = new ArrayList<>();
        for (Path file : files) {
            readMeasurements(file, measurements);
        }
        if (measurements.isEmpty()) {
            throw new IllegalArgumentException("No measurements found in matching files under: " + root);
        }
        DoubleSummaryStatistics stats = measurements.stream()
                .mapToDouble(Double::doubleValue)
                .summaryStatistics();
        List<Double> sorted = measurements.stream()
                .sorted()
                .toList();
        double mean = stats.getAverage();
        List<Double> deviations = measurements.stream()
                .filter(v -> Math.abs(v - mean) > delta)
                .toList();
        System.out.println("Files: " + files);
        System.out.println("Count: " + stats.getCount());
        System.out.println("Mean: " + mean);
        System.out.println("Min: " + stats.getMin());
        System.out.println("Max: " + stats.getMax());
        System.out.println("Sorted: " + sorted);
        System.out.println("Values with |x - mean| > " + delta + ": " + deviations);
        System.out.println("Trimmed mean: " + computeTrimmedMean(sorted, stats.getMin(), stats.getMax()));
    }

    private static String computeTrimmedMean(List<Double> sorted, double min, double max) {
        if (Double.compare(min, max) == 0) {
            return String.valueOf(min);
        }
        List<Double> trimmed = new ArrayList<>(sorted);
        trimmed.remove(min);
        trimmed.remove(max);
        if (trimmed.isEmpty()) {
            return "cannot compute: no measurements remain after removing min and max.";
        }
        double avg = trimmed.stream().mapToDouble(Double::doubleValue).average().orElseThrow();
        return String.valueOf(avg);
    }

    private static boolean isMeasurementFile(Path path) {
        String name = path.getFileName().toString().toLowerCase(Locale.ROOT);
        return name.startsWith("log") && name.endsWith(".txt");
    }

    private static void readMeasurements(Path file, List<Double> destination) throws IOException {
        try (Stream<String> lines = Files.lines(file, StandardCharsets.UTF_8)) {
            List<Double> parsed = new ArrayList<>();
            int[] lineNum = {0};
            lines.forEachOrdered(line -> {
                lineNum[0]++;
                if (!line.isBlank()) {
                    try {
                        parsed.add(parseFiniteDouble(line.trim(), "value"));
                    } catch (IllegalArgumentException ex) {
                        throw new UncheckedIOException(
                                new IOException(file + ":" + lineNum[0] + ": " + ex.getMessage(), ex));
                    }
                }
            });
            destination.addAll(parsed);
        } catch (UncheckedIOException ex) {
            throw ex.getCause();
        }
    }

    private static double parseFiniteDouble(String text, String name) {
        try {
            double value = Double.parseDouble(text);
            if (!Double.isFinite(value)) {
                throw new IllegalArgumentException(name + " must be a finite number: " + text);
            }
            return value;
        } catch (NumberFormatException exception) {
            throw new IllegalArgumentException(name + " must be a number: " + text, exception);
        }
    }
}