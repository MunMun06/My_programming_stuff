import java.util.Scanner;

/**
 * lbs_to_kgs
 */
public class lbs_to_kgs {
  public static void main(String[] args) {
    Scanner scanner = new Scanner(System.in);

    double weight, convertedWeight;
    int choice;

    System.out.println("Weight conversion program");
    System.out.print("Enter your choice (1: lbs to kgs/ 2: kgs to lbs): ");
    choice = scanner.nextInt();

    if (choice == 1) {
      System.out.print("Enter your weight in lbs: ");
      weight = scanner.nextDouble();
      convertedWeight = weight / 2.2;
      System.out.printf("Your weight is %.2f kgs\n", convertedWeight);
    } else if (choice == 2) {
      System.out.print("Enter your weight in kgs: ");
      weight = scanner.nextDouble();
      convertedWeight = weight * 2.2;
      System.out.printf("Your weight is %.2f lbs\n", convertedWeight);
    } else {
      System.out.println("Invalid choice");
    }

    scanner.close();

  }
}
