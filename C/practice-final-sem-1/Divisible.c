#include <stdio.h>

int main() {

  int a, b, d, i, count = 0;

  scanf("%d %d %d", &a, &b, &d);

  i = d;

  while (i < a) {
    i += d;
  }

  while (i >= a && i <= b) {
    count++;
    i += d;
  }

  printf("%d\n", count);

  return 0;
}
