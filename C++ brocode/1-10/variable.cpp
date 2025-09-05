#include <iostream>

int main() {

  int x;     // declare
  x = 2;     // assign
  int y = 8; // combine
  int sum = x + y;

  int z = 25;               // integer
  double price = 27.95;     // decimal
  char grade = 'a';         // 1 charater
  std::string name = "mun"; // sequence of text
  bool smart = false; // true or false. 1 or 0. bool == true is the same as bool

  std::cout << x << '\n';
  std::cout << sum << '\n';
  std::cout << "hello " << name << '\n';

  return 0;
}
