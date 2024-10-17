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

// Аналогичные тесты для шестиугольника и восьмиугольника
