public class PrimeNumbersInArray {

    public static void main(String[] args) {
        // Check if the user provided the array of numbers
        if (args.length == 0) {
            System.out.println("Please provide an array of integers as command line arguments.");
            return;
        }

        // Convert the command-line arguments into an integer array
        int[] numbers = new int[args.length];
        for (int i = 0; i < args.length; i++) {
            try {
                numbers[i] = Integer.parseInt(args[i]);
            } catch (NumberFormatException e) {
                System.out.println("Invalid input: " + args[i] + " is not a valid integer.");
                return;
            }
        }

        // Find and print the prime numbers from the array
        System.out.println("Prime numbers in the array:");
        boolean foundPrime = false;
        for (int num : numbers) {
            if (isPrime(num)) {
                System.out.print(num + " ");
                foundPrime = true;
            }
        }

        // If no prime numbers are found, print a message
        if (!foundPrime) {
            System.out.println("No prime numbers found.");
        }
    }

    // Method to check if a number is prime
    public static boolean isPrime(int num) {
        if (num <= 1) {
            return false; // Numbers less than or equal to 1 are not prime
        }

        for (int i = 2; i <= Math.sqrt(num); i++) {
            if (num % i == 0) {
                return false; // Not a prime number
            }
        }

        return true; // Prime number
    }
}
