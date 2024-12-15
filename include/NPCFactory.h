#pragma once
#include "DerivedNPCs.h"
#include "NPC.h"
#include <memory>

class NPCFactory {
public:
    static std::shared_ptr<NPC> createKnight(const std::string& name, double x, double y);
    static std::shared_ptr<NPC> createDragon(const std::string& name, double x, double y);
    static std::shared_ptr<NPC> createElf(const std::string& name, double x, double y);
    static std::shared_ptr<NPC> createNPC(const std::string& type, const std::string& name, double x, double y);
};
