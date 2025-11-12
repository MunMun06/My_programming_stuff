#include <stdio.h>

float my_min(float a, float b) { return (a < b) ? a : b; }

float my_max(float a, float b) { return (a > b) ? a : b; }

int main() {

  int size, i, j, c = 0, max_index, min_index;
  float value[55], neg[55];

  scanf("%d", &size);

  for (i = 0; i < size; i++) {
    scanf("%f", &value[i]);
  }

  float min = 100;
  float max = -100;
  float sum = 0;

  for (i = 0; i < size; i++) {
    sum += value[i];
    min = my_min(min, value[i]);
    max = my_max(max, value[i]);

    if (value[i] < 0) {
      neg[c] = value[i];
      c++;
    }
  }

  for (i = 0; i < size; i++) {
    if (min == value[i]) {
      min_index = i;
    }
    if (max == value[i]) {
      max_index = i;
    }
  }

  float avg = sum / size;

  printf("Maximum value: %10.2f\n", max);
  printf("Minimum value: %10.2f\n", min);
  printf("Maximum index: %10d\n", max_index);
  printf("Minimum index: %10d\n", min_index);
  printf("Average: %10.2f\n", avg);
  printf("Reverse order: ");

  for (i = size - 1; i >= 0; i--) {
    printf("%.2f ", value[i]);
  }

  printf("\nAbove average list: ");
  for (i = 0; i < size; i++) {
    if (value[i] > avg) {
      printf("%.2f ", value[i]);
    }
  }

  printf("\nNegative coordinates: ");
  for (i = 0; i < c - 1; i++) {
    for (j = i + 1; j < c; j++) {
      printf("(%.2f, %.2f), ", neg[i], neg[j]);
    }
  }
  printf("\n");
  return 0;
}
