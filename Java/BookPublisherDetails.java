import java.util.Scanner;

// Base class Publisher
class Publisher {
    String publisherName;
    int publisherId;

    // Method to get data for the publisher
    public void getData() {
        Scanner scanner = new Scanner(System.in);

        System.out.print("Enter publisher name: ");
        publisherName = scanner.nextLine();

        System.out.print("Enter publisher ID: ");
        publisherId = scanner.nextInt();
    }

    // Method to show data for the publisher
    public void showData() {
        System.out.println("Publisher Name: " + publisherName);
        System.out.println("Publisher ID: " + publisherId);
    }
}

// Derived class Book
class Book extends Publisher {
    String bookName;
    int bookId;
    String authorName;

    // Method to get data for the book
    @Override
    public void getData() {
        super.getData(); // Call Publisher's getData() method to get publisher details

        Scanner scanner = new Scanner(System.in);  // Create a new scanner object to avoid input issues

        System.out.print("Enter book name: ");
        bookName = scanner.nextLine();

        System.out.print("Enter book ID: ");
        bookId = scanner.nextInt();

        scanner.nextLine();  // Clear the buffer
        System.out.print("Enter author name: ");
        authorName = scanner.nextLine();
    }

    // Method to show data for the book
    public void showData() {
        super.showData(); // Call Publisher's showData() method to display publisher details

        System.out.println("Book Name: " + bookName);
        System.out.println("Book ID: " + bookId);
        System.out.println("Author Name: " + authorName);
    }
}

public class BookPublisherDetails {
    public static void main(String[] args) {
        // Create an instance of Book
        Book book = new Book();

        // Get and show data for the book and publisher
        book.getData();
        System.out.println("\nDetails of the book and publisher:");
        book.showData();
    }
}
