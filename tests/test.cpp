#include <gtest/gtest.h>
#include "FearOfNumbers.h"

TEST(FearOfNumbersTest, MondayTest) {
    std::string day = "Понедельник";
    int number1 = 12;
    int number2 = 13;

    bool result1 = is_afraid(day, number1);
    bool result2 = is_afraid(day, number2);

    EXPECT_TRUE(result1);
    EXPECT_FALSE(result2);
}

TEST(FearOfNumbersTest, TuesdayTest) {
    std::string day = "Вторник";
    int number1 = 96;
    int number2 = 50;

    bool result1 = is_afraid(day, number1);
    bool result2 = is_afraid(day, number2);

    EXPECT_TRUE(result1);
    EXPECT_FALSE(result2);
}

TEST(FearOfNumbersTest, WednesdayTest) {
    std::string day = "Среда";
    int number1 = 34;
    int number2 = 35;

    bool result1 = is_afraid(day, number1);
    bool result2 = is_afraid(day, number2);

    EXPECT_TRUE(result1);
    EXPECT_FALSE(result2);
}

TEST(FearOfNumbersTest, ThursdayTest) {
    std::string day = "Четверг";
    int number1 = 0;
    int number2 = 1;

    bool result1 = is_afraid(day, number1);
    bool result2 = is_afraid(day, number2);

    EXPECT_TRUE(result1);
    EXPECT_FALSE(result2);
}

TEST(FearOfNumbersTest, FridayTest) {
    std::string day = "Пятница";
    int number1 = 2;
    int number2 = 10;
    int number3 = 3;

    bool result1 = is_afraid(day, number1);
    bool result2 = is_afraid(day, number2);
    bool result3 = is_afraid(day, number3);

    EXPECT_TRUE(result1);
    EXPECT_TRUE(result2);
    EXPECT_FALSE(result3);
}

TEST(FearOfNumbersTest, SaturdayTest) {
    std::string day = "Суббота";
    int number1 = 56;
    int number2 = 57;

    bool result1 = is_afraid(day, number1);
    bool result2 = is_afraid(day, number2);

    EXPECT_TRUE(result1);
    EXPECT_FALSE(result2);
}

TEST(FearOfNumbersTest, SundayTest) {
    std::string day = "Воскресенье";
    int number1 = 666;
    int number2 = -666;
    int number3 = 665;

    bool result1 = is_afraid(day, number1);
    bool result2 = is_afraid(day, number2);
    bool result3 = is_afraid(day, number3);

    EXPECT_TRUE(result1);
    EXPECT_TRUE(result2);
    EXPECT_FALSE(result3);
}

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
