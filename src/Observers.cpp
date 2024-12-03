#include "../include/Observers.h"
#include <ctime>
#include <iomanip>

void ConsoleLogger::onDeath(const std::string& event) {
    std::cout << "Death event: " << event << std::endl;
}

FileLogger::FileLogger(const std::string& filename) : logFile(filename, std::ios::app) {
    if (!logFile.is_open()) {
        throw std::ios_base::failure("Failed to open log file");
    }
}

void FileLogger::onDeath(const std::string& event) {
    if (logFile.is_open()) {
        logFile << "Death event: " << event << std::endl;
    }
}