#include <iostream>

namespace first {
int x = 1;
int y = 5;
} // namespace first
namespace mature {
int x = 69;
}

int main() {
  using namespace first;
  using std::cout;   // no std::cout but cout
  using std::string; // no std::string but string

  // namespace allow same name variable as long as namespace is different
  // if no namespace is specify. we will use the local version

  int x = 0;
  cout << mature::x << '\n';
  cout << mature::x + y;

  return 0;
}
