#include <cmath>
#include <iostream>

// think of array as fixed sized continuous list of the same type of data
// dont forget about multi-dimensional array and dynamic memory for array

int main() {

  int saving[12]; // declare the array and its size
  int total, average;

  std::string breakfast[] = {
      "Fried egg", "cooked salmon",
      "boiled egg"}; // declare the array and its elements

  for (int i = 0; i < 12; i++) {
    saving[i] = pow(i + 1, 2);
  }

  for (int j = 0; j < 12; j++) {
    total += saving[j];
  }

  average = total / 12;

  std::cout << "The total amount of your saving is: " << total << " $\n";
  std::cout << "Your average monthly saving is: " << average;

  return 0;
}
