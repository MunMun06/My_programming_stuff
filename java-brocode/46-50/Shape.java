public abstract class Shape {
  // Shape is an abstract class is you cant do
  // Shape shape = new Shape();

  abstract double area(); // ABSTRACT
                          // must be implement by its children

  void display() { // CONCRETE aka normal method
    System.out.println("This is a shape");
  }
}
