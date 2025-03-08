import java.io.IOException;

public class MultiProcessingExample {
    public static void main(String[] args) {
        try {
            // Create a new process to run the "notepad" application
            ProcessBuilder processBuilder = new ProcessBuilder("notepad.exe");
            Process process = processBuilder.start();
            System.out.println("Process started: Notepad");

            // Wait for the process to complete
            process.waitFor();
            System.out.println("Process finished.");
        } catch (IOException | InterruptedException e) {
            e.printStackTrace();
        }
    }
}
