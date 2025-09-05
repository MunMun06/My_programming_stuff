#include <iostream>

int main() {

  long long n = 0;

  std::cout << "Enter the input number: \n";
  std::cin >> n;

  for (int i = 1; i <= n; i++) {
    if (i % 3 == 0 && i % 5 == 0) {
      std::cout << "Fizz Buzz \n";
    } else if (i % 3 == 0) {
      std::cout << "Fizz \n";
    } else if (i % 5 == 0) {
      std::cout << "Buzz \n";
    } else {
      std::cout << i << '\n';
    }
  }

  return 0;
}
