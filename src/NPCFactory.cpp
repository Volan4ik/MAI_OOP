#include "../include/NPCFactory.h"

// Реализация методов
std::shared_ptr<NPC> NPCFactory::createKnight(const std::string& name, double x, double y) {
    return std::make_shared<Knight>(name, x, y);
}

std::shared_ptr<NPC> NPCFactory::createElf(const std::string& name, double x, double y) {
    return std::make_shared<Elf>(name, x, y);
}

std::shared_ptr<NPC> NPCFactory::createDragon(const std::string& name, double x, double y) {
    return std::make_shared<Dragon>(name, x, y);
}
