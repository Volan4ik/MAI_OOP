#include <gtest/gtest.h>
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
    EXPECT_NEAR(center.second, 0.4, 1e-6);
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
