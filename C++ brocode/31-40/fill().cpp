#include <iostream>

int main() {

  // fill() will fills a range of element with a specified value
  // fill(begin, end, value)

  const int SIZE = 99;
  std::string foods[SIZE];

  fill(foods, foods + (SIZE / 3), "pizza");
  fill(foods + (SIZE / 3), foods + (SIZE / 3) * 2, "hamburger");
  fill(foods + (SIZE / 3) * 2, foods + SIZE, "hotdog");

  // 14 i=1 j=3

  for (int i = 0; i < 9; i++) {
    for (int j = 0; j < 11; j++) {
      std::cout << foods[(i * 11) + j] << " ";
    }
    std::cout << '\n';
  }

  return 0;
}
