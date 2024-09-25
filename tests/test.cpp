// #include "seven.h"
// #include <gtest/gtest.h>

// TEST(SevenConstructorTest, FromString) {
//     std::string input = "123";
//     Seven num(input);
//     EXPECT_EQ(num, Seven("123"));
// }

// TEST(SevenConstructorTest, DefaultConstructor) {
//     Seven num;
//     EXPECT_EQ(num, Seven("0"));  
// }

// TEST(SevenArithmeticTest, Addition) {
//     Seven num1("123");
//     Seven num2("456");  
//     Seven result = num1 + num2;
//     EXPECT_EQ(result, Seven("1022")); 
// }

// TEST(SevenAssignmentTest, CopyAssignment) {
//     Seven num1("123");
//     Seven num2;
//     num2 = num1;
//     EXPECT_EQ(num2, num1);
// }

// TEST(SevenAssignmentTest, MoveAssignment) {
//     Seven num1("123");
//     Seven num2;
//     num2 = std::move(num1);
//     EXPECT_EQ(num2, Seven("123")); 
//     EXPECT_EQ(num1, Seven()); 
// }

// TEST(SevenComparisonTest, Equality) {
//     Seven num1("123");
//     Seven num2("123");
//     EXPECT_TRUE(num1 == num2);
// }

// TEST(SevenComparisonTest, Inequality) {
//     Seven num1("123");
//     Seven num2("456");
//     EXPECT_TRUE(num1 != num2);
// }

// TEST(SevenComparisonTest, LessThan) {
//     Seven num1("123");
//     Seven num2("456");
//     EXPECT_TRUE(num1 < num2);
// }

// TEST(SevenComparisonTest, GreaterThan) {
//     Seven num1("456");
//     Seven num2("123");
//     EXPECT_TRUE(num1 > num2);
// }

// int main(int argc, char **argv) {
//     ::testing::InitGoogleTest(&argc, argv);
//     return RUN_ALL_TESTS();
// }
#include "seven.h"
#include <gtest/gtest.h>

TEST(SevenConstructorTest, DefaultConstructor) {
    Seven num;
    EXPECT_EQ(num, Seven("0"));
}

TEST(SevenConstructorTest, FromStringValid) {
    std::string input = "123";
    Seven num(input);
    EXPECT_EQ(num, Seven("123"));
}

TEST(SevenConstructorTest, FromStringInvalid) {
    std::string input = "789";
    testing::internal::CaptureStderr();
    Seven num(input);
    std::string error_output = testing::internal::GetCapturedStderr();
    EXPECT_EQ(error_output, "Error: Invalid digit in seven number\n");
}

TEST(SevenArithmeticTest, Addition) {
    Seven num1("123");
    Seven num2("456");
    Seven result = num1 + num2;
    EXPECT_EQ(result, Seven("612"));
}

TEST(SevenArithmeticTest, AdditionWithCarry) {
    Seven num1("666");
    Seven num2("1");
    Seven result = num1 + num2;
    EXPECT_EQ(result, Seven("1000"));
}

TEST(SevenAssignmentTest, CopyAssignment) {
    Seven num1("123");
    Seven num2 = num1;
    EXPECT_EQ(num2, num1);
}

TEST(SevenAssignmentTest, MoveAssignment) {
    Seven num1("123");
    Seven num2 = std::move(num1);
    EXPECT_EQ(num2, Seven("123"));
    EXPECT_EQ(num1, Seven());
}

TEST(SevenComparisonTest, Equality) {
    Seven num1("123");
    Seven num2("123");
    EXPECT_TRUE(num1 == num2);
}

TEST(SevenComparisonTest, Inequality) {
    Seven num1("123");
    Seven num2("456");
    EXPECT_TRUE(num1 != num2);
}

TEST(SevenComparisonTest, LessThan) {
    Seven num1("123");
    Seven num2("456");
    EXPECT_TRUE(num1 < num2);
}

TEST(SevenComparisonTest, GreaterThan) {
    Seven num1("456");
    Seven num2("123");
    EXPECT_TRUE(num1 > num2);
}

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
