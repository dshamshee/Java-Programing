// Super and Sub class
// Base class
class SuperClass {
    int x; // Variable in the superclass

    // Constructor to initialize x
    SuperClass(int x) {
        this.x = x;
    }

    // Method to display x in the superclass
    void show() {
        System.out.println("Value of x in SuperClass: " + x);
    }
}

// Subclass
class SubClass extends SuperClass {
    int x; // Variable in the subclass

    // Constructor to initialize x in both superclass and subclass
    SubClass(int superX, int subX) {
        super(superX); // Initialize x in the superclass
        this.x = subX; // Initialize x in the subclass
    }

    // Override show() to display x in both superclass and subclass
    @Override
    void show() {
        super.show(); // Call superclass show() method
        System.out.println("Value of x in SubClass: " + x);
    }
}

// Main class to test the code
public class Super_Sub_class {
    public static void main(String[] args) {
        SubClass obj = new SubClass(10, 20);
        obj.show(); // Display values of x in both superclass and subclass
    }
}
