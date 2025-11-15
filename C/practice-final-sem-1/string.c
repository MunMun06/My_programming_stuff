#include <stdio.h>
#include <string.h>

int main() {

  char one[6], two[6], warcrime[11];
  int a, b;

  strcpy(one, "hello");
  strcpy(two, "world");

  a = strcmp(one, two);
  b = strcmp(two, one);

  printf("%d %d\n", a, b);

  strcpy(warcrime, one);
  strcat(warcrime, two);

  printf("%s\n", warcrime);

  return 0;
}
