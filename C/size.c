#include <stdio.h>

int main() {

  int a = 0, b = 0, c = 0, d = 0, e = 0;

  a = sizeof(int);
  b = sizeof(long);
  c = sizeof(long long);
  d = sizeof(float);
  e = sizeof(double);

  printf("int size is %d bytes\n", a);
  printf("long size is %d bytes\n", b);
  printf("long long size is %d bytes\n", c);
  printf("float size is %d bytes\n", d);
  printf("double size is %d bytes\n\n", e);

  short x = 320;
  char *whatptr;
  whatptr = (char *)&x;
  printf("64 in ascii is %c\n\n", *whatptr);

  short what[10] = {0}, *w = NULL;
  w = &what[0];

  printf("address of short[0] = %x\n", w);
  w++;
  printf("address of short[1] = %x\n", w);

  for (int i = 0; i < 10; i++) {
    what[i] = 1000 * i;
  }

  int *how = (int *)&what[0];

  printf("reading short[0] and [1] as int %d\n", *how);

  return 0;
}
