#pragma once
#include <string>
#include <cmath>

class NPC {
public:
    virtual ~NPC() = default;
    NPC(const std::string& name, double x, double y); 
    void setPosition(double x, double y);
    std::pair<double, double> getPosition() const;

    std::string getName() const;
    double getX() const;
    double getY() const;
    double distanceTo(const NPC& other) const;

    virtual bool canDefeat(const NPC& other) const = 0;
    virtual std::string getType() const = 0;

    bool isAlive() const { return alive; }
    void kill() { alive = false; }

    void move(double dx, double dy);

protected:
    std::string name;
    double x;
    double y;
    bool alive = true;
};
