#include <vector>
#include <gtest/gtest.h>
#include "solution.hpp"

class TwoSumTest : public ::testing::Test {
protected:
    void SetUp() override {}
    void TearDown() override {}
};

TEST_F(TwoSumTest, BasicCase) {
    vector<int> nums = {2, 7, 11, 15};
    int target = 9;
    Result res = Solve(nums.size(), target, nums);

    EXPECT_TRUE(res.finded);
    EXPECT_EQ(res.left, 2);
    EXPECT_EQ(res.right, 7);
}

TEST_F(TwoSumTest, NoSolution) {
    vector<int> nums = {1, 2, 3, 4};
    int target = 8;
    Result res = Solve(nums.size(), target, nums);

    EXPECT_FALSE(res.finded);
}

TEST_F(TwoSumTest, AllElementsSame) {
    vector<int> nums = {5, 5, 5, 5};
    int target = 10;
    Result res = Solve(nums.size(), target, nums);

    EXPECT_TRUE(res.finded);
    EXPECT_EQ(res.left, 5);
    EXPECT_EQ(res.right, 5);
}

TEST_F(TwoSumTest, NegativeNumbers) {
    vector<int> nums = {-5, -3, 0, 1, 4};
    int target = -2;
    Result res = Solve(nums.size(), target, nums);

    EXPECT_TRUE(res.finded);
    EXPECT_EQ(res.left, -3);
    EXPECT_EQ(res.right, 1);
}

TEST_F(TwoSumTest, EmptyArray) {
    vector<int> nums = {};
    int target = 5;
    Result res = Solve(nums.size(), target, nums);

    EXPECT_FALSE(res.finded);
}

TEST_F(TwoSumTest, SingleElementArray) {
    vector<int> nums = {5};
    int target = 5;
    Result res = Solve(nums.size(), target, nums);

    EXPECT_FALSE(res.finded);
}

TEST_F(TwoSumTest, TargetTooSmall) {
    vector<int> nums = {10, 20, 30};
    int target = 5;
    Result res = Solve(nums.size(), target, nums);

    EXPECT_FALSE(res.finded);
}

TEST_F(TwoSumTest, TargetTooLarge) {
    vector<int> nums = {1, 2, 3};
    int target = 10;
    Result res = Solve(nums.size(), target, nums);

    EXPECT_FALSE(res.finded);
}

TEST_F(TwoSumTest, MultipleSolutions) {
    vector<int> nums = {1, 2, 3, 4, 5, 6};
    int target = 7;
    Result res = Solve(nums.size(), target, nums);

    EXPECT_TRUE(res.finded);
    EXPECT_EQ(res.left + res.right, target);  
}

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}