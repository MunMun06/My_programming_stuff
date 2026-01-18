public class methodOverriding {
  public static void main(String[] args) {
    // Method overriding = When a subclass provides its own
    // implementation of a method that is already defined.
    // Allows for code reusability and gives specific implementations.

    // isnt this polymorphism?
    Dog dog = new Dog();
    Cat cat = new Cat();
    Fish fish = new Fish();

    dog.move();
    cat.move();
    fish.move();
  }
}
