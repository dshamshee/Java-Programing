// Main class to handle division with exception handling
public class DivisionHandler {
    public static void main(String[] args) {
        try {
            // Check if two arguments are passed
            if (args.length < 2) {
                throw new ArrayIndexOutOfBoundsException("Two arguments are required.");
            }

            // Parse arguments to integers
            int num1 = Integer.parseInt(args[0]);
            int num2 = Integer.parseInt(args[1]);

            // Perform division
            int result = num1 / num2;
            System.out.println("Result of division: " + result);

        } catch (ArrayIndexOutOfBoundsException e) {
            System.out.println("Error: " + e.getMessage());
            System.out.println("Usage: java DivisionHandler <num1> <num2>");
        } catch (NumberFormatException e) {
            System.out.println("Error: Invalid number format. Please enter valid integers.");
        } catch (ArithmeticException e) {
            System.out.println("Error: Division by zero is not allowed.");
        } catch (Exception e) {
            System.out.println("An unexpected error occurred: " + e.getMessage());
        }
    }
}
