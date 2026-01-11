import java.util.Scanner;

/**
 * scanner
 */
public class scanner {
  public static void main(String[] args) {
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

    System.out.println("Your name is " + name);
    System.out.println("Your age is " + age + " years old");
    System.out.println("Your gpa is " + gpa);
    if (isStudent) {
      System.out.println("You are a student");
    } else {
      System.out.println("you are not a student");
    }
    scanner.close();
  }
}
