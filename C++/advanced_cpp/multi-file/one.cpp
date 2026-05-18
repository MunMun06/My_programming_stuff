#include "Logger.hpp"

// one only get library included in Logger.hpp not Logger.cpp. 
// Because its preprocessing and text replacement by the preprocessor.

int main() {
    Logger myLog;
    myLog.log("System initialized via multi-file setup.");
    return 0;
}
