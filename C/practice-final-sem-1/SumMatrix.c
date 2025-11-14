#include <stdio.h>

int main() {

  int i, j, input[4][4], a, b, sum = 0;

  for (i = 0; i < 4; i++) {
    for (j = 0; j < 4; j++) {
      scanf("%d", &input[i][j]);
    }
  }

  scanf("%d %d", &a, &b);

  for (i = 0; i < 4; i++) {
    sum += input[a][i] + input[i][b];
  }

  printf("%d\n", sum);

  return 0;
}
