#include "../include/BattleSimulator.h"

void BattleSimulator::addNPC(std::shared_ptr<NPC> npc) {
    std::unique_lock lock(npcMutex);
    npcs.push_back(npc);
}

void BattleSimulator::runSimulation() {
    auto startTime = std::chrono::steady_clock::now();

    std::thread moveThread([this]() { moveNPC(); });
    std::thread fightThread([this]() { fightNPCs(); });

    while (std::chrono::steady_clock::now() - startTime < std::chrono::seconds(SIMULATION_TIME)) {
        printMap();
        std::this_thread::sleep_for(std::chrono::seconds(1));
    }

    simulationRunning = false; // Остановить потоки

    moveThread.join();
    fightThread.join();

    std::cout << "Simulation finished! Survivors:\n";
    for (const auto& npc : npcs) {
        if (npc->isAlive()) {
            std::cout << npc->getType() << " " << npc->getName() << " at (" << npc->getX() << ", " << npc->getY() << ")\n";
        }
    }
}

void BattleSimulator::moveNPC(std::shared_ptr<NPC> npc, double x, double y) {
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_real_distribution<> moveDist(-10, 10);

    while (simulationRunning) { // Использовать флаг
        std::this_thread::sleep_for(std::chrono::milliseconds(100));
        std::unique_lock lock(npcMutex);

        for (auto& npc : npcs) {
            if (npc->isAlive()) {
                double dx = moveDist(gen);
                double dy = moveDist(gen);
                npc->move(dx, dy);

                if (npc->getX() < 0 || npc->getX() > MAP_WIDTH || npc->getY() < 0 || npc->getY() > MAP_HEIGHT) {
                    npc->move(-dx, -dy);
                }
            }
        }
    }
}

void BattleSimulator::fightNPCs() {
    while (simulationRunning) { // Использовать флаг
        std::this_thread::sleep_for(std::chrono::milliseconds(100));
        std::unique_lock lock(npcMutex);

        for (auto& npc1 : npcs) {
            if (!npc1->isAlive()) continue;

            for (auto& npc2 : npcs) {
                if (npc1 == npc2 || !npc2->isAlive()) continue;

                if (npc1->distanceTo(*npc2) <= 10 && npc1->canDefeat(*npc2)) {
                    if (rollDice(6, 6)) { 
                        npc2->kill();
                        std::lock_guard<std::mutex> coutLock(coutMutex);
                        std::cout << npc1->getType() << " " << npc1->getName() << " killed " 
                                  << npc2->getType() << " " << npc2->getName() << "!\n";
                    }
                }
            }
        }
    }
}


void BattleSimulator::printMap() {
    std::lock_guard<std::mutex> coutLock(coutMutex);
    std::cout << "NPC Positions:\n";
    for (const auto& npc : npcs) {
        if (npc->isAlive()) {
            std::cout << npc->getType() << " " << npc->getName() 
                      << " at (" << npc->getX() << ", " << npc->getY() << ")\n";
        }
    }
}

bool BattleSimulator::rollDice(int attack, int defense) {
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> dice(1, 6);

    return dice(gen) > dice(gen);
}
