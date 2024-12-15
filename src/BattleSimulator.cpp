#include "BattleSimulator.h"
#include <iostream>
#include <chrono>
#include <cmath>
#include <thread>

BattleSimulator::BattleSimulator(size_t npcCount, int mapWidth, int mapHeight)
    : running(true), mapWidth(mapWidth), mapHeight(mapHeight), gen(rd()), moveDist(-10, 10) {
    for (size_t i = 0; i < npcCount; ++i) {
        int x = rand() % mapWidth;
        int y = rand() % mapHeight;
        npcs.emplace_back(i, x, y);
    }
}

void BattleSimulator::run() {
    auto start = std::chrono::steady_clock::now();

    threads.emplace_back([this]() { moveNPCs(); });
    threads.emplace_back([this]() { handleBattles(); });

    while (std::chrono::steady_clock::now() - start < std::chrono::seconds(30)) {
        printMap();
        std::this_thread::sleep_for(std::chrono::seconds(1));
    }

    running = false;

    for (auto& thread : threads) {
        if (thread.joinable()) thread.join();
    }

    std::cout << "\nSimulation finished. Survivors:\n";
    for (const auto& npc : npcs) {
        if (npc.isAlive()) {
            std::cout << "NPC " << npc.getID() << " at (" << npc.getX() << ", " << npc.getY() << ")\n";
        }
    }
}

void BattleSimulator::moveNPCs() {
    while (running) {
        std::unique_lock lock(npcMutex);
        for (auto& npc : npcs) {
            if (npc.isAlive()) {
                npc.move(moveDist(gen), moveDist(gen), mapWidth, mapHeight);
            }
        }
        std::this_thread::sleep_for(std::chrono::milliseconds(100));
    }
}

void BattleSimulator::handleBattles() {
    while (running) {
        std::unique_lock lock(npcMutex);
        for (size_t i = 0; i < npcs.size(); ++i) {
            for (size_t j = i + 1; j < npcs.size(); ++j) {
                if (!npcs[i].isAlive() || !npcs[j].isAlive()) continue;

                if (areClose(npcs[i], npcs[j])) {
                    int attack = npcs[i].rollDice();
                    int defense = npcs[j].rollDice();

                    std::lock_guard<std::mutex> coutLock(coutMutex);
                    std::cout << "NPC " << npcs[i].getID() << " attacks NPC " << npcs[j].getID()
                              << " (Attack: " << attack << ", Defense: " << defense << ")\n";

                    if (attack > defense) npcs[j].kill();
                    else npcs[i].kill();
                }
            }
        }
        std::this_thread::sleep_for(std::chrono::milliseconds(100));
    }
}

void BattleSimulator::printMap() {
    std::lock_guard<std::mutex> coutLock(coutMutex);
    std::cout << "\nMap state:\n";
    for (const auto& npc : npcs) {
        if (npc.isAlive()) {
            std::cout << "NPC " << npc.getID() << " at (" << npc.getX() << ", " << npc.getY() << ")\n";
        }
    }
}

bool BattleSimulator::areClose(const NPC& a, const NPC& b) {
    return std::abs(a.getX() - b.getX()) <= 5 && std::abs(a.getY() - b.getY()) <= 5;
}
