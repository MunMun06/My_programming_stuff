#include <stdio.h>

int main() {

  int input[100] = {0}, val[21] = {0}, i, n, max = 0, index;

  scanf("%d", &n);

  for (i = 0; i < n; i++) {
    scanf("%d", &input[i]);
    val[input[i]]++;
  }

  for (i = n; i > 0; i--) {
    if (max < val[i]) {
      max = val[i];
      index = i;
    }
  }

  printf("%d %d\n", index, max);

  return 0;
}
