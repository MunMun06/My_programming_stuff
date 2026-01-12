import java.util.Scanner;

public class conditional {
  public static void main(String[] args) {
    Scanner scanner = new Scanner(System.in);

    System.out.print("Enter your name: ");
    String name = scanner.nextLine();

    if (name.isEmpty()) {
      System.out.println("You didn't enter your name!");
    }
    int age = 14;
    // ==

    if (age >= 60) {
      System.out.println("You are retired");
    } else if (age >= 18) {
      System.out.println("You are an adult");
    } else if (age >= 0) {
      System.out.println("You are a child");
    } else {
      System.out.println("You haven't been borned yet!");
    }

    scanner.close();
  }
}
