public class variable {
  public static void main() {
    // primitive = simple value stored directly in memory (stack)
    // int long short byte(number) float void double char boolean
    // reference = memory address (stack) that points to the heap
    // string array object

    int age = 21;
    System.out.println("The age is " + age);

    // sout~ to do System.out.println
    double temperature;
    temperature = 34.23;
    System.out.println("The temperature is " + temperature + " C");

    boolean isStudent = true; // true and false only, no 1 and 0
    if (isStudent) {
      System.out.println("You are a student");
    } else {
      System.out.println("You are not a student");
    }

    String name = "arch raphael";
    System.out.println("The name is " + name);
  }
}
