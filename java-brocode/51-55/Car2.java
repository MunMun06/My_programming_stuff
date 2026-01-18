public class Car2 {

  String model;
  int year;
  Engine engine;

  Car2(String model, int year, String engineType) {
    this.model = model;
    this.year = year;
    this.engine = new Engine(engineType);
    // create Engine then put it in Car
  }

  void start() {
    this.engine.start();
    System.out.println("The " + this.model + " is running");
  }
}
