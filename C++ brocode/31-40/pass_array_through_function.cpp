#include <iostream>

double getMean(double prices[], int size);

int main() {

  double prices[] = {12, 27, 28, 52, 55, 92, 42, 71};
  int size = sizeof(prices) / sizeof(double);
  double mean = getMean(prices, size);

  std::cout << "The average is " << mean;

  return 0;
}

// after a function recieved an array
// it decay into a pointer with no way of knowing it size

double getMean(double prices[], int size) {

  double mean = 0;
  double total = 0;

  for (int i = 0; i < size; i++) {
    total += prices[i];
  }

  mean = total / size;

  return mean;
}
