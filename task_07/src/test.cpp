#include <gtest/gtest.h>
#include "RB_Tree.cpp"

TEST(RedBlackTreeTest, InsertAndSearch) {
    RedBlackTree tree;
    EXPECT_FALSE(tree.Search(10));
    
    tree.InsertKey(10);
    EXPECT_TRUE(tree.Search(10));
    EXPECT_TRUE(tree.CheckRBProperties());
    
    tree.InsertKey(20);
    tree.InsertKey(5);
    EXPECT_TRUE(tree.Search(20));
    EXPECT_TRUE(tree.Search(5));
    EXPECT_TRUE(tree.CheckRBProperties());
}

TEST(RedBlackTreeTest, DeleteKey) {
    RedBlackTree tree;
    tree.InsertKey(10);
    tree.InsertKey(20);
    tree.InsertKey(5);
    tree.InsertKey(15);
    tree.InsertKey(25);
    
    tree.DeleteKey(20);
    EXPECT_FALSE(tree.Search(20));
    EXPECT_TRUE(tree.CheckRBProperties());
    
    tree.DeleteKey(10);
    EXPECT_FALSE(tree.Search(10));
    EXPECT_TRUE(tree.CheckRBProperties());
    
    tree.DeleteKey(5);
    EXPECT_FALSE(tree.Search(5));
    EXPECT_TRUE(tree.CheckRBProperties());
}

TEST(RedBlackTreeTest, MinMaxOperations) {
    RedBlackTree tree;
    EXPECT_THROW(tree.GetMinimum(), std::runtime_error);
    EXPECT_THROW(tree.GetMaximum(), std::runtime_error);
    
    tree.InsertKey(10);
    tree.InsertKey(20);
    tree.InsertKey(5);
    tree.InsertKey(15);
    tree.InsertKey(25);
    
    EXPECT_EQ(tree.GetMinimum(), 5);
    EXPECT_EQ(tree.GetMaximum(), 25);
    
    tree.DeleteKey(5);
    EXPECT_EQ(tree.GetMinimum(), 10);
    
    tree.DeleteKey(25);
    EXPECT_EQ(tree.GetMaximum(), 20);
}

TEST(RedBlackTreeTest, SuccessorPredecessor) {
    RedBlackTree tree;
    tree.InsertKey(10);
    tree.InsertKey(20);
    tree.InsertKey(5);
    tree.InsertKey(15);
    tree.InsertKey(25);
    
    EXPECT_EQ(tree.FindSuccessor(10), 15);
    EXPECT_EQ(tree.FindSuccessor(15), 20);
    EXPECT_EQ(tree.FindSuccessor(20), 25);
    EXPECT_THROW(tree.FindSuccessor(25), std::runtime_error);
    
    EXPECT_EQ(tree.FindPredecessor(20), 15);
    EXPECT_EQ(tree.FindPredecessor(15), 10);
    EXPECT_EQ(tree.FindPredecessor(10), 5);
    EXPECT_THROW(tree.FindPredecessor(5), std::runtime_error);
}

TEST(RedBlackTreeTest, RBPropertiesAfterOperations) {
    RedBlackTree tree;
    
    for (int i = 0; i < 100; i++) {
        tree.InsertKey(rand() % 1000);
        EXPECT_TRUE(tree.CheckRBProperties());
    }
    
    for (int i = 0; i < 50; i++) {
        int key = rand() % 1000;
        if (tree.Search(key)) {
            tree.DeleteKey(key);
            EXPECT_TRUE(tree.CheckRBProperties());
        }
    }
}

TEST(RedBlackTreeTest, SpecialCases) {
    RedBlackTree tree;
    
    tree.InsertKey(10);
    tree.InsertKey(10);
    EXPECT_TRUE(tree.Search(10));
    EXPECT_TRUE(tree.CheckRBProperties());
    
    tree.DeleteKey(999);
    EXPECT_TRUE(tree.CheckRBProperties());
    
    tree.DeleteKey(10);
    tree.DeleteKey(10);
    EXPECT_FALSE(tree.Search(10));
    EXPECT_THROW(tree.GetMinimum(), std::runtime_error);
}

TEST(RedBlackTreeTest, SortedInsert) {
    RedBlackTree tree;
    
    for (int i = 1; i <= 100; i++) {
        tree.InsertKey(i);
        EXPECT_TRUE(tree.CheckRBProperties());
    }
    
    RedBlackTree tree2;
    for (int i = 100; i >= 1; i--) {
        tree2.InsertKey(i);
        EXPECT_TRUE(tree2.CheckRBProperties());
    }
}

int main(int argc, char **argv) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}