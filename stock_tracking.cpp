#include <algorithm>
#include <iostream>

double find_total(double input[], int size, double max) {
  double total = 0;
  double prev = 0;
  for (int i = 0; i < size; i++) {
    double first_curr = input[i];
    double curr = first_curr;
    while (curr < max) {
      prev = curr;
      curr += first_curr;
    }
    if ((max - prev) < (curr - max)) {
      total += prev;
    } else {
      total += curr;
    }
  }

  return total;
}

void entry_output(double curr, double max, double total) {
  double prev = 0;
  double first_curr = curr;
  int count = 0;
  while (curr < max) {
    prev = curr;
    curr += first_curr;
    count++;
  }

  if ((max - prev) < (curr - max)) {
    std::cout << count << "   " << prev << "  " << prev * 100 / total << " %";
  } else {
    std::cout << count + 1 << "   " << curr << "  " << curr * 100 / total
              << " %";
  }
}

double find_max(double input[], int size) {
  double curr_max = 0;

  for (int i = 0; i < size; i++) {
    curr_max = std::max(curr_max, input[i]);
  }

  return curr_max;
}
int main() {

  int entry = 0;
  double *pStock = nullptr;
  double temp = 0;

  std::cout << "What is the number of entries: ";
  std::cin >> entry;
  std::cout << '\n';

  pStock = new double[entry];

  for (int i = 0; i < entry; i++) {
    std::cout << "Enter the value for entry " << i << ": ";
    std::cin >> temp;
    pStock[i] = temp;
  }

  std::cout << '\n';

  double max = find_max(pStock, entry);
  double total = find_total(pStock, entry, max);

  std::cout << "The total value of the portfolio is: " << total << '\n';

  for (int i = 0; i < entry; i++) {
    std::cout << "Entry " << i << " (amount, total value, percentage): ";
    entry_output(pStock[i], max, total);
    std::cout << '\n';
  }

  delete[] pStock;

  return 0;
}
