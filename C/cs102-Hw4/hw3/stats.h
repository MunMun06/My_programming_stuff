#ifndef STATS_H
#define STATS_H

struct statistics {
  int min;
  int max;
  int range;
  int mean;
  int median;
  int mode;
  int N;
};

void bubbleSort(int arr[], int N);
void stats(int *data, int N, struct statistics *stats);

#endif
