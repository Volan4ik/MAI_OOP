#include "../include/NPC.h"

NPC::NPC(const std::string& name, double x, double y) : name(name), x(x), y(y) {}

std::string NPC::getName() const { return name; }
double NPC::getX() const { return x; }
double NPC::getY() const { return y; }

double NPC::distanceTo(const NPC& other) const {
    return std::sqrt((x - other.x) * (x - other.x) + (y - other.y) * (y - other.y));
}

bool Knight::canDefeat(const NPC& other) const {
    return dynamic_cast<const Dragon*>(&other) != nullptr;
}

bool Elf::canDefeat(const NPC& other) const {
    return dynamic_cast<const Knight*>(&other) != nullptr;
}

bool Dragon::canDefeat(const NPC& other) const {
    return true; 
}
