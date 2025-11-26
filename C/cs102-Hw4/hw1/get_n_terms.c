#define _GNU_SOURCE
#include "get_n_terms.h"
#include <math.h>
#include <stdint.h>

void get_n_terms(const unsigned long long *a, int N, int *pos) {
  int i;
  unsigned long long j;

  const double exact_target = (M_PI - 3.0) * 10.0;

  for (i = 0; i < N; i++) {
    double guess_pi_over_four = 0.0;

    for (j = 0; j <= a[i]; j++) {
      double sign = (j % 2 == 0) ? 1.0 : -1.0;
      double denominator = 2.0 * (double)j + 1.0;
      guess_pi_over_four += sign / denominator;
    }

    double guess_target = (guess_pi_over_four * 4.0 - 3.0) * 10.0;

    int precision = 0;

    double curr_guess = guess_target;
    double curr_exact = exact_target;

    for (int k = 0; k < 8; k++) {
      if (floor(curr_exact) == floor(curr_guess)) {
        precision++;
        curr_exact = (curr_exact - floor(curr_exact)) * 10.0;
        curr_guess = (curr_guess - floor(curr_guess)) * 10.0;
      } else {
        break;
      }
    }
    pos[i] = precision;
  }
}
