public class polymorphism {
  public static void main(String[] args) {

    // Polymorphism = "POLY-" = "MANY"
    // "-MORPH" = "SHAPE"
    // Objects can identify as other objects in a superclass.
    // Objects can be treated as objects of a common superclass.

    Car2 car = new Car2();
    Bike bike = new Bike();
    Boat boat = new Boat();

    Vehicle[] vehicles = { car, bike, boat };

    for (Vehicle vehicle : vehicles) {
      vehicle.go();
    }
  }
}
