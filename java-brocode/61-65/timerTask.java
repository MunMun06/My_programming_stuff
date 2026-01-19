import java.util.Timer;
import java.util.TimerTask;

public class timerTask {
  public static void main(String[] args) {

    // Timer = Class that schedules tasks at specific times or periodically
    // Useful for: sending notifications, scheduled updates, repetitive actions

    // TimerTask = Represents the task that will be executed when the timer said so
    // You will extend the TimerTask class to define your task
    // Create a subclass of TimerTask and @Override run()

    Timer timer = new Timer();
    TimerTask task = new TimerTask() {
      int count = 10;

      @Override
      public void run() {
        System.out.println("Hello!");
        count--;
        if (count <= 0) {
          System.out.println("task completed");
          timer.cancel();
        }
      }
    };

    timer.schedule(task, 0, 1000); // (task, delay, period)
    // timer.schedule(task,0) so no repetition

  }
}
