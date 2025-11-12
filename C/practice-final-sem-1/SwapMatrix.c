#include <stdio.h>

int my_max(int a, int b) { return a * (a > b) + b * (b > a); }

int main() {

  int input[4][5], i, j, a, b, c, d, max;

  for (i = 0; i < 4; i++) {
    for (j = 0; j < 5; j++) {
      scanf("%d", &input[i][j]);
    }
  }

  scanf("%d %d", &a, &b);
  scanf("%d %d", &c, &d);

  i = input[a][b];
  input[a][b] = input[c][d];
  input[c][d] = i;

  for (i = 0; i < 4; i++) {
    for (j = 0; j < 5; j++) {
      max = my_max(max, input[i][j]);
    }
    printf("%d ", max);
    max = 0;
  }

  printf("\n");

  return 0;
}
