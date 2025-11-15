#include <stdio.h>
#include <string.h>

int my_max(int a, int b) { return a * (a >= b) + b * (b > a); }

int hex(char a) {
  if (a >= '0' && a <= '9') {
    return ((int)a - 48);
  } else {
    return ((int)a - 55);
  }
}

int my_char(char a) { return ((int)a - 64); }

int main() {

  char input[1000] = {'_'};
  int i, j, n, max = 0, val[256] = {0}, sum[13] = {0}, month;

  scanf("%s", input);

  n = strlen(input);
  month = hex(input[0]);

  for (i = 0; i <= n; i += 2) {
    if (month == hex(input[i])) {
      val[my_char(input[i + 1])] = 1;
    } else {
      for (j = 1; j < 27; j++) {
        sum[month] += val[j];
        val[j] = 0;
      }
      month = hex(input[i]);
      val[my_char(input[i + 1])] = 1;
    }
  }

  for (i = 1; i < 13; i++) {
    max = my_max(max, sum[i]);
    printf("%d\n", sum[i]);
  }
  printf("%d\n", max);

  return 0;
}
