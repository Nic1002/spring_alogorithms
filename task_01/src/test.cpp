#include <gtest/gtest.h>
#include <vector>

#include "task1.hpp"

TEST(FindNumberOfSummaTest, SimpleCase) {
    std::vector<int> vec = {1, 2, 3, 4, 5};
    int summa = 8;
    std::vector<int> expected = {3, 5};
    ASSERT_EQ(FindNumberOfSumma(vec, summa), expected);
}

TEST(FindNumberOfSummaTest, FirstAndLastElements) {
    std::vector<int> vec = {1, 2, 3, 4, 5};
    int summa = 6;
    std::vector<int> expected = {1, 5};
    ASSERT_EQ(FindNumberOfSumma(vec, summa), expected);
}

TEST(FindNumberOfSummaTest, NoPairFound) {
    std::vector<int> vec = {1, 2, 3, 4, 5};
    int summa = 10;
    EXPECT_THROW(FindNumberOfSumma(vec, summa), std::runtime_error);
}

TEST(FindNumberOfSummaTest, EmptyVector) {
    std::vector<int> vec;
    int summa = 5;
    EXPECT_THROW(FindNumberOfSumma(vec, summa), std::runtime_error);
}
