#include <iostream>

int main() {

  // int is 4 bytes, short is 2 bytes, long is 8 bytes, long long is 8 bytes
  // (16 maybe??) float is 8 bytes, double is 8 bytes (16 maybe??)
  // char is 1 bytes

  std::cout << "size of int: " << sizeof(char) << " bytes \n";

  return 0;
}
