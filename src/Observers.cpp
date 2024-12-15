#include "../include/Observers.h"
#include <iostream>
#include <fstream>

void ConsoleLogger::update(const std::string& message) {
    std::cout << "" << message << std::endl;
}

void ConsoleLogger::onDeath(const std::string& event) {
    std::cout << "Death event: " << event << std::endl;
}

FileLogger::FileLogger(const std::string& filename) : logFile(filename, std::ios::app) {
    if (!logFile.is_open()) {
        std::cerr << "Failed to open log file!" << std::endl;
    }
}

void FileLogger::update(const std::string& message) {
    if (logFile.is_open()) {
        logFile << "" << message << std::endl;
    }
}

void FileLogger::onDeath(const std::string& event) {
    if (logFile.is_open()) {
        logFile << "Death event: " << event << std::endl;
    }
}
