import java.util.Scanner;

/**
 * whileLoop
 */
public class whileLoop {
  public static void main(String[] args) {
    Scanner scanner = new Scanner(System.in);

    // while and do while loop works the same as C and C++

    String name = "";

    while (name.isEmpty()) {
      System.out.print("Enter your name: ");
      name = scanner.nextLine();
    }

    System.out.println("Your name is " + name);

    scanner.close();

  }
}
