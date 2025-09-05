#include <iostream>

int main() {

  // new create heap memory
  // must delete the heap everytime after use
  // to prevent memory leak and undefined behavior

  char *pGrades = NULL;
  int size;

  std::cout << "How many grades to enter in?: ";
  std::cin >> size;

  pGrades = new char[size];

  for (int i = 0; i < size; i++) {
    std::cout << "Enter grade #" << i + 1 << ": ";
    std::cin >> pGrades[i];
  }

  for (int i = 0; i < size; i++) {
    std::cout << pGrades[i] << " ";
  }

  std::cout << '\n';

  delete[] pGrades;

  return 0;
}
