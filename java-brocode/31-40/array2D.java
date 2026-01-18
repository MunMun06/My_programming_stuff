public class array2D {
  public static void main(String[] args) {
    // 2D array = An array where each element is an array
    // Useful for storing a matrix of data

    String[][] groceries = { { "apple", "orange", "banana" },
        { "potato", "onion", "carrot" },
        { "chicken", "pork", "beef", "fish" } };
    // array in 2d array dont need to be the same size
    groceries[2][1] = "eggs"; // change "pork" to "eggs"

    for (String[] foods : groceries) {
      for (String food : foods) {
        System.out.print(food + " ");
      }
      System.out.println();

    }
    char[][] telephone = { { '1', '2', '3' },
        { '4', '5', '6' },
        { '7', '8', '9' },
        { '*', '0', '#' } };
    for (char[] row : telephone) {
      for (char number : row) {
        System.out.print(number + " ");
      }
      System.out.println();
    }
  }
}
