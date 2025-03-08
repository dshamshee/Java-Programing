import java.util.*;
public class MyArrayList {
    public static void main(String[] args) {
        // Creating an ArrayList to store Strings
        ArrayList<String> names = new ArrayList<>();
        names.add("Danish");
        names.add("Nasreen");
        names.add("Muskan");
        System.out.println(names);

        for (String element : names) {
            System.out.println(element);
        }


        // Access Fiest Element
        System.out.println("First Name: "+ names.get(0));

        
        // Modifiying element
        names.set(0, "Shamshee");
        System.out.println("Modified names: "+ names);

        ///Removing Elements
        names.remove(2);
        System.out.println("After Removal: " + names);

        // Size of ArrayList
        System.out.println("Size of ArrayList: " + names.size());

        // Iterating throug ArrayList
        for (String element : names) {
            System.out.println(element);
            
        }

        // // Accessing elements by index
        // System.out.println("First name: " + names.get(0));

        // // Modifying an element
        // names.set(1, "Eve");
        // System.out.println("Updated Names: " + names);

        // // Removing an element
        // names.remove(2); // Removes "Bob"
        // System.out.println("After Removal: " + names);

        // // Size of ArrayList
        // System.out.println("Size: " + names.size());

        // // Iterating through ArrayList
        // System.out.println("Iterating:");
        // for (String name : names) {
        //     System.out.println(name);
        // }
    }
}
