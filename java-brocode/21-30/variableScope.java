public class variableScope {
  static int x = 3; // class wide

  public static void main(String[] args) {
    // local are preferred over class wide variable
    int x = 1; // LOCAL
    System.out.println(x);
    doSomething();
  }

  static void doSomething() {
    int x = 2; // LOCAL
    System.out.println(x);
  }
}
