/**
 * logicalOperator
 */
public class logicalOperator {
  public static void main(String[] args) {
    // logical AND OR NOT. && || !

    double temp = 20;
    boolean isSunny = true;

    if (temp <= 30 && temp >= 0) {
      System.out.println("The weather is GOOD ");
    } else if (!isSunny) {
      System.out.println("It is not sunny");
    }
  }
}
