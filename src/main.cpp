#include "../include/NPCFactory.h"
#include "../include/BattleVisitor.h"
#include "../include/Observers.h"

int main() {
    NPCFactory factory;
    BattleVisitor battle;

    ConsoleLogger consoleLogger;
    FileLogger fileLogger;

    battle.addObserver(&consoleLogger);
    battle.addObserver(&fileLogger);

    auto knight = factory.createKnight("Arthur", 100, 100);
    auto elf = factory.createElf("Legolas", 200, 200);
    auto dragon = factory.createDragon("Smaug", 150, 150);

    battle.addNPC(knight);
    battle.addNPC(elf);
    battle.addNPC(dragon);

    std::cout << "Starting battle mode...\n";
    battle.startBattle(100.0);

    return 0;
}
