#include <iostream>

int main() {
  // Useful String Methods
  /*Note that std::string data type is mutable meaning that you can change the
   * content of a variable with this data type after initialization*/

  std::string userName;

  std::cout << "Enter your full name\n";
  std::getline(std::cin, userName);

  // get the total numbers of a string using the length function
  std::cout << userName.length() << "\n";

  // check is the string is empty or not using the empty method
  std::cout << userName.empty() << "\n";

  // delete all the characters in a string using the clear method
  // userName.clear();
  // std::cout << "Result:" << userName;

  // concatenate two strings using the append method
  userName.append(" Basdouri"); // userName + " Basdouri"
  std::cout << userName << "\n";

  // get a character at a specified index using the [] or the at method
  std::cout << userName[0] << "\n";
  std::cout << userName.at(2) << "\n";

  // insert a string starting from a specific index
  userName.insert(userName.length(), " Hello");
  std::cout << userName << "\n";

  // find a specific character or string with the find method
  // it returns the index of the first occurence
  std::cout << userName.find("Amine") << "\n";

  // delete a portion of string using the erase method
  // it takes the index to start with and how many characters as arguments
  userName.erase(0, 4);
  std::cout << userName << "\n";

  return 0;
}
