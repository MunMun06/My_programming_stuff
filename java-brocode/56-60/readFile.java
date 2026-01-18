import java.io.BufferedReader;
import java.io.FileNotFoundException;
import java.io.FileReader;
import java.io.IOException;

public class readFile {
  public static void main(String[] args) {

    // How to read a file using Java (3 popular options)

    // BufferedReader + FileReader: Best for reading text files line-by-line
    // FileInputStream: Best for binary files (e.g., images, audio files)
    // RandomAccessFile: Best for read/write specific portions of a large file

    String filePath = "/home/munmun06/My_programming_stuff/java-brocode/56-60/test.txt";
    // it didnt accept relative path

    try (BufferedReader reader = new BufferedReader(new FileReader(filePath))) {

      String line; // receive each line from the file
      while ((line = reader.readLine()) != null) {
        System.out.println(line);
      }
    } catch (FileNotFoundException e) {
      System.out.println("Could not locate file");
    } catch (IOException e) {
      System.out.println("IO error");
    } catch (Exception e) {
      System.out.println("Something went wrong");
    }
  }
}
