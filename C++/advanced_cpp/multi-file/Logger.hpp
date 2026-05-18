#ifndef LOGGER_HPP // Header Guard: Prevents double-inclusion
#define LOGGER_HPP

// define LOGGER_HPP for the preprocessor. Because #include is just text replacement done by the preprocessor.

// only include what you needed for declaration in .hpp
#include <string>

class Logger {
public:
    void log(const std::string& message);
};

#endif
