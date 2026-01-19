import java.util.Scanner;

public class ENUM {
  public static void main(String[] args) {

    // Enums = (Enumerations) A special kind of class that
    // represents a fixed set of constants.
    // They improve code readability and reliability.
    // More efficient with switches than comparing Strings.

    Scanner scanner = new Scanner(System.in);
    System.out.print("Enter a day of the week: ");
    String response = scanner.nextLine().toUpperCase();

    // Day day = Day.SUNDAY;
    // day is SUNDAY
    // day.getDayNumber(); is 1

    try {
      Day day = Day.valueOf(response); // SUNDAY

      switch (day) {
        case MONDAY,
            TUESDAY,
            WEDNESDAY,
            THURSDAY,
            FRIDAY ->
          System.out.println("It is a weekday");
        case SATURDAY, SUNDAY -> System.out.println("It is the weekend");
      }
    } catch (IllegalArgumentException e) {
      System.out.println("Please enter a valid day");
    }

    scanner.close();
  }
}
