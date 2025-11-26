#include "stats.h"
#include <stdio.h>

int main() {

  int a[1000];
  struct statistics s = {0, 0, 0, 0, 0, 0, 0};

  int N;
  scanf("%d", &N);

  int i;
  for (i = 0; i < N; ++i)
    scanf("%d", &a[i]);

  fclose(stdin);

  stats(a, N, &s);

  printf("%d %d %d %d %d %d %d", s.min, s.max, s.range, s.mean, s.median,
         s.mode, s.N);

  printf("\n");
  fclose(stdout);

  return 0;
}
