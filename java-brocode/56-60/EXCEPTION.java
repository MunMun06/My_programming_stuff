import java.util.InputMismatchException;
import java.util.Scanner;

public class EXCEPTION {
  public static void main(String[] args) {

    // Exception = An event that interrupts the normal flow of a program
    // (Dividing by zero, file not found, mismatch input type)
    // Surround any dangerous code with a try{} block
    // try{}, catch{}, finally{}

    Scanner scanner = new Scanner(System.in);

    try { // do this code block until exception happen then go to exception handling
      System.out.print("Enter a number: ");
      int number = scanner.nextInt();
      System.out.println(number);
    } catch (InputMismatchException e) {
      System.out.println("That wasn't a number!");
    } catch (ArithmeticException e) {
      System.out.println("YOU CAN'T DIVIDE BY ZERO!");
    } catch (Exception e) { // catch all exception
      // SAFETY NET
      System.out.println("Something went wrong");
    } finally { // always do this code block
      System.out.println("This always executes");
      scanner.close();
    }

    // or try (Scanner scanner = new Scanner(System.in)) { ... }
    // this way java close the resources for you

    // System.out.println(1 / 0);
    // exception we got. ArithmeticException
    // int number = scanner.nextInt();
    // when input is not int. InputMismatchException
  }
}
