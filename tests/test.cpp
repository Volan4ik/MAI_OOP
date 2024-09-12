#include <gtest/gtest.h>
#include <FearOfNumbers.h>

TEST(FearOfNumbersTest, MondayTest) {
    EXPECT_TRUE(is_afraid("Понедельник", 12));
    EXPECT_FALSE(is_afraid("Понедельник", 13));
}

TEST(FearOfNumbersTest, TuesdayTest) {
    EXPECT_TRUE(is_afraid("Вторник", 96));
    EXPECT_FALSE(is_afraid("Вторник", 50));
}

TEST(FearOfNumbersTest, WednesdayTest) {
    EXPECT_TRUE(is_afraid("Среда", 34));
    EXPECT_FALSE(is_afraid("Среда", 35));
}

TEST(FearOfNumbersTest, ThursdayTest) {
    EXPECT_TRUE(is_afraid("Четверг", 0));
    EXPECT_FALSE(is_afraid("Четверг", 1));
}

TEST(FearOfNumbersTest, FridayTest) {
    EXPECT_TRUE(is_afraid("Пятница", 2));
    EXPECT_TRUE(is_afraid("Пятница", 10));
    EXPECT_FALSE(is_afraid("Пятница", 3));
}

TEST(FearOfNumbersTest, SaturdayTest) {
    EXPECT_TRUE(is_afraid("Суббота", 56));
    EXPECT_FALSE(is_afraid("Суббота", 57));
}

TEST(FearOfNumbersTest, SundayTest) {
    EXPECT_TRUE(is_afraid("Воскресенье", 666));
    EXPECT_TRUE(is_afraid("Воскресенье", -666));
    EXPECT_FALSE(is_afraid("Воскресенье", 665));
}

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
