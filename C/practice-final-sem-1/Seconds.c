#include <stdio.h>

void solve_time(int x) {
  int a, b, c;

  a = x / 3600;
  b = (x % 3600) / 60;
  c = (x % 3600) % 60;
  printf("%d %d %d\n", a, b, c);
}

int main() {

  int i, n, input[20] = {0};

  scanf("%d", &n);

  for (i = 0; i < n; i++) {
    scanf("%d", &input[i]);
  }

  for (i = 0; i < n; i++) {
    solve_time(input[i]);
  }

  return 0;
}
