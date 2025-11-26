#include "stats.h"
void swap(int *arr, int i, int j) {
  int temp = arr[i];
  arr[i] = arr[j];
  arr[j] = temp;
}
void bubbleSort(int arr[], int N) {
  int i, j;
  for (i = 0; i < N - 1; i++) {
    for (j = 0; j < N - i - 1; j++) {
      if (arr[j] > arr[j + 1])
        swap(arr, j, j + 1);
    }
  }
}
