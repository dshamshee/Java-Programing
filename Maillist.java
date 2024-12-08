import java.util.*;

// Address class with data members
class Address {
    private String name;
    private String city;
    private String state;

    // Constructor
    public Address(String name, String city, String state) {
        this.name = name;
        this.city = city;
        this.state = state;
    }

    // Override toString for easy display
    @Override
    public String toString() {
        return "Name: " + name + ", City: " + city + ", State: " + state;
    }
}

// Main class to demonstrate linked list with Address objects
public class Maillist {
    public static void main(String[] args) {
        // Create a LinkedList to hold Address objects
        LinkedList<Address> addressList = new LinkedList<>();

        // Add Address objects to the LinkedList
        addressList.add(new Address("Danish", "Patna", "Bihar"));
        addressList.add(new Address("Muskan", "Gaya", "Bihar"));
        addressList.add(new Address("Raushni", "Saran", "Bihar"));

        // Display the contents using Iterator
        System.out.println("Mailing List:");
        Iterator<Address> iterator = addressList.iterator();
        while (iterator.hasNext()) {
            System.out.println(iterator.next());
        }
    }
}
