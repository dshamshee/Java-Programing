class SumCalculator extends Thread {
    private int number;
    private int sum;

    public SumCalculator(int number) {
        this.number = number;
    }

    @Override
    public void run() {
        sum = 0;
        for (int i = 1; i <= number; i++) {
            sum += i;
            try {
                Thread.sleep(100); // Simulate a delay
            } catch (InterruptedException e) {
                System.out.println("SumCalculator interrupted.");
            }
        }
        System.out.println("Sum of numbers up to " + number + " is: " + sum);
    }
}

class FactorialCalculator extends Thread {
    private int number;
    private long factorial;

    public FactorialCalculator(int number) {
        this.number = number;
    }

    @Override
    public void run() {
        factorial = 1;
        for (int i = 1; i <= number; i++) {
            factorial *= i;
            try {
                Thread.sleep(100); // Simulate a delay
            } catch (InterruptedException e) {
                System.out.println("FactorialCalculator interrupted.");
            }
        }
        System.out.println("Factorial of " + number + " is: " + factorial);
    }
}

public class SumAndFactorial {
    public static void main(String[] args) {
        int number = 5; // Example number to calculate sum and factorial

        // Create threads
        SumCalculator sumThread = new SumCalculator(number);
        FactorialCalculator factorialThread = new FactorialCalculator(number);

        // Start threads
        sumThread.start();
        factorialThread.start();

        // Wait for threads to complete
        try {
            sumThread.join();
            factorialThread.join();
        } catch (InterruptedException e) {
            System.out.println("Main thread interrupted.");
        }

        System.out.println("Calculations completed.");
    }
}
