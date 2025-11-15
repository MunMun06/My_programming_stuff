#include <stdio.h>

int my_max(int a, int b) { return a * (a >= b) + b * (b > a); }

int main() {

  int input[100][100], i, j, n, max = -100000, sum1 = 0, sum2 = 0;

  scanf("%d", &n);

  for (i = 0; i < n; i++) {
    for (j = 0; j < n; j++) {
      scanf("%d", &input[i][j]);
    }
  }

  for (i = 0; i < n; i++) {
    sum1 += input[i][i];
    sum2 += input[n - i - 1][i];
  }

  max = my_max(sum1, sum2);
  sum1 = 0;
  sum2 = 0;

  if (n % 2 == 0) {
    for (i = 1; i < n - 1; i += 2) {
      for (j = 0; j < n; j++) {
        sum1 += (input[i][j] + input[i + 1][j]) / 2;
        sum2 += (input[j][i] + input[j][i + 1]) / 2;
      }
    }
  } else {
    for (i = 1; i < n - 1; i++) {
      for (j = 0; j < n; j++) {
        sum1 += input[i][j];
        sum2 += input[j][i];
      }
    }
  }

  sum1 = my_max(sum1, sum2);
  max = my_max(max, sum1);

  printf("%d\n", max);

  return 0;
}
