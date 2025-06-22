#include <gtest/gtest.h>
#include "function.cpp"

TEST(TwoSumTest, PairExistsAtEnds) {
    vector<int> vec = {1, 2, 3, 4, 5};
    auto result = Numbers(6, vec);
    ASSERT_EQ(result.first, 1);
    ASSERT_EQ(result.second, 5);
}

TEST(TwoSumTest, PairExistsAdjacent) {
    vector<int> vec = {1, 3, 4, 7, 9};
    auto result = Numbers(11, vec);
    ASSERT_EQ(result.first, 4);
    ASSERT_EQ(result.second, 7);
}

TEST(TwoSumTest, PairWithSameElements) {
    vector<int> vec = {2, 2, 3, 4, 5};
    auto result = Numbers(4, vec);
    ASSERT_EQ(result.first, 2);
    ASSERT_EQ(result.second, 2);
}

TEST(TwoSumTest, PairAtBeginning) {
    vector<int> vec = {1, 2, 3, 4, 5};
    auto result = Numbers(3, vec);
    ASSERT_EQ(result.first, 1);
    ASSERT_EQ(result.second, 2);
}

TEST(TwoSumTest, NoPairThrowsException) {
    vector<int> vec = {1, 2, 3, 4, 5};
    EXPECT_THROW({
        Numbers(20, vec);
    }, runtime_error);
}

TEST(TwoSumTest, EmptyArrayThrows) {
    vector<int> vec;
    EXPECT_THROW({
        Numbers(10, vec);
    }, runtime_error);
}

TEST(TwoSumTest, SingleElementThrows) {
    vector<int> vec = {5};
    EXPECT_THROW({
        Numbers(5, vec);
    }, runtime_error);
}

TEST(TwoSumTest, TwoElementsValid) {
    vector<int> vec = {3, 7};
    auto result = Numbers(10, vec);
    ASSERT_EQ(result.first, 3);
    ASSERT_EQ(result.second, 7);
}

TEST(TwoSumTest, TwoElementsInvalid) {
    vector<int> vec = {3, 7};
    EXPECT_THROW({
        Numbers(11, vec);
    }, runtime_error);
}

TEST(TwoSumTest, NegativeNumbers) {
    vector<int> vec = {-5, -3, 0, 1, 4};
    auto result = Numbers(-4, vec);
    ASSERT_EQ(result.first, -5);
    ASSERT_EQ(result.second, 1);
}

TEST(TwoSumTest, AllNegativeNumbers) {
    vector<int> vec = {-8, -5, -3, -1};
    auto result = Numbers(-8, vec);
    ASSERT_EQ(result.first, -5);
    ASSERT_EQ(result.second, -3);
}

TEST(TwoSumTest, LargeNumbers) {
    vector<int> vec = {1000000, 2000000, 3000000, 4000000};
    auto result = Numbers(5000000, vec);
    ASSERT_EQ(result.first, 1000000);
    ASSERT_EQ(result.second, 4000000);
}

int main(int argc, char **argv) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}