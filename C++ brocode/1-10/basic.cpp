#include <iostream>

int main() {

  /*
   this is a multi-line comment
  */

  std::cout << "i like fried rice"
            << std::endl;                // new line (flush output buffer)
  std::cout << "it really good" << '\n'; // better performance
  std::cout << "but i never ate pancake in my life \n";
  std::cout << "So i would pick waffle 100% of the time ";

  return 0;
}
