#include <iostream>

int main() {

  // parenthesis   multiplication    addition
  // same priority is left to right

  int money = 1000;
  int days = 28;
  money += 70;              // money = money + 70;
  days++;                   // days+=1; (increment operator)
  money -= 500;             // money = money - 500;
  days--;                   // days-=1; (decrement operator)
  money *= 10;              // money = money * 10;
  money /= 2;               // money = money / 2;
  int remainder = days % 5; //(modulo operator) find remainder

  std::cout << money << '\n';
  std::cout << remainder << '\n';

  // days = days + 1
  // days += 1
  // days++

  return 0;
}
