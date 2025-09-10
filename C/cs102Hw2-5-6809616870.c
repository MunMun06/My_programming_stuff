#include <stdio.h>

int main() {

  int input;

  printf("Please enter your ticket number <xxxxx>: ");
  scanf("%d", &input);

  int fifth_digit = input / 10000;
  int fourth_digit = (input / 1000) % 10;
  int third_digit = (input / 100) % 10;
  int second_digit = (input / 10) % 10;
  int first_digit = input % 10;

  int first =
      fifth_digit + fourth_digit + third_digit + second_digit + first_digit;

  int second_second_digit = first / 10;
  int second_first_digit = first % 10;

  int second = second_second_digit + second_first_digit;

  int third_second_digit = second / 10;
  int third_first_digit = second % 10;

  int third = third_second_digit + third_first_digit;

  printf("Your number is: %d\n", third);
  printf("Your prediction is: ");

  switch (third) {
  case 0:
    printf("Bad luck\n");
    break;
  case 1:
    printf("Good luck :)\n");
    break;
  case 2:
    printf("Will meet your soul-mate soon ^__^\n");
    break;
  case 3:
    printf("Should make merit\n");
    break;
  case 4:
    printf("Lucky in love\n");
    break;
  case 5:
    printf("Need more rest!\n");
    break;
  case 6:
    printf("Beware of an accident @__@\n");
    break;
  case 7:
    printf("Lucky in game\n");
    break;
  case 8:
    printf("looking good\n");
    break;
  case 9:
    printf("Will get some money soon.\n");
    break;
  }

  return 0;
}
