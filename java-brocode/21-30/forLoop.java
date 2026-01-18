import java.util.Scanner;

public class forLoop {
  public static void main(String[] args) throws InterruptedException {
    // make thread pause execution when interrupted

    // for loop = execute some code a CERTAIN amount of times
    Scanner scanner = new Scanner(System.in);

    System.out.print("How many seconds to countdown from?: ");
    int start = scanner.nextInt();

    for (int i = start; i > 0; i--) {
      System.out.println(i);
      Thread.sleep(1000); // sleep for 1000 ms per iteration
    }
    System.out.println("HAPPY NEW YEAR!");
    scanner.close();
  }
}
