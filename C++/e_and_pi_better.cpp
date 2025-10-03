#include <cmath>
#include <iostream>
using namespace std;

// Factorial function
long double factorial(int n) {
  long double result = 1.0;
  for (int i = 1; i <= n; i++) {
    result *= i;
  }
  return result;
}

// Approximation of e using series expansion
long double compute_e(int iterations) {
  long double e = 0.0;
  for (int n = 0; n < iterations; n++) {
    e += 1.0 / factorial(n);
  }
  return e;
}

// Approximation of pi using Newton's formula
long double compute_pi(int iterations) {
  long double sum = 0.0;
  for (int n = 0; n < iterations; n++) {
    long double term = pow(-1, n) / ((2 * n + 1) * pow(3, n));
    sum += term;
  }
  return sqrt(12.0) * sum;
}

int main() {
  int e_iter, pi_iter;

  cout << "Enter number of iterations for e: ";
  cin >> e_iter;

  cout << "Enter number of iterations for pi: ";
  cin >> pi_iter;

  long double approx_e = compute_e(e_iter);
  long double approx_pi = compute_pi(pi_iter);

  cout.precision(15);
  cout << "Approximation of e with " << e_iter << " iterations: " << approx_e
       << endl;
  cout << "Approximation of pi with " << pi_iter << " iterations: " << approx_pi
       << endl;

  return 0;
}
