#include <stdio.h>

int main() {

  int m, n, trash, i, input, choice, sum[11], ans = 0, index;

  scanf("%d %d", &m, &n);

  for (i = 0; i < m * n; i++) {
    scanf("%d %d %d", &trash, &choice, &input);
    sum[choice] += input;
  }
  for (i = 1; i <= n; i++) {
    if (sum[i] > ans) {
      ans = sum[i];
      index = i;
    }
  }
  printf("%d\n%d\n", index, ans);

  return 0;
}
