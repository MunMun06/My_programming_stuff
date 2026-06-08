#include <iostream>

int squareSides = 4;

void checkInput(){
  int first = 0, current = 0;
  bool isValid = true;

  std::cin >> first;

  for (int i = 0; i < squareSides - 1; ++i){
    std::cin >> current;
    if (first != current){
      isValid = false;
    }
  }

  if (isValid) {
    std::cout << "YES\n";
  }
  else {
    std::cout << "NO\n";
  }
}

int main (){
  int testNum;
  std::cin >> testNum;

  for (int i = 0; i < testNum; ++i){
    checkInput();
  } 

  return 0;
}

