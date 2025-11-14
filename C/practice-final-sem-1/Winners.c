#include <stdio.h>

int main() {

  int n, i, input[13], count = 0;

  scanf("%d", &n);

  for (i = 0; i < n; i++) {
    scanf("%d", &input[i]);
  }

  for (i = 0; i < n - 1; i++) {
    if (input[i] > input[n - 1]) {
      count++;
    }
  }
  if (count == 0) {
    count = 1;
  }
  printf("%d\n%d\n", input[n - 1], count);

  return 0;
}
