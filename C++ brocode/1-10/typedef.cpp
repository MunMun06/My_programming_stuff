#include <iostream>
#include <vector>

typedef std::string text_t;
using b_t = bool;
using std::cout;

int main() {

  // typedef create keyword for data type. help with readability and reduce
  // typo. needed #include <vector>.
  // using replaced typedef. better with templates.
  // use these when there are clear benefit

  b_t real_name = false;
  text_t name = "Mun";
  cout << name << " " << real_name;

  return 0;
}
