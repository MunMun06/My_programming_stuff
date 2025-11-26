#include "stats.h"

void stats(int *data, int N, struct statistics *stats) {
  int i = 0, mode = 0, sum = 0, max = 1;
  bubbleSort(data, N);

  stats->N = N;
  stats->min = data[0];
  stats->max = data[N - 1];
  stats->range = stats->max - stats->min;

  int count[1001] = {0};

  for (i = 0; i < N; i++) {
    count[data[i]]++;
    sum += data[i];
  }
  stats->mean = sum / N;

  if (N % 2 == 0) {
    stats->median = data[(N / 2) - 1];
  } else {
    stats->median = data[N / 2];
  }

  for (i = 0; i < 1001; i++) {
    if (count[i] > max) {
      mode = i;
      max = count[i];
    }
  }

  stats->mode = mode;
}
