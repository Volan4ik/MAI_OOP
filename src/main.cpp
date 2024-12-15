#include "BattleSimulator.h"

int main() {
    constexpr size_t npcCount = 50;
    constexpr int mapWidth = 100;
    constexpr int mapHeight = 100;

    BattleSimulator simulator(npcCount, mapWidth, mapHeight);
    simulator.run();

    return 0;
}
