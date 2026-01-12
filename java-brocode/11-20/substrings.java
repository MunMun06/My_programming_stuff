/**
 * substrings
 */
public class substrings {
  public static void main(String[] args) {
    String email = "arch.raphael.06@gmail.com";
    String username = email.substring(0, 15); // get the string from index 0 to 14
    String domain = email.substring(16, 25); // get the string from index 16 to 24
                                             // the string is dont have index 25
                                             // email.substrings(16) also works
                                             // if we want 16 to the end

    String email2 = "dell.comeback@gmail.com";
    String username2 = email2.substring(0, email2.indexOf("@"));
    String domain2 = email2.substring(email2.indexOf("@") + 1);

    System.out.println(username);
    System.out.println(domain);
    System.out.println(username2);
    System.out.println(domain2);

  }

}
