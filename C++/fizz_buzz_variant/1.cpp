#include <iostream>

int main() {

  // reverse FizzBuzz
  // 100 to 1

  long long n = 0;

  std::cout << "Enter the input number: \n";
  std::cin >> n;

  for (long long i = n; i >= 1; i--) {
    if (i % 3 == 0 && i % 5 == 0) {
      std::cout << "FizzBuzz\n";
    } else if (i % 3 == 0) {
      std::cout << "Fizz\n";
    } else if (i % 5 == 0) {
      std::cout << "Buzz\n";
    } else {
      std::cout << i << '\n';
    }
  }

  return 0;
}
