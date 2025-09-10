#include <stdio.h>

int main() {

  int side1, side2, side3;

  printf("Please enter length of each side of your triangle: ");
  scanf("%d %d %d", &side1, &side2, &side3);

  if ((side1 <= 0) || (side2 <= 0) || (side3 <= 0) ||
      ((side1 + side2) <= side3) || ((side1 + side3) <= side2) ||
      ((side3 + side2) <= side1)) {
    printf("This is not a valid triangle!\n");
  } else if ((side1 == side2) && (side2 == side3)) {
    printf("This is an equilateral triangle.\n");
  } else if ((side1 == side2) || (side1 == side3) || (side2 == side3)) {
    printf("This is an isosceles triangle.\n");
  } else {
    printf("This is a scalene triangle.\n");
  }

  return 0;
}
