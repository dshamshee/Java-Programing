import java.util.*;

public class ArrayListToArray {

    public static void main(String[] args) {
        // Create an ArrayList
        ArrayList<Integer> arrayList = new ArrayList<>();

        // Add elements to the ArrayList
        Scanner scanner = new Scanner(System.in);
        System.out.println("Enter numbers to add to the ArrayList (type 'done' to finish):");
        while (scanner.hasNext()) {
            String input = scanner.next();
            if (input.equalsIgnoreCase("done")) {
                break;
            }
            try {
                int number = Integer.parseInt(input);
                arrayList.add(number);
            } catch (NumberFormatException e) {
                System.out.println("Invalid input. Please enter an integer or 'done' to finish.");
            }
        }

        // Convert ArrayList to array
        Integer[] array = arrayList.toArray(new Integer[0]);

        // Display the contents of the array
        System.out.println("Contents of the array:");
        int sum = 0;
        for (int num : array) {
            System.out.print(num + " ");
            sum += num;
        }
        System.out.println();

        // Display the sum of the numbers
        System.out.println("Sum of the numbers: " + sum);

        scanner.close();
    }
}
