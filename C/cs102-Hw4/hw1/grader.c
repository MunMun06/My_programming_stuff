#include "get_n_terms.h"
#include <stdio.h>

int main() {

  unsigned long long int a[10];
  int pos[10];

  int N;
  scanf("%d", &N);

  int i;
  for (i = 0; i < N; ++i)
    scanf("%lld", &a[i]);

  // fclose(stdin);

  get_n_terms(a, N, pos);

  for (i = 0; i < N; ++i) {
    if (i > 0)
      printf(" ");
    printf("%d", pos[i]);
  }

  printf("\n");
  // fclose(stdout);

  return 0;
}
