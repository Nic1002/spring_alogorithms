#include <gtest/gtest.h>
#include "stack.cpp"

TEST(MyStackTest, IsEmptyInitially) {
    MyStack stack;
    EXPECT_TRUE(stack.empty());
}

TEST(MyStackTest, PushAndTop) {
    MyStack stack;
    stack.push(1);
    EXPECT_EQ(stack.top(), 1);
    stack.push(2);
    EXPECT_EQ(stack.top(), 2);
}

TEST(MyStackTest, PushAndPop) {
    MyStack stack;
    stack.push(1);
    stack.push(2);
    EXPECT_EQ(stack.pop(), 2);
    EXPECT_EQ(stack.pop(), 1);
    EXPECT_TRUE(stack.empty());
}

TEST(MyStackTest, PopEmptyThrows) {
    MyStack stack;
    EXPECT_THROW(stack.pop(), std::out_of_range);
}

TEST(MyStackTest, TopEmptyThrows) {
    MyStack stack;
    EXPECT_THROW(stack.top(), std::out_of_range);
}

TEST(MyStackTest, ResizeOnPush) {
    MyStack stack;
    for (int i = 0; i < 20; ++i) {
        stack.push(i);
    }
    EXPECT_EQ(stack.top(), 19);
}

TEST(MinStackTest, EmptyStack) {
    MinStack stack;
    EXPECT_TRUE(stack.empty());
    EXPECT_THROW(stack.getMin(), std::out_of_range);
}

TEST(MinStackTest, SingleElement) {
    MinStack stack;
    stack.push(5);
    EXPECT_EQ(stack.getMin(), 5);
}

TEST(MinStackTest, TwoElements) {
    MinStack stack;
    stack.push(5);
    stack.push(3);
    EXPECT_EQ(stack.getMin(), 3);
    stack.pop();
    EXPECT_EQ(stack.getMin(), 5);
}

TEST(MinStackTest, DuplicateMin) {
    MinStack stack;
    stack.push(4);
    stack.push(4);
    EXPECT_EQ(stack.getMin(), 4);
    stack.pop();
    EXPECT_EQ(stack.getMin(), 4);
}

TEST(MinStackTest, MultipleOperations) {
    MinStack stack;
    stack.push(3);
    stack.push(5);
    EXPECT_EQ(stack.getMin(), 3);
    stack.push(2);
    stack.push(1);
    EXPECT_EQ(stack.getMin(), 1);
    stack.pop();
    EXPECT_EQ(stack.getMin(), 2);
    stack.pop();
    EXPECT_EQ(stack.getMin(), 3);
}

TEST(MinStackTest, ComplexSequence) {
    MinStack stack;
    stack.push(10);
    stack.push(20);
    stack.push(5);
    stack.push(5);
    stack.push(15);
    EXPECT_EQ(stack.getMin(), 5);
    stack.pop();
    EXPECT_EQ(stack.getMin(), 5);
    stack.pop();
    EXPECT_EQ(stack.getMin(), 5);
    stack.pop();
    EXPECT_EQ(stack.getMin(), 10);
}

TEST(MinStackTest, PopEmptyThrows) {
    MinStack stack;
    EXPECT_THROW(stack.pop(), std::out_of_range);
}

TEST(MinStackTest, TopEmptyThrows) {
    MinStack stack;
    EXPECT_THROW(stack.top(), std::out_of_range);
}

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}