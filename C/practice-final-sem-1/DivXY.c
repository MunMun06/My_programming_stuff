#include <stdio.h>

int main() {

  int x, y, i, count;

  scanf("%d %d", &x, &y);

  for (i = x; i <= y; i++) {
    if (y % i == 0)
      count++;
  }

  printf("%d\n", count);

  return 0;
}
