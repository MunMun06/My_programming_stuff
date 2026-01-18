import java.util.ArrayList;
import java.util.Collections;

public class arrayList {
  public static void main(String[] args) {
    // ArrayList = A resizeable array that stores objects (autoboxing)
    // Arrays are fixed in size, but ArrayLists can change

    // ITS VECTOR RIGHT?!!?!!?
    // but only for objects
    ArrayList<String> fruits = new ArrayList<>();
    // ArrayList<Integer> list = new ArrayList<>();

    fruits.add("Apple");
    fruits.add("Orange");
    fruits.add("Banana");
    fruits.add("Coconut");

    // fruits.remove(0);
    // fruits.set(0, "Pineapple");
    // fruits.add("dragon fruit")
    // fruits.get(2);
    // fruits.size();

    Collections.sort(fruits);

    for (String fruit : fruits) {
      System.out.println(fruit);
    }
    System.out.println(fruits);
  }
}
