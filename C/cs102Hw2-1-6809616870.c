#include <stdio.h>

int main() {

  float mother_h, father_h, h_variance;
  printf("Enter the height of the mother (centimeres): ");
  scanf("%f", &mother_h);
  printf("Enter the height of the father (centimeres): ");
  scanf("%f", &father_h);

  h_variance = 13.5;
  float h_avg = (mother_h + father_h) / 2;
  float h_min = h_avg - h_variance;
  float h_max = h_avg + h_variance;

  printf("The possible height of the child is between %.2f to %.2f\n", h_min,
         h_max);

  return 0;
}
