public class MethodOverloadingExample {

    // Method to add two integers
    public int addfunc(int a, int b) {
        return a + b;
    }

    // Method to add two doubles
    public double addfunc(double a, double b) {
        return a + b;
    }

    public static void main(String[] args) {
        MethodOverloadingExample obj = new MethodOverloadingExample();

        // Calling the method with integer parameters
        int intResult = obj.addfunc(10, 20);
        System.out.println("Sum of integers: " + intResult);

        // Calling the method with double parameters
        double doubleResult = obj.addfunc(10.5, 20.3);
        System.out.println("Sum of doubles: " + doubleResult);
    }
}
