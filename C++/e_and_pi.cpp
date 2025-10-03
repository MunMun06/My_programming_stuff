#include <cmath>
#include <iostream>

unsigned long long factorial(int n) {
  if (n < 0) {
    return 1;
  }
  unsigned long long result = 1;
  for (int i = 1; i <= n; i++) {
    result *= i;
  }
  return result;
}

unsigned long long permutation(int n, int r) {
  if (n < 0) {
    return 0;
  }
  unsigned long long result = 1;
  for (int i = n; i > r; i--) {
    result *= i;
  }
  return result;
}

unsigned long long nth_term_pi_newtons(int n) {
  if (n == 1) {
    return 1;
  } else if (n == 2) {
    return 1 + n;
  }
}

long double nth_term_e(int n) {
  long double result = 0;
  for (int i = 0; i < n; i++) {
    result += 1.0 / (factorial(i));
  }
  return result;
}

int main() {

  int num_e;
  long double e;

  std::cout << "Please enter the amount of iteration for e: ";
  std::cin >> num_e;
  std::cout << '\n';

  std::cout.precision(15);

  e = nth_term_e(num_e);

  std::cout << e << '\n';

  return 0;
}
