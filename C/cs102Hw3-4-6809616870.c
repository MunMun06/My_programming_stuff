#include <stdio.h>

float min_value(float *arr, int size) {
  float m = *arr;
  for (int i = 1; i < size; i++) {
    float x = *(arr + i);
    if (x < m) {
      m = x;
    }
  }
  return m;
}

float max_value(float *arr, int size) {
  float m = *arr;
  for (int i = 1; i < size; i++) {
    float x = *(arr + i);
    if (x > m) {
      m = x;
    }
  }
  return m;
}

int main() {

  int size, i, j, c = 0, max_index = 0, min_index = 0;
  float value[55], neg[55];

  scanf("%d", &size);

  for (i = 0; i < size; i++) {
    scanf("%f", (value + i));
  }

  float min = min_value(value, size);
  float max = max_value(value, size);

  float sum = 0;

  for (i = 0; i < size; i++) {
    float x = *(value + i);
    sum += x;

    if (x < 0) {
      *(neg + c) = x;
      c++;
    }
  }

  for (i = 0; i < size; i++) {
    if (*(value + i) == min)
      min_index = i;
    if (*(value + i) == max)
      max_index = i;
  }

  float avg = sum / size;

  printf("Maximum value: %10.2f\n", max);
  printf("Minimum value: %10.2f\n", min);
  printf("Maximum index: %10d\n", max_index);
  printf("Minimum index: %10d\n", min_index);
  printf("Average: %10.2f\n", avg);

  printf("Reverse order: ");
  for (i = size - 1; i >= 0; i--) {
    printf("%.2f ", *(value + i));
  }

  printf("\nAbove average list: ");
  for (i = 0; i < size; i++) {
    if (*(value + i) > avg) {
      printf("%.2f ", *(value + i));
    }
  }

  printf("\nNegative coordinates: ");
  for (i = 0; i < c - 1; i++) {
    for (j = i + 1; j < c; j++) {
      printf("(%.2f, %.2f), ", *(neg + i), *(neg + j));
    }
  }

  printf("\n");
  return 0;
}
