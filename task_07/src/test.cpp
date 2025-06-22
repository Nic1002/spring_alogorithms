#include <gtest/gtest.h>
#include "tree.hpp"

TEST(BinarySearchTreeTest, InsertAndContains) {
    BinarySearchTree bst;
    bst.insert(5);
    bst.insert(3);
    bst.insert(7);
    
    ASSERT_TRUE(bst.contains(5));
    ASSERT_TRUE(bst.contains(3));
    ASSERT_TRUE(bst.contains(7));
    ASSERT_FALSE(bst.contains(2));
}

TEST(BinarySearchTreeTest, Remove) {
    BinarySearchTree bst;
    bst.insert(10);
    bst.insert(5);
    bst.insert(15);
    
    bst.remove(5);
    ASSERT_FALSE(bst.contains(5));
    ASSERT_TRUE(bst.contains(10));
    ASSERT_TRUE(bst.contains(15));
    
    bst.remove(10);
    ASSERT_FALSE(bst.contains(10));
    ASSERT_TRUE(bst.contains(15));
}

TEST(BinarySearchTreeTest, SizeAndEmpty) {
    BinarySearchTree bst;
    ASSERT_TRUE(bst.isEmpty());
    ASSERT_EQ(bst.size(), 0);
    
    bst.insert(1);
    bst.insert(2);
    ASSERT_FALSE(bst.isEmpty());
    ASSERT_EQ(bst.size(), 2);
    
    bst.clear();
    ASSERT_TRUE(bst.isEmpty());
    ASSERT_EQ(bst.size(), 0);
}

TEST(BinarySearchTreeTest, MinValue) {
    BinarySearchTree bst;
    bst.insert(8);
    bst.insert(3);
    bst.insert(10);
    bst.insert(1);
    bst.insert(6);
    
    ASSERT_EQ(bst.minValue(), 1);
    
    bst.remove(1);
    ASSERT_EQ(bst.minValue(), 3);
    
    bst.clear();
    ASSERT_THROW(bst.minValue(), std::runtime_error);
}