import java.util.Scanner;

public class madlibs {
  public static void main(String[] args) {

    Scanner scanner = new Scanner(System.in);

    String adjective1, noun1, adjective2, verb1, adjective3;

    System.out.print("Enter an adjective: ");
    adjective1 = scanner.nextLine();
    System.out.print("Enter a noun (animal or person): ");
    noun1 = scanner.nextLine();
    System.out.print("Enter an adjective: ");
    adjective2 = scanner.nextLine();
    System.out.print("Enter a verb ending in -ing : ");
    verb1 = scanner.nextLine();
    System.out.print("Enter an adjective: ");
    adjective3 = scanner.nextLine();

    System.out.println("\nToday I went to a " + adjective1 + " zoo.");
    System.out.println("In an exhibit, I saw a " + noun1 + ".");
    System.out.println(noun1 + " was " + adjective2 + " and " + verb1 + "!");
    System.out.println("I was " + adjective3 + "!");

    scanner.close();
  }
}
