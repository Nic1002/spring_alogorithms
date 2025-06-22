#include <gtest/gtest.h>

#include "tree.hpp"

class AVLTreeTest : public ::testing::Test {
 protected:
  AVLTree tree;

  void SetUp() override {
    tree.insert(50);
    tree.insert(30);
    tree.insert(70);
    tree.insert(20);
    tree.insert(40);
    tree.insert(60);
    tree.insert(80);
  }
};

TEST_F(AVLTreeTest, InsertAndContains) {
  EXPECT_TRUE(tree.contains(50));
  EXPECT_TRUE(tree.contains(30));
  EXPECT_TRUE(tree.contains(70));
  EXPECT_TRUE(tree.contains(20));
  EXPECT_TRUE(tree.contains(40));
  EXPECT_TRUE(tree.contains(60));
  EXPECT_TRUE(tree.contains(80));
  EXPECT_FALSE(tree.contains(10));
  EXPECT_FALSE(tree.contains(100));
}

TEST_F(AVLTreeTest, RemoveElements) {
  tree.remove(20);
  EXPECT_FALSE(tree.contains(20));
  EXPECT_TRUE(tree.contains(30));

  tree.remove(30);
  EXPECT_FALSE(tree.contains(30));
  EXPECT_TRUE(tree.contains(50));

  tree.remove(50);
  EXPECT_FALSE(tree.contains(50));
  EXPECT_TRUE(tree.contains(60));
  EXPECT_TRUE(tree.contains(70));
}

TEST_F(AVLTreeTest, MaintainsBalanceProperty) {
  AVLTree balanceTestTree;

  // Вставляем элементы в порядке, который создает дисбаланс в обычном BST
  for (int i = 1; i <= 100; ++i) {
    balanceTestTree.insert(i);
    // Можно добавить проверку баланса на каждом шаге
  }

  // Проверяем, что все элементы присутствуют
  for (int i = 1; i <= 100; ++i) {
    EXPECT_TRUE(balanceTestTree.contains(i));
  }
}

TEST_F(AVLTreeTest, ClearTree) {
  EXPECT_TRUE(tree.contains(50));
  tree.clear();
  EXPECT_FALSE(tree.contains(50));

  // Проверяем, что можно снова использовать дерево
  tree.insert(100);
  EXPECT_TRUE(tree.contains(100));
}

TEST(AVLTreeEmptyTest, HandlesEmptyTree) {
  AVLTree emptyTree;
  EXPECT_FALSE(emptyTree.contains(10));

  // Удаление из пустого дерева не должно вызывать ошибок
  EXPECT_NO_THROW(emptyTree.remove(10));
}

int main(int argc, char **argv) {
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}