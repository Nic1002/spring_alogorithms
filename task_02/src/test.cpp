#include <gtest/gtest.h>

#include "stack.hpp"

TEST(StackTest, PushPopPeek) {
  Stack s;
  s.Push(10);
  s.Push(20);
  EXPECT_EQ(s.peek(), 20);
  s.pop();
  EXPECT_EQ(s.peek(), 10);
}

TEST(StackTest, PopEmptyStack) {
  Stack s;
  EXPECT_THROW(s.pop(), std::out_of_range);
}

TEST(StackTest, PeekEmptyStack) {
  Stack s;
  EXPECT_THROW(s.peek(), std::out_of_range);
}

TEST(StackTest, MinElement) {
  Stack s;
  s.Push(5);
  s.Push(2);
  s.Push(7);
  s.Push(1);
  EXPECT_EQ(s.min(), 1);
  s.pop();
  EXPECT_EQ(s.min(), 2);
}

TEST(StackTest, MinEmptyStack) {
  Stack s;
  EXPECT_THROW(s.min(), std::out_of_range);
}

TEST(StackTest, DisplayEmpty) {
  Stack s;
  testing::internal::CaptureStdout();
  s.display();
  std::string output = testing::internal::GetCapturedStdout();
  EXPECT_EQ(output, "Stack is empty.\n");
}

TEST(StackTest, DisplayNonEmpty) {
  Stack s;
  s.Push(1);
  s.Push(2);
  s.Push(3);
  testing::internal::CaptureStdout();
  s.display();
  std::string output = testing::internal::GetCapturedStdout();
  EXPECT_TRUE(output == "1 2 3 \n" || output == "1 2 3\n");
}

TEST(StackTest, MultipleOperations) {
  Stack s;
  s.Push(10);
  s.Push(5);
  s.Push(15);
  EXPECT_EQ(s.min(), 5);
  s.pop();
  s.Push(3);
  EXPECT_EQ(s.peek(), 3);
  EXPECT_EQ(s.min(), 3);
}