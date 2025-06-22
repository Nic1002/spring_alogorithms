#include <gtest/gtest.h>
#include "RB_Tree.cpp"

TEST(RedBlackTreeTest, InsertAndSearch) {
    RedBlackTree tree;
    tree.InsertKey(10);
    tree.InsertKey(20);
    tree.InsertKey(5);
    
    EXPECT_TRUE(tree.Search(10));
    EXPECT_TRUE(tree.Search(20));
    EXPECT_TRUE(tree.Search(5));
    EXPECT_FALSE(tree.Search(15));
}

TEST(RedBlackTreeTest, DeleteLeafNode) {
    RedBlackTree tree;
    tree.InsertKey(10);
    tree.InsertKey(20);
    tree.InsertKey(5);
    
    tree.DeleteKey(5);
    EXPECT_FALSE(tree.Search(5));
    EXPECT_TRUE(tree.Search(10));
    EXPECT_TRUE(tree.Search(20));
}

TEST(RedBlackTreeTest, DeleteRootNode) {
    RedBlackTree tree;
    tree.InsertKey(10);
    tree.InsertKey(20);
    tree.InsertKey(5);
    
    tree.DeleteKey(10);
    EXPECT_FALSE(tree.Search(10));
    EXPECT_TRUE(tree.Search(20));
    EXPECT_TRUE(tree.Search(5));
}

TEST(RedBlackTreeTest, MinimumAndMaximum) {
    RedBlackTree tree;
    tree.InsertKey(10);
    tree.InsertKey(20);
    tree.InsertKey(5);
    tree.InsertKey(15);
    tree.InsertKey(25);
    
    EXPECT_EQ(tree.GetMinimum(), 5);
    EXPECT_EQ(tree.GetMaximum(), 25);
}

TEST(RedBlackTreeTest, Successor) {
    RedBlackTree tree;
    tree.InsertKey(10);
    tree.InsertKey(20);
    tree.InsertKey(5);
    tree.InsertKey(15);
    tree.InsertKey(25);
    
    EXPECT_EQ(tree.FindSuccessor(10), 15);
    EXPECT_EQ(tree.FindSuccessor(15), 20);
    EXPECT_EQ(tree.FindSuccessor(20), 25);
}

TEST(RedBlackTreeTest, Predecessor) {
    RedBlackTree tree;
    tree.InsertKey(10);
    tree.InsertKey(20);
    tree.InsertKey(5);
    tree.InsertKey(15);
    tree.InsertKey(25);
    
    EXPECT_EQ(tree.FindPredecessor(10), 5);
    EXPECT_EQ(tree.FindPredecessor(15), 10);
    EXPECT_EQ(tree.FindPredecessor(20), 15);
}

TEST(RedBlackTreeTest, EmptyTree) {
    RedBlackTree tree;
    EXPECT_FALSE(tree.Search(10));
}

TEST(RedBlackTreeTest, LargeInsertDelete) {
    RedBlackTree tree;
    
    for (int i = 0; i < 100; ++i) {
        tree.InsertKey(i);
    }
    
    for (int i = 0; i < 100; i += 2) {
        tree.DeleteKey(i);
    }
    
    for (int i = 0; i < 100; ++i) {
        if (i % 2 == 0) {
            EXPECT_FALSE(tree.Search(i));
        } else {
            EXPECT_TRUE(tree.Search(i));
        }
    }
}

TEST(RedBlackTreeTest, ComplexSequence) {
    RedBlackTree tree;
    
    tree.InsertKey(50);
    tree.InsertKey(30);
    tree.InsertKey(70);
    tree.InsertKey(20);
    tree.InsertKey(40);
    tree.InsertKey(60);
    tree.InsertKey(80);
    
    EXPECT_EQ(tree.GetMinimum(), 20);
    EXPECT_EQ(tree.GetMaximum(), 80);
    EXPECT_EQ(tree.FindSuccessor(50), 60);
    EXPECT_EQ(tree.FindPredecessor(50), 40);
    
    tree.DeleteKey(50);
    EXPECT_FALSE(tree.Search(50));
    EXPECT_EQ(tree.GetMinimum(), 20);
    EXPECT_EQ(tree.GetMaximum(), 80);
    
    tree.DeleteKey(20);
    EXPECT_FALSE(tree.Search(20));
    EXPECT_EQ(tree.GetMinimum(), 30);
    
    tree.DeleteKey(70);
    EXPECT_FALSE(tree.Search(70));
    EXPECT_EQ(tree.FindSuccessor(60), 80);
    
    tree.DeleteKey(30);
    tree.DeleteKey(40);
    tree.DeleteKey(60);
    tree.DeleteKey(80);
}

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
