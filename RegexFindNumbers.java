import java.util.regex.*;

public class RegexFindNumbers {
    public static void main(String[] args) {
        // Input string
        String input = "The order 123 contains 45.67 items at a price of 89.99.";

        // Regular expression patterns
        String integerPattern = "\\b\\d+\\b"; // Matches integers
        String decimalPattern = "\\b\\d+\\.\\d+\\b"; // Matches decimal numbers

        // Compile patterns
        Pattern intPattern = Pattern.compile(integerPattern);
        Pattern decPattern = Pattern.compile(decimalPattern);

        // Match integers
        System.out.println("Integers found:");
        Matcher intMatcher = intPattern.matcher(input);
        while (intMatcher.find()) {
            System.out.println(intMatcher.group());
        }

        // Match decimals
        System.out.println("\nDecimal values found:");
        Matcher decMatcher = decPattern.matcher(input);
        while (decMatcher.find()) {
            System.out.println(decMatcher.group());
        }
    }
}
