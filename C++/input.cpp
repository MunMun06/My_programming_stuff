#include <iostream>

int main() {

  std::string name;

  std::cout << "What is your name? \n";
  std::cin >> name;

  std::cout << "Hello and welcome " << name
            << " to the club of real programmer\n";

  return 0;
}
