#pragma once
#include "NPC.h"

class Knight : public NPC {
public:
    using NPC::NPC;

    bool canDefeat(const NPC& other) const override {
        return other.getType() == "Dragon";
    }

    std::string getType() const override { return "Knight"; }
};

class Elf : public NPC {
public:
    using NPC::NPC;

    bool canDefeat(const NPC& other) const override {
        return other.getType() == "Knight";
    }

    std::string getType() const override { return "Elf"; }
};

class Dragon : public NPC {
public:
    using NPC::NPC;

    bool canDefeat(const NPC& other) const override {
        return true; // Дракон убивает всех
    }

    std::string getType() const override { return "Dragon"; }
};
