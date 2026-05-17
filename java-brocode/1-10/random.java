import java.util.Random;

/**
 * random
 */
public class random {
  public static void main(String[] args) {
    Random random = new Random();

    int number;
    number = random.nextInt(); // generate a large int
                               // can generate double float boolean long byte exponential gaussian

    int dice, dice2;
    dice = random.nextInt(1, 7); // generate number from 1 - 6
                                 // [1,7). int so 1 - 6
    dice2 = random.nextInt(1,7);
    System.out.println(number);
    System.out.println(dice);
    System.out.println(dice2);
  }

}
