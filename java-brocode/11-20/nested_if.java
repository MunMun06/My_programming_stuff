public class nested_if {
  public static void main(String[] args) {
    boolean isSenior = true, isVeteran = false;
    double price = 14.99;

    if (isSenior) {
      if (isVeteran) {
        System.out.println("You get a veteran discount of 20%");
        System.out.println("You get a senior discount of 10%");
        price *= 0.7;
      } else {
        System.out.println("You get a senior discount of 10%");
        price *= 0.9;
      }
    } else {
      if (isVeteran) {
        System.out.println("You get a veteran discount of 20%");
        price *= 0.8;
      } else {
        System.out.println("Unfortunately, there are no discount for you");
      }

    }

    System.out.printf("The price is: $%.2f\n", price);

  }
}
