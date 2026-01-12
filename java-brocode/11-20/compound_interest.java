import java.util.Scanner;

public class compound_interest {
  public static void main(String[] args) {
    Scanner scanner = new Scanner(System.in);

    double principal, rate, amount;
    int timeCompounded, years;

    System.out.print("What is the principal: ");
    principal = scanner.nextDouble();
    System.out.print("What is the interest rate (in %): ");
    rate = scanner.nextDouble() / 100; // convert 5 to 0.05
    System.out.print("What is the # of times compounded per year: ");
    timeCompounded = scanner.nextInt();
    System.out.print("What is the # of years invested: ");
    years = scanner.nextInt();

    amount = principal * Math.pow(1 + rate / timeCompounded, timeCompounded * years);

    System.out.println("Your final total after invested for " + years + " years: " + amount);

    scanner.close();
  }
}
