import java.util.Scanner;

/**
 * calculator
 */
public class calculator {
  public static void main(String[] args) {
    Scanner scanner = new Scanner(System.in);

    double num1, num2, result = 0;
    char operator;
    boolean validOperation = true;

    System.out.print("Enter the first number: ");
    num1 = scanner.nextDouble();
    System.out.print("Enter the operation (+ - * / ^): ");
    operator = scanner.next().charAt(0); // convert string to char
    System.out.print("Enter the second number: ");
    num2 = scanner.nextDouble();

    switch (operator) {
      case '+' -> result = num1 + num2;
      case '-' -> result = num1 - num2;
      case '*' -> result = num1 * num2;
      case '/' -> {
        if (num2 == 0) {
          System.out.println("divide by zero error! ");
          validOperation = false;
        } else {
          result = num1 / num2;
        }
      }
      case '^' -> result = Math.pow(num1, num2);

      default -> {
        System.out.println("That is not a valid operation! ");
        validOperation = false;
      }
    }

    if (validOperation) {
      System.out.printf("The result is: %.2f\n", result);
    }

    scanner.close();
  }
}
