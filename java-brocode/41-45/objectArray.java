public class objectArray {
  public static void main(String[] args) {

    Car[] cars = { new Car("Mustang", "Red"),
        new Car("Corvette", "Blue"),
        new Car("Charger", "Yellow") };

    for (Car car : cars) {
      car.color = "black";
    }

    for (Car car : cars) {
      car.drive();
    }
  }
}
