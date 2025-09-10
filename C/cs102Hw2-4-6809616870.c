#include <stdio.h>

int main() {

  int num1, num2, high, low;

  printf("Please enter two integers: ");
  scanf("%d %d", &num1, &num2);

  if (num1 < num2) {
    low = num1;
    high = num2;
  } else {
    low = num2;
    high = num1;
  }

  if (low % 13 == 0) {
    printf("%d\n", low);
  }

  while (low <= high) {
    low += 13 - (low % 13);
    if (low <= high) {
      printf("%d\n", low);
    }
  }
  printf("Bye!!\n");

  return 0;
}
