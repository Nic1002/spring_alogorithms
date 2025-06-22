#include "tree.hpp"

BinarySearchTree::BinarySearchTree() : root(nullptr) {}

void BinarySearchTree::insert(int key) { insert(root, key); }

void BinarySearchTree::insert(std::unique_ptr<Node>& node, int key) {
  if (!node) {
    node = std::make_unique<Node>(key);
  } else if (key < node->key) {
    insert(node->left, key);
  } else if (key > node->key) {
    insert(node->right, key);
  }
}

bool BinarySearchTree::contains(int key) const { return contains(root, key); }

bool BinarySearchTree::contains(const std::unique_ptr<Node>& node,
                                int key) const {
  if (!node) return false;
  if (key == node->key) return true;
  return key < node->key ? contains(node->left, key)
                         : contains(node->right, key);
}

void BinarySearchTree::remove(int key) { remove(root, key); }

void BinarySearchTree::remove(std::unique_ptr<Node>& node, int key) {
  if (!node) return;

  if (key < node->key) {
    remove(node->left, key);
  } else if (key > node->key) {
    remove(node->right, key);
  } else {
    if (!node->left && !node->right) {
      node.reset();
    } else if (!node->left) {
      node = std::move(node->right);
    } else if (!node->right) {
      node = std::move(node->left);
    } else {
      node->key = minValue(node->right);
      remove(node->right, node->key);
    }
  }
}

int BinarySearchTree::minValue() const {
  if (!root) throw std::runtime_error("Tree is empty");
  return minValue(root);
}

int BinarySearchTree::minValue(const std::unique_ptr<Node>& node) const {
  return node->left ? minValue(node->left) : node->key;
}

void BinarySearchTree::clear() { root.reset(); }

size_t BinarySearchTree::size() const { return size(root); }

size_t BinarySearchTree::size(const std::unique_ptr<Node>& node) const {
  return node ? 1 + size(node->left) + size(node->right) : 0;
}

bool BinarySearchTree::isEmpty() const { return !root; }