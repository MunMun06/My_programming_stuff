#include <cmath>
#include <iostream>

int main() {

  // switch is an alternative to many "else if"
  // it compare one value against a case

  int year;
  std::cout << "Enter a year (Christian year): ";
  std::cin >> year;
  int ChineseYear = abs(year) % 12;

  switch (ChineseYear) {
  case 0:
    std::cout << "It's the year of the monkey";
    break;
  case 1:
    std::cout << "It's the year of the rooster";
    break;
  case 2:
    std::cout << "It's the year of the dog";
    break;
  case 3:
    std::cout << "It's the year of the pig";
    break;
  case 4:
    std::cout << "It's the year of the rat";
    break;
  case 5:
    std::cout << "It's the year of the ox";
    break;
  case 6:
    std::cout << "It's the year of the tiger";
    break;
  case 7:
    std::cout << "It's the year of the rabbit";
    break;
  case 8:
    std::cout << "It's the year of the dragon";
    break;
  case 9:
    std::cout << "It's the year of the snake";
    break;
  case 10:
    std::cout << "It's the year of the horse";
    break;
  case 11:
    std::cout << "It's the year of the goat";
    break;
  }
  // default:
  //  code
  // use when there are no matching case

  return 0;
}
