#include "tree.hpp"

Node* AVLTree::insert(Node* node, int key) {
    if (!node) return new Node{key, nullptr, nullptr, 1};
    
    if (key < node->key)
        node->left = insert(node->left, key);
    else if (key > node->key)
        node->right = insert(node->right, key);
    else
        return node; // Дубликаты не допускаем
    
    return balance(node);
}

Node* AVLTree::remove(Node* node, int key) {
    if (!node) return nullptr;
    
    if (key < node->key)
        node->left = remove(node->left, key);
    else if (key > node->key)
        node->right = remove(node->right, key);
    else {
        if (!node->left || !node->right) {
            Node* temp = node->left ? node->left : node->right;
            delete node;
            return temp;
        }
        Node* temp = findMin(node->right);
        node->key = temp->key;
        node->right = remove(node->right, temp->key);
    }
    return balance(node);
}

bool AVLTree::contains(const Node* node, int key) const {
    if (!node) return false;
    if (key == node->key) return true;
    return key < node->key ? contains(node->left, key) : contains(node->right, key);
}

void AVLTree::clear(Node* node) {
    if (node) {
        clear(node->left);
        clear(node->right);
        delete node;
    }
}

Node* AVLTree::rotateRight(Node* y) {
    Node* x = y->left;
    y->left = x->right;
    x->right = y;
    updateHeight(y);
    updateHeight(x);
    return x;
}

Node* AVLTree::rotateLeft(Node* x) {
    Node* y = x->right;
    x->right = y->left;
    y->left = x;
    updateHeight(x);
    updateHeight(y);
    return y;
}

Node* AVLTree::balance(Node* node) {
    updateHeight(node);
    int bf = balanceFactor(node);
    
    if (bf > 1) {
        if (balanceFactor(node->left) < 0)
            node->left = rotateLeft(node->left);
        return rotateRight(node);
    }
    if (bf < -1) {
        if (balanceFactor(node->right) > 0)
            node->right = rotateRight(node->right);
        return rotateLeft(node);
    }
    return node;
}

Node* AVLTree::findMin(Node* node) {
    while (node && node->left) node = node->left;
    return node;
}