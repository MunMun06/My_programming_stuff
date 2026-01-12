import java.util.Scanner;

public class shop {
  public static void main(String[] args) {

    Scanner scanner = new Scanner(System.in);

    String item;
    double price;
    int quatity;
    char currency = '$';
    double total;

    System.out.print("What item do you want to buy: ");
    item = scanner.nextLine();
    System.out.print("What is the price for each: ");
    price = scanner.nextDouble();
    System.out.print("How many do you want to buy: ");
    quatity = scanner.nextInt();

    total = quatity * price;
    System.out.println("\nYou have bought " + quatity + " " + item + "/s");
    System.out.println("Your total is: " + currency + total);

    scanner.close();
  }
}
