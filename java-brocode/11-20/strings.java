/**
 * strings
 */
public class strings {
  public static void main(String[] args) {
    String name = "     dell is unironically making a comeback   ";

    int length = name.length();
    char letter = name.charAt(0); // char at index 0
    int index = name.indexOf("i"); // find the first occurance of "i"
    int lastIndex = name.lastIndexOf("i"); // find the last occurance of "i"

    String upperName = name.toUpperCase(); // turn all letters into uppercase
    String trimedName = name.trim(); // remove all white space before and after the string

    trimedName = trimedName.replace("a", "e"); // replace all a with e

    if (name.isEmpty()) {
      System.out.println("You didn't entered your name!");
    }

    if (name.contains("x")) {
      System.out.println("Your name contains x");
    }

    if (name.equals(trimedName)) { // equals is case sensitve, equalIgnoreCase to yk
      System.out.println("Your name doesn't have white space infront and behind");
    }

  }

}
