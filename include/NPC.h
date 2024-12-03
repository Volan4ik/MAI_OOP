#pragma once
#include <string>
#include <cmath>

class NPC {
public:
    NPC(const std::string& name, double x, double y);
    virtual ~NPC() = default;

    std::string getName() const;
    double getX() const;
    double getY() const;
    double distanceTo(const NPC& other) const;

    virtual bool canDefeat(const NPC& other) const = 0;
    virtual std::string getType() const = 0;


protected:
    std::string name;
    double x, y;
};

class Knight : public NPC {
public:
    using NPC::NPC;
    bool canDefeat(const NPC& other) const override;

    std::string getType() const override { return "Knight"; }
};


class Elf : public NPC {
public:
    using NPC::NPC;
    bool canDefeat(const NPC& other) const override;
    std::string getType() const override { return "Elf"; }
};

class Dragon : public NPC {
public:
    using NPC::NPC;
    bool canDefeat(const NPC& other) const override;
    std::string getType() const override { return "Dragon"; }
};
