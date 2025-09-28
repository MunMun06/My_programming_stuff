#include <stdio.h>

int main() {

  int a = 244545;
  int x, y;

  printf("normal:%d      this:%9d\n", a, a);
  printf("normal:%d      this:%-9d end\n", a, a);
  printf("normal:%+010d      this:%+9d\n", a, a);

  printf("Please input the number a and b <a b>: ");
  scanf("%d %d", &x, &y);

  printf("x is:%d y is:%d\n", x, y);

  return 0;
}
