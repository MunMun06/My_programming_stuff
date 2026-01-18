import java.util.Scanner;

public class arraySearch {
  public static void main(String[] args) {
    Scanner scanner = new Scanner(System.in);

    String[] fruits = { "apple", "orange", "banana" };
    boolean isFound = false;
    String target;

    System.out.print("Enter a fruit to search for: ");
    target = scanner.nextLine();

    for (int i = 0; i < fruits.length; i++) {
      if (fruits[i].equals(target)) { // string are reference datatype
        System.out.println("Element found at index: " + i);
        isFound = true;
        break;
      }
    }
    if (!isFound) {
      System.out.println("Element not found in the array");
    }
    scanner.close();
  }
}
