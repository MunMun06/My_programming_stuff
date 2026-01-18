public class Fish extends Animal {
  @Override // help compiler check if you actually Override the method
  // misspelling the method names for example
  void move() {
    System.out.println("This animal is swimming");
  }
}
