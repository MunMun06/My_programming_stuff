#include <stdio.h>

int my_max(int a, int b) { return a * (a > b) + b * (b > a); }

int main() {

  int input[100] = {0}, n, i, prev = 0, next = 5, max = -101, curr = 0;

  scanf("%d", &n);

  for (i = 0; i < n; i++) {
    scanf("%d", &input[i]);
  }

  for (i = 0; i < 5; i++) {
    curr += input[i];
  }

  max = my_max(max, curr);

  for (i = 0; i < n - 4; i++) {
    curr = curr - input[prev] + input[next];
    max = my_max(max, curr);
    prev++;
    next++;
  }

  printf("%d\n", max);

  return 0;
}
