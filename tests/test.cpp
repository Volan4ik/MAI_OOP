#include "gtest/gtest.h"
#include "../include/Pentagon.h"
#include "../include/Hexagon.h"
#include "../include/Octagon.h"
#include <sstream>

// Тесты для пятиугольника
TEST(PentagonTests, AreaCalculation) {
    Pentagon pentagon;
    std::istringstream input("-31 95 -81 -59 -81 59 31 -95");
    input >> pentagon;

    double area = pentagon.area();
    EXPECT_NEAR(area, 2916, 1e-6);
}

TEST(PentagonTests, GeometricCenterCalculation) {
    Pentagon pentagon;
    std::istringstream input("0 0 1 0 1 1 0 1 -1 0");
    input >> pentagon;

    auto center = pentagon.geometricCenter();
    EXPECT_NEAR(center.first, 0.2, 1e-6);
}

TEST(PentagonTests, PrintTest) {
    Pentagon pentagon;
    std::istringstream input("0 0 1 0 1 1 0 1 -1 0");
    input >> pentagon;

    std::ostringstream output;
    pentagon.print(output);
    
    EXPECT_EQ(output.str(), "(0, 0) (1, 0) (1, 1) (0, 1) (-1, 0) ");
}

TEST(PentagonTests, RemoveFigureByIndex) {
    std::vector<Pentagon> pentagons;
    pentagons.emplace_back();
    pentagons.emplace_back();
    pentagons.emplace_back();

    EXPECT_EQ(pentagons.size(), 3);
    pentagons.erase(pentagons.begin() + 1);  
    EXPECT_EQ(pentagons.size(), 2);
}

TEST(PentagonTests, TotalArea) {
    std::vector<Pentagon> pentagons;
    Pentagon pentagon1, pentagon2;
    
    std::istringstream input1("-31 95 -81 -59 -81 59 31 -95");
    input1 >> pentagon1;
    std::istringstream input2("0 0 1 0 1 1 0 1 -1 0");
    input2 >> pentagon2;

    pentagons.push_back(pentagon1);
    pentagons.push_back(pentagon2);

    double totalArea = 0;
    for (const auto& pentagon : pentagons) {
        totalArea += pentagon.area();
    }
    
    EXPECT_NEAR(totalArea, 2917.5, 1e-6);  
}

// Тесты для шестиугольника
TEST(HexagonTests, AreaCalculation) {
    Hexagon hexagon;
    std::istringstream input("0 0 1 0 1 1 0 1 -1 1 -1 0");
    input >> hexagon;

    double area = hexagon.area();
    EXPECT_NEAR(area, 2, 1e-6);
}

TEST(HexagonTests, GeometricCenterCalculation) {
    Hexagon hexagon;
    std::istringstream input("0 0 1 0 1 1 0 1 -1 1 -1 0");
    input >> hexagon;

    auto center = hexagon.geometricCenter();
    EXPECT_NEAR(center.first, 0.0, 1e-6);
    EXPECT_NEAR(center.second, 0.5, 1e-6);
}

TEST(HexagonTests, PrintTest) {
    Hexagon hexagon;
    std::istringstream input("0 0 1 0 1 1 0 1 -1 1 -1 0");
    input >> hexagon;

    std::ostringstream output;
    hexagon.print(output);
    
    EXPECT_EQ(output.str(), "(0, 0) (1, 0) (1, 1) (0, 1) (-1, 1) (-1, 0) ");
}

TEST(HexagonTests, RemoveFigureByIndex) {
    std::vector<Hexagon> hexagons;
    hexagons.emplace_back();
    hexagons.emplace_back();
    hexagons.emplace_back();

    EXPECT_EQ(hexagons.size(), 3);
    hexagons.erase(hexagons.begin() + 1);  
    EXPECT_EQ(hexagons.size(), 2);
}

TEST(HexagonTests, TotalArea) {
    std::vector<Hexagon> hexagons;
    Hexagon hexagon1, hexagon2;
    
    std::istringstream input1("0 0 1 0 1 1 0 1 -1 1 -1 0");
    input1 >> hexagon1;
    std::istringstream input2("0 0 1 0 1 1 0 1 -1 1 -1 0");
    input2 >> hexagon2;

    hexagons.push_back(hexagon1);
    hexagons.push_back(hexagon2);

    double totalArea = 0;
    for (const auto& hexagon : hexagons) {
        totalArea += hexagon.area();
    }
    
    EXPECT_NEAR(totalArea, 2 + 2, 1e-6); 
}

// Тесты для восьмиугольника
TEST(OctagonTests, AreaCalculation) {
    Octagon octagon;
    std::istringstream input("0 0 1 0 1 1 0 1 -1 1 -1 0 0 -1 1 -1");
    input >> octagon;

    double area = octagon.area();
    EXPECT_NEAR(area, 3, 1e-6);
}

TEST(OctagonTests, GeometricCenterCalculation) {
    Octagon octagon;
    std::istringstream input("0 0 1 0 1 1 0 1 -1 1 -1 0 0 -1 1 -1");
    input >> octagon;

    auto center = octagon.geometricCenter();
    EXPECT_NEAR(center.first, 0.125, 1e-6);
    EXPECT_NEAR(center.second, 0.125, 1e-6);
}

TEST(OctagonTests, PrintTest) {
    Octagon octagon;
    std::istringstream input("0 0 1 0 1 1 0 1 -1 1 -1 0 0 -1 1 -1");
    input >> octagon;

    std::ostringstream output;
    octagon.print(output);
    
    EXPECT_EQ(output.str(), "(0, 0) (1, 0) (1, 1) (0, 1) (-1, 1) (-1, 0) (0, -1) (1, -1) ");
}

TEST(OctagonTests, RemoveFigureByIndex) {
    std::vector<Octagon> octagons;
    octagons.emplace_back();
    octagons.emplace_back();
    octagons.emplace_back();

    EXPECT_EQ(octagons.size(), 3);
    octagons.erase(octagons.begin() + 1);  
    EXPECT_EQ(octagons.size(), 2);
}

TEST(OctagonTests, TotalArea) {
    std::vector<Octagon> octagons;
    Octagon octagon1, octagon2;
    
    std::istringstream input1("0 0 1 0 1 1 0 1 -1 1 -1 0 0 -1 1 -1");
    input1 >> octagon1;
    std::istringstream input2("0 0 1 0 1 1 0 1 -1 1 -1 0 0 -1 1 -1");
    input2 >> octagon2;

    octagons.push_back(octagon1);
    octagons.push_back(octagon2);

    double totalArea = 0;
    for (const auto& octagon : octagons) {
        totalArea += octagon.area();
    }
    
    EXPECT_NEAR(totalArea, 3 + 3, 1e-6);  
}