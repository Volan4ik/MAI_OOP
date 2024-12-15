#include <gtest/gtest.h>
#include "../include/NPC.h"
#include "../include/NPCFactory.h"
#include "../include/BattleVisitor.h"
#include "../include/BattleSimulator.h"
#include "../include/Observers.h"
#include <sstream>
#include <fstream>

// Тесты для BattleVisitor
TEST(BattleVisitorTest, KnightVsDragon1) {
    NPCFactory factory;
    BattleVisitor visitor;

    auto knight = factory.createKnight("Arthur", 0, 0);
    auto dragon = factory.createDragon("Smaug", 0, 0);

    ASSERT_TRUE(knight->canDefeat(*dragon)) << "Knight should defeat Dragon";
}

TEST(BattleVisitorTest, KnightVsDragon2) {
    NPCFactory factory;
    BattleVisitor visitor;

    auto knight = factory.createKnight("Arthur", 0, 0);
    auto dragon = factory.createDragon("Smaug", 0, 0);

    ASSERT_TRUE(dragon->canDefeat(*knight)) << "Dragon should defeat Knight";
}

TEST(BattleVisitorTest, ElfVsKnight1) {
    NPCFactory factory;
    BattleVisitor visitor;

    auto elf = factory.createElf("Legolas", 0, 0);
    auto knight = factory.createKnight("Arthur", 0, 0);

    ASSERT_TRUE(elf->canDefeat(*knight)) << "Elf should defeat Knight";
}

TEST(BattleVisitorTest, ElfVsKnight2) {
    NPCFactory factory;
    BattleVisitor visitor;

    auto elf = factory.createElf("Legolas", 0, 0);
    auto knight = factory.createKnight("Arthur", 0, 0);

    ASSERT_FALSE(knight->canDefeat(*elf)) << "Knight should not defeat Elf";
}

TEST(BattleVisitorTest, DragonDefeatsAll1) {
    NPCFactory factory;

    auto dragon = factory.createDragon("Smaug", 0, 0);
    auto knight = factory.createKnight("Arthur", 0, 0);

    ASSERT_TRUE(dragon->canDefeat(*knight)) << "Dragon should defeat Knight";
}

TEST(BattleVisitorTest, DragonDefeatsAll2) {
    NPCFactory factory;

    auto dragon = factory.createDragon("Smaug", 0, 0);
    auto elf = factory.createElf("Legolas", 0, 0);

    ASSERT_TRUE(dragon->canDefeat(*elf)) << "Dragon should defeat Elf";
}

// Тесты для BattleSimulator
TEST(BattleSimulatorTest, DistanceCalculation) {
    NPCFactory factory;
    auto npc1 = factory.createKnight("Arthur", 0, 0);
    auto npc2 = factory.createElf("Legolas", 3, 4);

    double distance = npc1->distanceTo(*npc2);
    ASSERT_NEAR(distance, 5.0, 1e-5) << "Distance between NPCs should be 5.0";
}

TEST(BattleSimulatorTest, MoveNPC) {
    NPCFactory factory;
    auto knight = factory.createKnight("Arthur", 0, 0);

    BattleSimulator simulator;
    simulator.moveNPC(knight, 3.0, 4.0);

    auto position = knight->getPosition();
    EXPECT_DOUBLE_EQ(position.first, 3.0);
    EXPECT_DOUBLE_EQ(position.second, 4.0);
}



// Тесты для Observers (логгеры)
TEST(ConsoleLoggerTest, LogToConsole) {
    ConsoleLogger logger;
    testing::internal::CaptureStdout();

    logger.update("Battle started!");
    std::string output = testing::internal::GetCapturedStdout();

    ASSERT_EQ(output, "Battle started!\n") << "ConsoleLogger should print correct message";
}

TEST(FileLoggerTest, LogToFile) {
    FileLogger logger("test_log.txt");
    logger.update("NPC defeated!");

    std::ifstream file("test_log.txt");
    ASSERT_TRUE(file.is_open()) << "Log file should be created";

    std::string line;
    std::getline(file, line);
    ASSERT_EQ(line, "NPC defeated!") << "FileLogger should write correct message";

    file.close();
    std::remove("test_log.txt"); // Удаляем тестовый файл после проверки
}
