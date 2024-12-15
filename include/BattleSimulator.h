#pragma once
#include "NPC.h"
#include <vector>
#include <memory>
#include <random>
#include <iostream>
#include <thread>
#include <shared_mutex>
#include <chrono>

class BattleSimulator {
public:
    void addNPC(std::shared_ptr<NPC> npc);
    void runSimulation();
    void moveNPC(std::shared_ptr<NPC> npc, double x, double y) {
        npc->setPosition(x, y);
    }

private:
    std::vector<std::shared_ptr<NPC>> npcs;
    std::shared_mutex npcMutex;
    std::mutex coutMutex;

    void fightNPCs();
    void printMap();
    bool simulationRunning = true;

    bool rollDice(int attack, int defense);
    static constexpr int MAP_WIDTH = 100;
    static constexpr int MAP_HEIGHT = 100;
    static constexpr int SIMULATION_TIME = 30; // seconds
};
