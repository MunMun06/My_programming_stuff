import java.util.Scanner;

/**
 * temperature
 */
public class temperature {
  public static void main(String[] args) {

    Scanner scanner = new Scanner(System.in);

    double Temperature, convertedTemperature;
    String unit;

    System.out.println("temperature converted program");
    System.out.println("C: F to C");
    System.out.println("F: C to F");
    System.out.print("Enter your choice: ");
    unit = scanner.next().toUpperCase();
    System.out.print("Enter your temperature: ");
    Temperature = scanner.nextDouble();

    convertedTemperature = (unit.equals("C")) ? (Temperature - 32) * 5 / 9 : (Temperature * 9 / 5) + 32;

    System.out.printf("%.2f %s\n", convertedTemperature, unit);

    scanner.close();

  }
}
