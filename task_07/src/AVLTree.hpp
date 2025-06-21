#pragma once

#include <iostream>

struct Node {
  int key;
  Node* left;
  Node* right;
  int height;
  Node(int k) : key(k), left(nullptr), right(nullptr), height(1) {}
};

class AVLTree {
 private:
  Node* root = nullptr;

  int height(Node* n) { return n ? n->height : 0; }

  int balanceFactor(Node* n) {
    return n ? height(n->left) - height(n->right) : 0;
  }

  void updateHeight(Node* n) {
    n->height = 1 + std::max(height(n->left), height(n->right));
  }

  Node* rotateRight(Node* y);
  Node* rotateLeft(Node* x);
  Node* balance(Node* n);
  Node* insert(Node* node, int key);
  Node* minValueNode(Node* node);
  Node* erase(Node* node, int key);
  bool find(Node* node, int key) const;
  void inorder(Node* node) const;

 public:
  void insert(int key) { root = insert(root, key); }

  void erase(int key) { root = erase(root, key); }

  bool find(int key) const { return find(root, key); }

  void printInorder() const {
    inorder(root);
    std::cout << "\n";
  }
};