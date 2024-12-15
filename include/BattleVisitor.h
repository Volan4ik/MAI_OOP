#pragma once
#include "NPC.h"
#include "Observers.h"
#include <vector>
#include <memory>

class BattleVisitor {
public:
    void addNPC(std::shared_ptr<NPC> npc);
    void addObserver(Observer* observer);
    void startBattle(double range);
    

    bool hasConflict() const { return conflict; }
    const NPC* getLoser() const { return loser; }
    double distanceBetween(const NPC& a, const NPC& b) {
        return std::hypot(a.getX() - b.getX(), a.getY() - b.getY());
    }
    size_t getNPCCount() const;
    std::shared_ptr<NPC> getNPCByIndex(size_t index) const;



private:
    void notifyObservers(const std::string& event);

    std::vector<std::shared_ptr<NPC>> npcs;
    std::vector<Observer*> observers;
    bool conflict = false;
    const NPC* loser = nullptr;
};

