#include <gtest/gtest.h>
#include "red_black_tree.hpp"

class RedBlackTreeTest : public ::testing::Test {
protected:
    RedBlackTree tree;

    void SetUp() override {}
    void TearDown() override {}
};

TEST_F(RedBlackTreeTest, InsertMaintainsRedBlackProperties) {
    tree.Insert(10);
    tree.Insert(20);
    tree.Insert(5);
    EXPECT_TRUE(tree.IsValid());
}

TEST_F(RedBlackTreeTest, ContainsReturnsCorrectResults) {
    tree.Insert(10);
    tree.Insert(20);
    tree.Insert(5);

    EXPECT_TRUE(tree.Contains(10));
    EXPECT_TRUE(tree.Contains(20));
    EXPECT_TRUE(tree.Contains(5));
    EXPECT_FALSE(tree.Contains(15));
}

TEST_F(RedBlackTreeTest, DeleteMaintainsRedBlackProperties) {
    tree.Insert(10);
    tree.Insert(20);
    tree.Insert(5);
    tree.Insert(15);

    tree.Del(15);
    EXPECT_FALSE(tree.Contains(15));
    EXPECT_TRUE(tree.IsValid());

    tree.Del(10);
    EXPECT_FALSE(tree.Contains(10));
    EXPECT_TRUE(tree.IsValid());
}

TEST_F(RedBlackTreeTest, EmptyTreeIsValid) {
    EXPECT_TRUE(tree.IsValid());
    EXPECT_FALSE(tree.Contains(10));
}

TEST_F(RedBlackTreeTest, HandlesDuplicateInsertions) {
    tree.Insert(10);
    tree.Insert(10);
    EXPECT_TRUE(tree.IsValid());
    EXPECT_TRUE(tree.Contains(10));
}

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}