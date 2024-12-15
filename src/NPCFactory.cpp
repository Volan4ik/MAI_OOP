#include "../include/NPCFactory.h"

std::shared_ptr<NPC> NPCFactory::createKnight(const std::string& name, double x, double y) {
    return std::make_shared<Knight>(name, x, y);
}

std::shared_ptr<NPC> NPCFactory::createDragon(const std::string& name, double x, double y) {
    return std::make_shared<Dragon>(name, x, y);
}

std::shared_ptr<NPC> NPCFactory::createElf(const std::string& name, double x, double y) {
    return std::make_shared<Elf>(name, x, y);
}

std::shared_ptr<NPC> NPCFactory::createNPC(const std::string& type, const std::string& name, double x, double y) {
    if (type == "Knight") {
        return createKnight(name, x, y);
    } else if (type == "Dragon") {
        return createDragon(name, x, y);
    } else if (type == "Elf") {
        return createElf(name, x, y);
    }
    throw std::invalid_argument("Unknown NPC type: " + type);
}
