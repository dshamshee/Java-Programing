import java.util.Scanner;

public class SwapAndFactorial {

    // Method to swap two numbers without using a third variable
    public static void swap(int a, int b) {
        System.out.println("Before swapping: a = " + a + ", b = " + b);
        
        // Swapping logic
        a = a + b;  // a now contains the sum of a and b
        b = a - b;  // b is now the original value of a
        a = a - b;  // a is now the original value of b
        
        System.out.println("After swapping: a = " + a + ", b = " + b);
    }

    // Method to find the factorial of a number
    public static int factorial(int n) {
        if (n == 0) {
            return 1;  // Base case: factorial of 0 is 1
        }
        int result = 1;
        for (int i = 1; i <= n; i++) {
            result *= i;
        }
        return result;
    }

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);

        // Swapping part
        System.out.print("Enter the first number to swap: ");
        int num1 = scanner.nextInt();
        System.out.print("Enter the second number to swap: ");
        int num2 = scanner.nextInt();

        swap(num1, num2);

        // Factorial part
        System.out.print("\nEnter a number to find its factorial: ");
        int num = scanner.nextInt();
        int fact = factorial(num);
        
        System.out.println("The factorial of " + num + " is " + fact);
    }
}
