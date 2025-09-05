#include <algorithm>
#include <fstream>
#include <iostream>
#include <string>
#include <vector>

// A simple BigInt struct to represent large numbers using base-10 storage
struct BigInt {
  std::vector<int> digits; // Least-significant digit first

  BigInt(int value = 0) {
    while (value > 0) {
      digits.push_back(value % 10);
      value /= 10;
    }
    if (digits.empty())
      digits.push_back(0);
  }

  // Multiply by 2
  void multiplyByTwo() {
    int carry = 0;
    for (int &d : digits) {
      int product = d * 2 + carry;
      d = product % 10;
      carry = product / 10;
    }
    while (carry) {
      digits.push_back(carry % 10);
      carry /= 10;
    }
  }

  // Convert to string
  std::string toString() const {
    std::string result;
    for (auto it = digits.rbegin(); it != digits.rend(); ++it)
      result += std::to_string(*it);
    return result;
  }
};

int main() {
  std::ofstream file("powers_of_two.txt");
  if (!file.is_open()) {
    std::cerr << "Failed to open output file.\n";
    return 1;
  }

  BigInt value(2); // Start from 2^1
  for (int exp = 1; exp <= 128; ++exp) {
    file << "2^" << exp << " = " << value.toString() << '\n';
    value.multiplyByTwo(); // Next power of 2
  }

  file.close();
  std::cout << "Powers of two written to powers_of_two.txt\n";
  return 0;
}
