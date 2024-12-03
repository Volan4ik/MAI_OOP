#include "../include/BattleVisitor.h"

void BattleVisitor::addNPC(std::shared_ptr<NPC> npc) {
    npcs.push_back(npc);
}

void BattleVisitor::addObserver(Observer* observer) {
    observers.push_back(observer);
}

void BattleVisitor::startBattle(double range) {
    for (size_t i = 0; i < npcs.size(); ++i) {
        for (size_t j = i + 1; j < npcs.size(); ++j) {
            if (npcs[i]->distanceTo(*npcs[j]) <= range) {
                bool firstWins = npcs[i]->canDefeat(*npcs[j]);
                bool secondWins = npcs[j]->canDefeat(*npcs[i]);

                if (firstWins && secondWins) {
                    notifyObservers(npcs[i]->getName() + " and " + npcs[j]->getName() + " killed each other!");
                    npcs.erase(npcs.begin() + j);
                    npcs.erase(npcs.begin() + i);
                    --i;
                    break;
                } else if (firstWins) {
                    notifyObservers(npcs[i]->getName() + " killed " + npcs[j]->getName() + "!");
                    npcs.erase(npcs.begin() + j);
                    --j;
                } else if (secondWins) {
                    notifyObservers(npcs[j]->getName() + " killed " + npcs[i]->getName() + "!");
                    npcs.erase(npcs.begin() + i);
                    --i;
                    break;
                }
            }
        }
    }
}

void BattleVisitor::notifyObservers(const std::string& event) {
    for (auto observer : observers) {
        observer->onDeath(event);
    }
}

size_t BattleVisitor::getNPCCount() const {
    return npcs.size();
}

std::shared_ptr<NPC> BattleVisitor::getNPCByIndex(size_t index) const {
    if (index >= npcs.size()) {
        throw std::out_of_range("Index out of range");
    }
    return npcs[index];
}
