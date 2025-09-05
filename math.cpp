#include <iostream>

int main() {

  int dividend = 0;
  int divisor = 0;

  std::cout << "Find the remainder of: \n";
  std::cin >> dividend;
  std::cout << "Divided by: \n";
  std::cin >> divisor;
  std::cout << dividend % divisor << '\n';

  return 0;
}
