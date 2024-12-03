#pragma once
#include <iostream>
#include <fstream>
#include <string>

class Observer {
public:
    virtual ~Observer() = default;
    virtual void onDeath(const std::string& event) = 0;
};

class ConsoleLogger : public Observer {
public:
    void onDeath(const std::string& event) override;
};

class FileLogger : public Observer {
public:
    FileLogger() : logFile("default_log.txt", std::ios::app) {} 
    explicit FileLogger(const std::string& filename);           
    void onDeath(const std::string& event) override;

private:
    std::ofstream logFile;
};

