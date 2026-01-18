import java.util.Arrays;

public class array {
  public static void main(String[] args) {
    // array = a collection of values of the same data type
    // array is a refernece data type
    String[] fruits = { "apple", "orange", "banana", "coconut" };
    fruits[0] = "pineapple";
    int numOfFruits = fruits.length; // built in function for array length
    Arrays.sort(fruits); // sort alphabetically
    Arrays.fill(fruits, "pineapple");

    for (String fruit : fruits) { // for each loop
      System.out.println(fruit);
    }
    System.out.println(numOfFruits);
  }
}
