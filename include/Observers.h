#pragma once
#include <iostream>
#include <fstream>
#include <string>

class Observer {
public:
    virtual void update(const std::string& message) = 0;
    virtual void onDeath(const std::string& event) = 0; 
};

class ConsoleLogger : public Observer {
public:
    void update(const std::string& message) override; 
    void onDeath(const std::string& event) override;
};

class FileLogger : public Observer {
private:
    std::ofstream logFile;
public:
    FileLogger(const std::string& filename);
    void update(const std::string& message) override;  
    void onDeath(const std::string& event) override;
};


