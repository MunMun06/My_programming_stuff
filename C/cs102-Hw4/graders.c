// #include "asquared.h"
#include <assert.h>
#include <stdio.h>

int main() {

  int a;
  assert(1 == scanf("%d", &a));
  fclose(stdin);

  int res = asquared(a);

  printf("%d", res);
  printf("\n");
  fclose(stdout);

  return 0;
}
