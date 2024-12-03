#include <gtest/gtest.h>
#include "../include/NPCFactory.h"
#include "../include/BattleVisitor.h"
#include "../include/Observers.h"

// Тест на создание NPC через фабрику
TEST(NPCFactoryTest, CreateNPCs) {
    NPCFactory factory;

    auto knight = factory.createKnight("Knight", 0.0, 0.0);
    auto elf = factory.createElf("Elf", 1.0, 1.0);
    auto dragon = factory.createDragon("Dragon", 2.0, 2.0);

    ASSERT_EQ(knight->getName(), "Knight");
    ASSERT_EQ(elf->getName(), "Elf");
    ASSERT_EQ(dragon->getName(), "Dragon");

    EXPECT_EQ(knight->getX(), 0.0);
    EXPECT_EQ(knight->getY(), 0.0);
    EXPECT_EQ(elf->getX(), 1.0);
    EXPECT_EQ(elf->getY(), 1.0);
    EXPECT_EQ(dragon->getX(), 2.0);
    EXPECT_EQ(dragon->getY(), 2.0);
}

// Тест на логику битвы (полиморфизм через canDefeat)
TEST(BattleVisitorTest, NPCDefeatLogic) {
    NPCFactory factory;
    BattleVisitor visitor;

    auto knight = factory.createKnight("Knight", 0.0, 0.0);
    auto elf = factory.createElf("Elf", 1.0, 1.0);
    auto dragon = factory.createDragon("Dragon", 2.0, 2.0);

    visitor.addNPC(knight);
    visitor.addNPC(elf);
    visitor.addNPC(dragon);

    ConsoleLogger consoleLogger;
    visitor.addObserver(&consoleLogger);

    visitor.startBattle(3.0);

    EXPECT_EQ(visitor.getNPCCount(), 1);
    EXPECT_EQ(visitor.getNPCByIndex(0)->getName(), "Dragon");
}

// Тест на уведомление наблюдателей
TEST(ObserverTest, NotifyObservers) {
    NPCFactory factory;
    BattleVisitor visitor;

    auto knight = factory.createKnight("Knight", 0.0, 0.0);
    auto dragon = factory.createDragon("Dragon", 1.0, 1.0);

    visitor.addNPC(knight);
    visitor.addNPC(dragon);

    ConsoleLogger consoleLogger;
    FileLogger fileLogger("battle_log.txt");

    visitor.addObserver(&consoleLogger);
    visitor.addObserver(&fileLogger);

    visitor.startBattle(2.0);

    std::ifstream logFile("battle_log.txt");
    ASSERT_TRUE(logFile.is_open());
}


// Тест на корректное удаление NPC после поражения
TEST(BattleVisitorTest, RemoveDefeatedNPCs) {
    NPCFactory factory;
    BattleVisitor visitor;

    auto knight = factory.createKnight("Knight", 0.0, 0.0);
    auto elf = factory.createElf("Elf", 1.0, 1.0);

    visitor.addNPC(knight);
    visitor.addNPC(elf);

    visitor.startBattle(2.0);

    EXPECT_EQ(visitor.getNPCCount(), 1);
    EXPECT_NE(visitor.getNPCByIndex(0)->getName(), "Knight"); 
}

// Тесты для NPCFactory
TEST(NPCFactoryTest, CreateKnight) {
    NPCFactory factory;
    auto knight = factory.createKnight("Arthur", 0.0, 0.0);
    ASSERT_EQ(knight->getName(), "Arthur");
    ASSERT_DOUBLE_EQ(knight->getX(), 0.0);
    ASSERT_DOUBLE_EQ(knight->getY(), 0.0);
}

TEST(NPCFactoryTest, CreateElf) {
    NPCFactory factory;
    auto elf = factory.createElf("Legolas", 1.0, 2.0);
    ASSERT_EQ(elf->getName(), "Legolas");
    ASSERT_DOUBLE_EQ(elf->getX(), 1.0);
    ASSERT_DOUBLE_EQ(elf->getY(), 2.0);
}

TEST(NPCFactoryTest, CreateDragon) {
    NPCFactory factory;
    auto dragon = factory.createDragon("Smaug", 10.0, 20.0);
    ASSERT_EQ(dragon->getName(), "Smaug");
    ASSERT_DOUBLE_EQ(dragon->getX(), 10.0);
    ASSERT_DOUBLE_EQ(dragon->getY(), 20.0);
}

// Тесты для BattleVisitor
TEST(BattleVisitorTest, AddNPC) {
    BattleVisitor visitor;
    NPCFactory factory;

    auto knight = factory.createKnight("Arthur", 0.0, 0.0);
    visitor.addNPC(knight);

    ASSERT_EQ(visitor.getNPCCount(), 1);
    ASSERT_EQ(visitor.getNPCByIndex(0)->getName(), "Arthur");
}

TEST(BattleVisitorTest, NotifyObservers) {
    BattleVisitor visitor;
    ConsoleLogger consoleLogger;
    FileLogger fileLogger("log.txt");

    visitor.addObserver(&consoleLogger);
    visitor.addObserver(&fileLogger);

    NPCFactory factory;
    auto knight = factory.createKnight("Arthur", 0.0, 0.0);
    auto dragon = factory.createDragon("Smaug", 1.0, 1.0);

    visitor.addNPC(knight);
    visitor.addNPC(dragon);

    visitor.startBattle(2.0);

    ASSERT_EQ(visitor.getNPCCount(), 0);
}

// Тесты для взаимодействий NPC
TEST(NPCTest, DistanceCalculation) {
    NPCFactory factory;
    auto knight = factory.createKnight("Arthur", 0.0, 0.0);
    auto elf = factory.createElf("Legolas", 3.0, 4.0);

    ASSERT_DOUBLE_EQ(knight->distanceTo(*elf), 5.0);
}

TEST(NPCTest, CanDefeatLogicForKnight) {
    NPCFactory factory;
    auto knight = factory.createKnight("Arthur", 0.0, 0.0);
    auto dragon = factory.createDragon("Smaug", 1.0, 1.0);

    ASSERT_TRUE(knight->canDefeat(*dragon));
}

TEST(NPCTest, CDLForDragon) {
    NPCFactory factory;
    auto knight = factory.createKnight("Arthur", 0.0, 0.0);
    auto dragon = factory.createDragon("Smaug", 1.0, 1.0);

    ASSERT_TRUE(dragon->canDefeat(*knight)); 
}

TEST(NPCTest, CDLForElf) {
    NPCFactory factory;
    auto knight = factory.createKnight("Arthur", 0.0, 0.0);
    auto elf = factory.createElf("Legolas", 3.0, 4.0);

    ASSERT_TRUE(elf->canDefeat(*knight));  
}

TEST(NPCTest, DragonCanDefeatLogic) {
    std::unique_ptr<NPC> dragon = std::make_unique<Dragon>("Smaug", 10.0, 20.0);
    std::unique_ptr<NPC> knight = std::make_unique<Knight>("Arthur", 5.0, 15.0);
    std::unique_ptr<NPC> elf = std::make_unique<Elf>("Legolas", 7.0, 10.0);


    EXPECT_TRUE(dragon->canDefeat(*knight));
    EXPECT_TRUE(dragon->canDefeat(*dragon));
}

// Тесты для ConsoleLogger и FileLogger
TEST(LoggerTest, ConsoleLoggerOutput) {
    ConsoleLogger logger;
    logger.onDeath("Arthur has been defeated by Smaug");
}

TEST(LoggerTest, FileLoggerOutput) {
    FileLogger logger("test_log.txt");
    logger.onDeath("Arthur has been defeated by Smaug");

    std::ifstream logFile("test_log.txt");
    ASSERT_TRUE(logFile.is_open());

    std::string line;
    std::getline(logFile, line);
    ASSERT_EQ(line, "Death event: Arthur has been defeated by Smaug");

    logFile.close();
}


TEST(BattleLogicTest, NoBattleOutOfRange) {
    BattleVisitor visitor;
    NPCFactory factory;

    auto knight = factory.createKnight("Arthur", 0.0, 0.0);
    auto dragon = factory.createDragon("Smaug", 10.0, 10.0); 

    visitor.addNPC(knight);
    visitor.addNPC(dragon);

    visitor.startBattle(2.0); 

    ASSERT_EQ(visitor.getNPCCount(), 2); 
}


