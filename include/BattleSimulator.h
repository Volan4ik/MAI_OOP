#ifndef BATTLESIMULATOR_H
#define BATTLESIMULATOR_H

#include "NPC.h"
#include <vector>
#include <thread>
#include <mutex>
#include <shared_mutex>

class BattleSimulator {
public:
    BattleSimulator(size_t npcCount, int mapWidth, int mapHeight);
    void run();

private:
    void moveNPCs();
    void handleBattles();
    void printMap();
    bool areClose(const NPC& a, const NPC& b);

    std::vector<NPC> npcs;
    std::vector<std::thread> threads;
    std::atomic<bool> running;

    int mapWidth;
    int mapHeight;

    std::shared_mutex npcMutex;
    std::mutex coutMutex;

    std::random_device rd;
    std::mt19937 gen;
    std::uniform_int_distribution<int> moveDist;
};

#endif // BATTLESIMULATOR_H
