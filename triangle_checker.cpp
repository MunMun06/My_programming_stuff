#include <iostream>

int main() {

  int side1, side2, side3;

  std::cout << "Please enter the lenght of the first side of the triangle: ";
  std::cin >> side1;
  std::cout << "Please enter the lenght of the second side of the triangle: ";
  std::cin >> side2;
  std::cout << "Please enter the lenght of the third side of the triangle: ";
  std::cin >> side3;

  if ((side1 <= 0) || (side2 <= 0) || (side3 <= 0) ||
      ((side1 + side2) <= side3) || ((side1 + side3) <= side2) ||
      ((side3 + side2) <= side1)) {
    std::cout << "This is not a valid triangle!\n";
  } else if ((side1 == side2) && (side2 == side3)) {
    std::cout << "This is an equilateral triangle.\n";
  } else if ((side1 == side2) || (side1 == side3) || (side2 == side3)) {
    std::cout << "This is an isosceles triangle.\n";
  } else {
    std::cout << "This is a scalene triangle.\n";
  }

  return 0;
}
