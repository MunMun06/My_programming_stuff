import java.util.Scanner;

/**
 * scanner
 */
public class scanner { // class~
  public static void main(String[] args) { // main~
    // use scanner to get user input

    Scanner scanner = new Scanner(System.in);

    System.out.println("Enter your name "); // System.out.print to put the input in the same line as the prompt
    String name = scanner.nextLine(); // scanner.next to ignore any spaces

    System.out.print("Enter your age: ");
    int age = scanner.nextInt();

    System.out.print("What your GPA: ");
    double gpa = scanner.nextDouble();

    System.out.print("Are you a student (true/false): ");
    boolean isStudent = scanner.nextBoolean();

    System.out.print("69 - 2 = ");
    int sixseven = scanner.nextInt();
    scanner.nextLine(); // to consume the newline
    // if not food will be the newline

    System.out.print("Whats your favorite food : ");
    String food = scanner.nextLine();

    System.out.println("Your name is " + name);
    System.out.println("Your age is " + age + " years old");
    System.out.println("Your gpa is " + gpa);
    if (isStudent) {
      System.out.println("You are a student");
    } else {
      System.out.println("you are not a student");
    }
    System.out.println("69 - 2 = " + sixseven);
    System.out.println("your favorite food is " + food);
    scanner.close();
  }
}
