#include <algorithm>
#include <ctime>
#include <iostream>
#include <random>
#include <vector>

std::string getRandomChars(const std::string &charset, int length,
                           std::mt19937 &rng) {
  std::string result;
  std::uniform_int_distribution<> dist(0, charset.size() - 1);
  for (int i = 0; i < length; ++i) {
    result += charset[dist(rng)];
  }
  return result;
}

int main() {
  int n;
  std::cout << "Enter a number (multiple of 4): ";
  std::cin >> n;

  if (n <= 0 || n % 4 != 0) {
    std::cerr << "Input must be a positive multiple of 4.\n";
    return 1;
  }

  int sectionLength = n / 4;

  std::string lowercase = "abcdefghijklmnopqrstuvwxyz";
  std::string uppercase = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
  std::string digits = "0123456789";
  std::string symbols = "!@#$%^&*()-_=+[]{}|;:',.<>?/`~";

  std::random_device rd;
  std::mt19937 rng(rd());

  std::vector<std::string> sections = {
      getRandomChars(lowercase, sectionLength, rng),
      getRandomChars(uppercase, sectionLength, rng),
      getRandomChars(digits, sectionLength, rng),
      getRandomChars(symbols, sectionLength, rng)};

  std::shuffle(sections.begin(), sections.end(), rng);

  std::string finalResult;
  for (const auto &part : sections) {
    finalResult += part;
  }

  std::cout << "Generated string: " << finalResult << "\n";

  return 0;
}
