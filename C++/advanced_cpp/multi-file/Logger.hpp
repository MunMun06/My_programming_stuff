#ifndef LOGGER_HPP // Header Guard: Prevents double-inclusion
#define LOGGER_HPP

#include <string>

class Logger {
public:
    void log(const std::string& message);
};

#endif
