#include <gtest/gtest.h>
#include "function.cpp"

TEST(NumberTest, FindPair) {
std::vector<int> numbers = {1, 4, 6, 2, 5, 3};
int target{10};
auto result = Numbers(target, numbers);
EXPECT_EQ(result.first, 4);
EXPECT_EQ(result.second, 6);
}

TEST(NumberTest, NoPairFound) {
std::vector<int> numbers = {1, 2, 3, 4, 5};
int target{10};
EXPECT_THROW(Numbers(target, numbers), std::runtime_error);
}

TEST(NumberTest, PairAtEnds) {
std::vector<int> numbers = {1, 2, 3, 7, 8};
int target{9};
auto result = Numbers(target, numbers);
EXPECT_EQ(result.first, 1);
EXPECT_EQ(result.second, 8);
}

TEST(NumberTest, PairWithNegativeNumbers) {
std::vector<int> numbers = {-5, -2, 0, 2, 5};
int target{0};
auto result = Numbers(target, numbers);
EXPECT_EQ(result.first, -5);
EXPECT_EQ(result.second, 5);
}

TEST(NumberTest, DuplicateNumbers) {
std::vector<int> numbers = {1, 1, 2, 3, 4};
int target{2};
auto result = Numbers(target, numbers);
EXPECT_EQ(result.first, 1);
EXPECT_EQ(result.second, 1);
}

int main(int argc, char **argv) {
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}