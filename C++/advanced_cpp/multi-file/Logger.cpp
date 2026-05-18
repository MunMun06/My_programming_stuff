#include "Logger.hpp"
#include <iostream>

// only include what you need in that file. 
// you can include more stuff for the definition of this file. (its encapsulation) 

void Logger::log(const std::string& message) {
    std::cout << "[LOG]: " << message << std::endl;
}
