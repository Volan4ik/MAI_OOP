#include "../include/NPCFactory.h"
#include "../include/BattleSimulator.h"
#include <iostream>

int main() {
    BattleSimulator simulator;

    for (int i = 0; i < 50; ++i) {
        std::string name = "NPC_" + std::to_string(i);
        double x = rand() % 100;
        double y = rand() % 100;
        std::string type = (i % 3 == 0) ? "Knight" : (i % 3 == 1) ? "Elf" : "Dragon";

        simulator.addNPC(NPCFactory::createNPC(type, name, x, y));
    }

    std::cout << "Starting simulation...\n";
    simulator.runSimulation();

    return 0;
}
