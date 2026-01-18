public class INTERFACES {
  public static void main(String[] args) {
    // Interface = A blueprint for a class that specifies a set of abstract methods
    // that implementing classes MUST define.
    // a class can implement multiple Interfaces.

    Rabbit rabbit = new Rabbit();
    Hawk hawk = new Hawk();
    Fish2 fish = new Fish2();

    rabbit.flee();
    hawk.hunt();
    fish.flee();
    fish.hunt();
  }
}
