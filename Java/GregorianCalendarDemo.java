import java.util.*;

public class GregorianCalendarDemo {
    public static void main(String[] args) {
        // Create a GregorianCalendar instance
        GregorianCalendar calendar = new GregorianCalendar();

        // Display current date and time in default locale and time zone
        Date currentDate = calendar.getTime();
        System.out.println("Current date and time: " + currentDate);

        // Get the current year
        int currentYear = calendar.get(Calendar.YEAR);

        // Check if the current year is a leap year
        boolean isLeapYear = calendar.isLeapYear(currentYear);

        // Display whether the current year is a leap year or not
        if (isLeapYear) {
            System.out.println(currentYear + " is a leap year.");
        } else {
            System.out.println(currentYear + " is not a leap year.");
        }
    }
}
