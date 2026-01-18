public class wrapperClass {
  public static void main(String[] args) {

    // Wrapper classes = Allow primitive values (int, char, double, boolean)
    // to be used as objects. "Wrap them in an object"
    // Generally, don't wrap primitives unless you need an object.
    // Allows use of Collections Framework and static utility methods.

    // deprecated way
    // Integer a = new Integer(123);

    // Autoboxing
    // all of these a reference datatype now
    Integer a = 123;
    Double b = 3.14;
    Character c = '$';
    Boolean d = true;

    // Unboxing
    // changing a wrapper back to its primitive
    int x = a;

    String h = Integer.toString(123);
    String i = Double.toString(23.4);
    String j = Character.toString('^');
    String k = Boolean.toString(false);

    String y = h + i + j + k;

    System.out.println(y);

    // int a = Integer.parseInt("25");
    // double b = Double.parseDouble("34.653");
    // char c = "Pizza".charAt(0);
    // boolean d = Boolean.parseBoolean("true");
  }
}
