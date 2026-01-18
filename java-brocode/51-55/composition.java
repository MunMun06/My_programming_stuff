public class composition {
  public static void main(String[] args) {

    // Composition = Represents a "part-of" relationship between objects.
    // For example, an Engine is "part of" a Car.
    // Allows complex objects to be constructed from smaller objects.

    // unlike aggregration. where you create books then put them in library
    // composition create Car and Engine simualtenously
    Car2 car = new Car2("Corvette", 2025, "V8");

    System.out.println(car.model);
    System.out.println(car.year);
    System.out.println(car.engine.type);

    car.start();
  }
}
