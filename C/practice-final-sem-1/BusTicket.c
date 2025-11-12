#include <stdio.h>

int add_digits(int a) {
  int i, ans = 0;
  for (i = 0; i < 6; i++) {
    ans += a % 10;
    a /= 10;
  }
  return ans;
}

int main() {

  int input, temp;

  scanf("%d", &input);

  do {
    temp = add_digits(input);
    input = add_digits(temp);
  } while (input > 9);

  printf("%d\n", input);

  return 0;
}
