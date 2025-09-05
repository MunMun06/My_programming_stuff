#include <iostream>

int main() {

  // custom words and divisors

  long long n = 0;
  int first_divisor, second_divisor;
  std::string first_word, second_word;

  std::cout << "Enter divisor 1: \n";
  std::cin >> first_divisor;
  std::cout << "Enter word 1: \n";
  std::cin >> first_word;
  std::cout << "Enter divisor 2: \n";
  std::cin >> second_divisor;
  std::cout << "Enter word 2: \n";
  std::cin >> second_word;
  std::cout << "Enter the input number: \n";
  std::cin >> n;

  for (long long i = 1; i <= n; i++) {
    if (i % first_divisor == 0 && i % second_divisor == 0) {
      std::cout << first_word << second_word << '\n';
    } else if (i % first_divisor == 0) {
      std::cout << first_word << '\n';
    } else if (i % second_divisor == 0) {
      std::cout << second_word << '\n';
    } else {
      std::cout << i << '\n';
    }
  }

  return 0;
}
