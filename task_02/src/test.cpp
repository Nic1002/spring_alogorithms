#include <gtest/gtest.h>

#include "stack.cpp"

TEST(MinStackTest, EmptyStack) {
  MinStack stack;
  EXPECT_TRUE(stack.empty());
  EXPECT_THROW(stack.getMin(), std::out_of_range);
  EXPECT_THROW(stack.top(), std::out_of_range);
  EXPECT_THROW(stack.pop(), std::out_of_range);
}

TEST(MinStackTest, SingleElement) {
  MinStack stack;
  stack.push(5);
  EXPECT_FALSE(stack.empty());
  EXPECT_EQ(stack.getMin(), 5);
  EXPECT_EQ(stack.top(), 5);

  stack.pop();
  EXPECT_TRUE(stack.empty());
}

TEST(MinStackTest, MultipleElements) {
  MinStack stack;
  stack.push(5);
  stack.push(3);
  stack.push(4);

  EXPECT_EQ(stack.getMin(), 3);
  EXPECT_EQ(stack.top(), 4);

  stack.pop();
  EXPECT_EQ(stack.getMin(), 3);
  EXPECT_EQ(stack.top(), 3);

  stack.pop();
  EXPECT_EQ(stack.getMin(), 5);
  EXPECT_EQ(stack.top(), 5);
}

TEST(MinStackTest, DuplicateMins) {
  MinStack stack;
  stack.push(4);
  stack.push(2);
  stack.push(2);
  stack.push(3);

  EXPECT_EQ(stack.getMin(), 2);
  stack.pop();
  EXPECT_EQ(stack.getMin(), 2);

  stack.pop();
  EXPECT_EQ(stack.getMin(), 2);

  stack.pop();
  EXPECT_EQ(stack.getMin(), 4);
}

TEST(MinStackTest, ComplexSequence) {
  MinStack stack;
  stack.push(10);
  stack.push(20);
  stack.push(5);
  stack.push(5);
  stack.push(15);

  EXPECT_EQ(stack.getMin(), 5);
  stack.pop();  // 15
  EXPECT_EQ(stack.getMin(), 5);
  stack.pop();  // 5
  EXPECT_EQ(stack.getMin(), 5);
  stack.pop();  // 5
  EXPECT_EQ(stack.getMin(), 10);
  stack.pop();  // 20
  EXPECT_EQ(stack.getMin(), 10);
}

int main(int argc, char** argv) {
  testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}