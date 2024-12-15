#include "../include/NPC.h"

NPC::NPC(const std::string& name, double x, double y) : name(name), x(x), y(y) {}

std::string NPC::getName() const { return name; }
double NPC::getX() const { return x; }
double NPC::getY() const { return y; }

double NPC::distanceTo(const NPC& other) const {
    return std::sqrt((x - other.x) * (x - other.x) + (y - other.y) * (y - other.y));
}

void NPC::setPosition(double x, double y) {
    this->x = x;
    this->y = y;
}

std::pair<double, double> NPC::getPosition() const {
    return {x, y};
}

void NPC::move(double dx, double dy) {
    x += dx;
    y += dy;
}
