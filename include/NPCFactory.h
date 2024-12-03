#pragma once
#include "NPC.h"
#include <memory>

class NPCFactory {
public:
    std::shared_ptr<NPC> createKnight(const std::string& name, double x, double y);
    std::shared_ptr<NPC> createElf(const std::string& name, double x, double y);
    std::shared_ptr<NPC> createDragon(const std::string& name, double x, double y);
    
    std::shared_ptr<NPC> createNPC(const std::string& type, const std::string& name, double x, double y) {
        if (type == "Knight") {
            return createKnight(name, x, y);
        } else if (type == "Elf") {
            return createElf(name, x, y);
        } else if (type == "Dragon") {
            return createDragon(name, x, y);
        } else {
            throw std::invalid_argument("Unknown NPC type");
        }
    }
};
