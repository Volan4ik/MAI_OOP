#include <gtest/gtest.h>
#include "../include/MemoryResource.h"
#include "../include/Stack.h"

// Тест для MemoryResource
// TEST(MemoryResourceTest, BasicAllocation) {
//     MemoryResource memRes(1024);
//     std::pmr::polymorphic_allocator<int> alloc(&memRes);

//     int* ptr1 = alloc.allocate(1);  // Не используется, но нужно для проверки выделения памяти
//     int* ptr2 = alloc.allocate(1);  // Не используется, но нужно для проверки выделения памяти

//     SUCCEED();
// }

TEST(MemoryResourceTest, BasicDeallocation) {
    MemoryResource memRes(1024);
    std::pmr::polymorphic_allocator<int> alloc(&memRes);

    int* ptr1 = alloc.allocate(1);
    int* ptr2 = alloc.allocate(1);
    alloc.deallocate(ptr1, 1);
    alloc.deallocate(ptr2, 1);

    SUCCEED();
}

TEST(StackTest, PushAndTopWithInt_FirstPush) {
    MemoryResource memRes(1024);
    Stack<int> intStack(&memRes);

    intStack.push(1);
    EXPECT_EQ(intStack.top(), 1);
}

TEST(StackTest, PushAndTopWithInt_SecondPush) {
    MemoryResource memRes(1024);
    Stack<int> intStack(&memRes);

    intStack.push(1);
    intStack.push(2);
    EXPECT_EQ(intStack.top(), 2);
}

TEST(StackTest, PushAndTopWithInt_ThirdPush) {
    MemoryResource memRes(1024);
    Stack<int> intStack(&memRes);

    intStack.push(1);
    intStack.push(2);
    intStack.push(3);
    EXPECT_EQ(intStack.top(), 3);
}

TEST(StackTest, PopAndEmptyWithInt_FirstPop) {
    MemoryResource memRes(1024);
    Stack<int> intStack(&memRes);

    intStack.push(1);
    intStack.push(2);
    intStack.push(3);

    intStack.pop();
    EXPECT_EQ(intStack.top(), 2);
}

TEST(StackTest, PopAndEmptyWithInt_SecondPop) {
    MemoryResource memRes(1024);
    Stack<int> intStack(&memRes);

    intStack.push(1);
    intStack.push(2);
    intStack.push(3);

    intStack.pop();
    intStack.pop();
    EXPECT_EQ(intStack.top(), 1);
}

TEST(StackTest, PopAndEmptyWithInt_ThirdPop) {
    MemoryResource memRes(1024);
    Stack<int> intStack(&memRes);

    intStack.push(1);
    intStack.push(2);
    intStack.push(3);

    intStack.pop();
    intStack.pop();
    intStack.pop();
    EXPECT_TRUE(intStack.empty());
}

TEST(StackTest, PushAndTopWithComplexType_FirstPush) {
    struct ComplexType {
        int a;
        double b;
        std::string c;

        ComplexType(int a, double b, const std::string& c) : a(a), b(b), c(c) {}
    };

    MemoryResource memRes(1024);
    Stack<ComplexType> complexStack(&memRes);

    complexStack.push({1, 2.5, "Hello"});
    EXPECT_EQ(complexStack.top().a, 1);
    EXPECT_EQ(complexStack.top().b, 2.5);
    EXPECT_EQ(complexStack.top().c, "Hello");
}

TEST(StackTest, PushAndTopWithComplexType_SecondPush) {
    struct ComplexType {
        int a;
        double b;
        std::string c;

        ComplexType(int a, double b, const std::string& c) : a(a), b(b), c(c) {}
    };

    MemoryResource memRes(1024);
    Stack<ComplexType> complexStack(&memRes);

    complexStack.push({1, 2.5, "Hello"});
    complexStack.push({2, 3.5, "World"});
    EXPECT_EQ(complexStack.top().a, 2);
    EXPECT_EQ(complexStack.top().b, 3.5);
    EXPECT_EQ(complexStack.top().c, "World");
}

TEST(StackTest, PopAndEmptyWithComplexType_FirstPop) {
    struct ComplexType {
        int a;
        double b;
        std::string c;

        ComplexType(int a, double b, const std::string& c) : a(a), b(b), c(c) {}
    };

    MemoryResource memRes(1024);
    Stack<ComplexType> complexStack(&memRes);

    complexStack.push({1, 2.5, "Hello"});
    complexStack.push({2, 3.5, "World"});

    complexStack.pop();
    EXPECT_EQ(complexStack.top().a, 1);
    EXPECT_EQ(complexStack.top().b, 2.5);
    EXPECT_EQ(complexStack.top().c, "Hello");
}

TEST(StackTest, PopAndEmptyWithComplexType_SecondPop) {
    struct ComplexType {
        int a;
        double b;
        std::string c;

        ComplexType(int a, double b, const std::string& c) : a(a), b(b), c(c) {}
    };

    MemoryResource memRes(1024);
    Stack<ComplexType> complexStack(&memRes);

    complexStack.push({1, 2.5, "Hello"});
    complexStack.push({2, 3.5, "World"});

    complexStack.pop();
    complexStack.pop();
    EXPECT_TRUE(complexStack.empty());
}

TEST(StackTest, IteratorOperations_FirstIteration) {
    MemoryResource memRes(1024);
    Stack<int> intStack(&memRes);

    intStack.push(1);
    intStack.push(2);
    intStack.push(3);

    auto it = intStack.begin();
    EXPECT_EQ(*it, 1);
}

TEST(StackTest, IteratorOperations_SecondIteration) {
    MemoryResource memRes(1024);
    Stack<int> intStack(&memRes);

    intStack.push(1);
    intStack.push(2);
    intStack.push(3);

    auto it = intStack.begin();
    ++it;
    EXPECT_EQ(*it, 2);
}

TEST(StackTest, IteratorOperations_ThirdIteration) {
    MemoryResource memRes(1024);
    Stack<int> intStack(&memRes);

    intStack.push(1);
    intStack.push(2);
    intStack.push(3);

    auto it = intStack.begin();
    ++it;
    ++it;
    EXPECT_EQ(*it, 3);
}

TEST(StackTest, IteratorOperations_EndIteration) {
    MemoryResource memRes(1024);
    Stack<int> intStack(&memRes);

    intStack.push(1);
    intStack.push(2);
    intStack.push(3);

    auto it = intStack.begin();
    ++it;
    ++it;
    ++it;
    EXPECT_EQ(it, intStack.end());
}

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
