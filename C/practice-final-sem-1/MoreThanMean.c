#include <stdio.h>

int main() {

  int i, n, count = 0;
  float input[40] = {0}, avg = 0, sum = 0;

  scanf("%d", &n);

  for (i = 0; i < n; i++) {
    scanf("%f", &input[i]);
    sum += input[i];
  }

  avg = sum / n;

  for (i = 0; i < n; i++) {
    if (input[i] > avg)
      count++;
  }

  printf("%d\n", count);

  return 0;
}
