/**
 * printf
 */
public class printf {
  public static void main(String[] args) {
    // litearlly printf from c
    // %(flags)(width)(.precision)(datatype)
    // s string c char d int (decimal) f float and double b boolean

    String name = "spongebob";
    int age = 34;

    System.out.printf("%s is %d years old\n", name, age);

    double price1 = 9400000.23;
    double price2 = -3240000.546;
    double price3 = -3245000.6274;
    double price4 = 234300.245;
    // , comma every 3 digits
    // + show + and -
    // ( negative are in ()
    // space any postive number have a preceding space
    // - left aligned
    // 0 for zero padding

    System.out.printf("%+,.3f\n", price1); // normal behaviour for printf is 6 decimal points
    System.out.printf("%+,14.2f here \n", price2);
    System.out.printf("%-,(18.4f here\n", price3);
    System.out.printf("% ,12.4f here\n", price4);
    // System.out.printf();

  }

}
