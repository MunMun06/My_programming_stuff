#include <stdio.h>

int main() {

  int num;
  int j = 1;
  int k = 1;

  printf("Please enter the range of number from 1 to n: ");
  scanf("%d", &num);

  for (int i = 1; i <= num; i++) {
    printf("%d\n", i);
  }
  while (j <= num) {
    printf("%d\n", j);
    j++;
  }
  do {
    printf("%d\n", k);
    k++;
  } while (k <= num);

  return 0;
}
