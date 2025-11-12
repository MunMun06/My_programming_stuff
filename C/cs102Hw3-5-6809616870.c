#include <stdio.h>

void readSquare(int arr[8][8], int N) {
  for (int i = 0; i < N; i++) {
    for (int j = 0; j < N; j++) {
      scanf("%d", &arr[i][j]);
    }
  }
}

int findMagicNumber(int arr[8][8], int N) {
  int target = 0;

  for (int j = 0; j < N; j++) {
    target += arr[0][j];
  }

  for (int i = 1; i < N; i++) {
    int sum = 0;
    for (int j = 0; j < N; j++)
      sum += arr[i][j];
    if (sum != target)
      return -1;
  }

  for (int j = 0; j < N; j++) {
    int sum = 0;
    for (int i = 0; i < N; i++)
      sum += arr[i][j];
    if (sum != target)
      return -1;
  }

  int diag1 = 0;
  for (int i = 0; i < N; i++)
    diag1 += arr[i][i];
  if (diag1 != target)
    return -1;

  int diag2 = 0;
  for (int i = 0; i < N; i++)
    diag2 += arr[i][N - i - 1];
  if (diag2 != target)
    return -1;

  return target;
}

int main() {

  int arr[8][8];
  int N;

  scanf("%d", &N);
  readSquare(arr, N);

  int magicNumber = findMagicNumber(arr, N);

  if (magicNumber == -1) {
    printf("Your square is NOT a magic square.\n");
  } else {
    printf("Your square is a magic square!! with the magic constant = %d.\n",
           magicNumber);
  }

  return 0;
}
