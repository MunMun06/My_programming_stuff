#define _GNU_SOURCE
#include "get_n_terms.h"
#include <math.h>

void get_n_terms(const unsigned long long *a, int N, int *pos) {
  int i = 0;
  double j = 0, result = 0, exact = M_PI - 3;

  for (i = 0; i < N; i++) {
    for (j = 0; j < a[i]; j++) {
      result += pow(-1.0, j) / (2.0 * j + 1.0);
    }
    result = (result * 4.0) - 3.0;

    double x = exact - floor(exact);
    double y = result - floor(result);
    int count = 0;
    while (1) {
      x *= 10.0;
      y *= 10.0;

      int dx = (int)floor(x);
      int dy = (int)floor(y);

      if (dx != dy)
        break;
      count++;

      x -= dx;
      y -= dy;
    }
    pos[i] = count;
    result = 0;
  }
}
