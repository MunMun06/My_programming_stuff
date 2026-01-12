/**
 * switches
 */
public class switches {
  public static void main(String[] args) {
    // enhanced switch is java14 feature
    //
    // in java its
    // switch(){
    // case "" -> {code block};
    // }

    String day = "saturday";

    switch (day) {
      case "monday":
        ;
      case "tuesday":
        ;
      case "wednesday":
        ;
      case "thursday":
        ;
      case "friday":
        System.out.println("thats a weekday");
        break;
      case "saturday":
        ;
      case "sunday":
        System.out.println("thats a weekend");
        break;

      default:
        System.out.println(day + " is not a day");
        break;
    }
    switch (day) {
      case "monday", "tuesday", "wednesday", "thursday", "friday" -> System.out.println("thats a weekday");
      case "saturday", "sunday" -> System.out.println("thats a weekend");
      default -> System.out.println(day + " is not a day");
    }
  }
}
