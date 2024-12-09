import java.io.*;
import java.text.SimpleDateFormat;
import java.util.*;

public class FileOperations {

    // Method to accept strings, convert to uppercase, and store in a file
    public static void saveUppercaseStringsToFile(String filename, List<String> strings) {
        try (BufferedWriter writer = new BufferedWriter(new FileWriter(filename))) {
            for (String str : strings) {
                writer.write(str.toUpperCase());
                writer.newLine();
            }
            System.out.println("Strings successfully written to file: " + filename);
        } catch (IOException e) {
            System.out.println("Error writing to file: " + e.getMessage());
        }
    }

    // Method to write a double value and the current date to a file
    public static void writeDoubleAndDateToFile(String filename, double value) {
        try (BufferedWriter writer = new BufferedWriter(new FileWriter(filename))) {
            writer.write("Double value: " + value);
            writer.newLine();

            String currentDate = new SimpleDateFormat("yyyy-MM-dd HH:mm:ss").format(new Date());
            writer.write("Date: " + currentDate);
            writer.newLine();

            System.out.println("Double value and date successfully written to file: " + filename);
        } catch (IOException e) {
            System.out.println("Error writing to file: " + e.getMessage());
        }
    }

    // Method to delete a file or directory
    public static void deleteFileOrDirectory(String path) {
        File file = new File(path);
        if (file.exists()) {
            if (file.delete()) {
                System.out.println("File or directory deleted successfully: " + path);
            } else {
                System.out.println("Failed to delete file or directory: " + path);
            }
        } else {
            System.out.println("File or directory not found: " + path);
        }
    }

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);

        // Part 1: Accept strings from user, convert to uppercase, and save to file
        System.out.println("Enter strings to save to file (type 'exit' to finish):");
        List<String> strings = new ArrayList<>();
        while (true) {
            String input = scanner.nextLine();
            if (input.equalsIgnoreCase("exit")) {
                break;
            }
            strings.add(input);
        }
        saveUppercaseStringsToFile("strings.txt", strings);

        // Part 2: Write double value and date to file
        System.out.print("Enter a double value to save: ");
        double value = scanner.nextDouble();
        writeDoubleAndDateToFile("double_and_date.txt", value);

        // Part 3: Delete a file or directory
        scanner.nextLine(); // Consume newline left by nextDouble
        System.out.print("Enter the file or directory path to delete: ");
        String pathToDelete = scanner.nextLine();
        deleteFileOrDirectory(pathToDelete);

        scanner.close();
    }
}
