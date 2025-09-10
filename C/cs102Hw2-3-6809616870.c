#include <stdio.h>

int main() {

  int input;

  printf("Please enter the time in seconds: ");
  scanf("%d", &input);

  if (input < 0) {
    printf("Invalid Input !!\n");
  } else {
    int hour = input / 3600;
    int hour_r = input % 3600;
    int minute = hour_r / 60;
    int second = hour_r % 60;
    printf("The time is %d hours(s), %d minute(s), and %d seconds(s)\n", hour,
           minute, second);
  }

  return 0;
}
