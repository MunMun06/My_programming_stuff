#include <stdio.h>

int main() {
  int n;
  printf("Enter a number: ");
  scanf("%d", &n);

  // 1. Left-aligned upright
  for (int i = 1; i <= n; i++) {
    for (int j = 0; j < i; j++)
      printf("@");
    printf("\n");
  }
  printf("\n");

  // 2. Left-aligned inverted
  for (int i = n; i >= 1; i--) {
    for (int j = 0; j < i; j++)
      printf("@");
    printf("\n");
  }
  printf("\n");

  // 3. Right-aligned upright
  for (int i = 1; i <= n; i++) {
    for (int j = 0; j < n - i; j++)
      printf(" ");
    for (int j = 0; j < i; j++)
      printf("@");
    printf("\n");
  }
  printf("\n");

  // 4. Right-aligned inverted
  for (int i = n; i >= 1; i--) {
    for (int j = 0; j < n - i; j++)
      printf(" ");
    for (int j = 0; j < i; j++)
      printf("@");
    printf("\n");
  }

  return 0;
}
