#include <stdio.h>

int main() {

  int i, n, k, t, input[1000] = {0}, ans, count = 0;

  scanf("%d %d %d", &n, &k, &t);

  for (i = 0; i < n; i++) {
    scanf("%d", &input[i]);
  }

  ans = n * k / 100;

  if ((n * k) % 100 != 0) {
    ans++;
  }

  for (i = 0; i < n; i++) {
    if (input[i] <= t)
      count++;
  }

  if (count >= ans) {
    printf("1\n");
  } else {
    printf("0\n");
  }
  count = n - count;
  printf("%d\n", count);

  return 0;
}
