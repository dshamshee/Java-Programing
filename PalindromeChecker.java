public class PalindromeChecker {

    public static void main(String[] args) {
        // Check if the user provided an input number
        if (args.length != 1) {
            System.out.println("Please provide exactly one number as a command line argument.");
            return;
        }

        // Try to parse the input number
        try {
            int num = Integer.parseInt(args[0]);
            if (isPalindrome(num)) {
                System.out.println(num + " is a palindrome.");
            } else {
                System.out.println(num + " is not a palindrome.");
            }
        } catch (NumberFormatException e) {
            System.out.println("Invalid input. Please enter a valid integer.");
        }
    }

    // Method to check if the number is a palindrome
    public static boolean isPalindrome(int num) {
        int originalNum = num;
        int reversedNum = 0;
        
        // Reverse the number
        while (num != 0) {
            int digit = num % 10;
            reversedNum = reversedNum * 10 + digit;
            num /= 10;
        }

        // Check if the original number is equal to the reversed number
        return originalNum == reversedNum;
    }
}
