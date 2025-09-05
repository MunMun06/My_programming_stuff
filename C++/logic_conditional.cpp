#include <iostream>

int main() {

  // bool x = 0 is true
  // bool y = 100 is false
  // bool z = 15.12 is false
  // logic operator are && || ! apply to the least signifigant bit
  // bitwise operator are & | ~ apply to every bit
  // 0000000 0 bool is false everything else is true
  // 1111111 0 bool is true but the least signifigant bit is 0
  // so it is best to only use logic operator for evaluating condition

  bool a = 1;
  bool b = 0;
  bool c = 1;

  bool *pA = &a;
  bool *pB = &b;
  bool *pC = &c;

  std::cout << "A is equal to " << *pA << '\n';
  std::cout << "B is equal to " << *pB << '\n';
  std::cout << "C is equal to " << *pC << '\n';

  // let test to see which is which for logic operator

  // *pA = ~a;
  // *pB = ~b;

  std::cout << "A after getting bitwise not " << ~a << '\n';
  std::cout << "B after getting bitwise not " << ~b << '\n';
  std::cout << "A after getting bitwise not " << (short)a << '\n';
  std::cout << "B after getting bitwise not " << (short)b << '\n';

  return 0;
}
