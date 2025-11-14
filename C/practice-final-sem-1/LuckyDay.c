#include <stdio.h>

int my_pow_four(int a) { return a * a * a * a; }

int lucky(int a, int b) {
  return (a * (my_pow_four((b / 10)) + my_pow_four((b % 10))));
}

int main() {

  int n, i, count = 0, day[20] = {0}, date[20] = {0}, temp1 = 0, temp2 = 0;

  scanf("%d", &n);

  for (i = 0; i < n; i++) {
    scanf("%d %d", &temp1, &temp2);
    if (lucky(temp1, temp2) % 10 == 4) {
      day[count] = temp1;
      date[count] = temp2;
      count++;
    }
  }

  printf("%d\n", count);

  for (i = 0; i < count; i++) {
    printf("%d %d\n", day[i], date[i]);
  }
  return 0;
}
