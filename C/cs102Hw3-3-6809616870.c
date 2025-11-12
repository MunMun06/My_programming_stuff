#include <stdio.h>

int main() {

  int N, input[8][8], i, j, sum, ans = 0, valid = 1;
  int used[65] = {0};

  scanf("%d", &N);

  for (i = 0; i < N; i++) {
    for (j = 0; j < N; j++) {
      scanf("%d", &input[i][j]);

      if (input[i][j] < 1 || input[i][j] > N * N)
        valid = 0;

      if (used[input[i][j]])
        valid = 0;
      used[input[i][j]] = 1;
    }
  }

  for (i = 0; i < N; i++) {
    sum = 0;
    for (j = 0; j < N; j++)
      sum += input[i][j];

    if (i == 0)
      ans = sum;
    else if (ans != sum)
      valid = 0;
  }

  for (i = 0; i < N; i++) {
    sum = 0;
    for (j = 0; j < N; j++)
      sum += input[j][i];

    if (ans != sum)
      valid = 0;
  }

  sum = 0;
  for (i = 0; i < N; i++)
    sum += input[i][i];
  if (ans != sum)
    valid = 0;

  sum = 0;
  for (i = 0; i < N; i++)
    sum += input[i][N - 1 - i];
  if (ans != sum)
    valid = 0;

  if (valid == 1)
    printf("This is a magic square!\n");
  else
    printf("This is NOT a magic square!\n");

  return 0;
}
