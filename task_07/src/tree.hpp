#include <algorithm>

struct Node {
    int key;
    Node* left;
    Node* right;
    int height;
};

class AVLTree {
public:
    AVLTree() : root(nullptr) {}
    ~AVLTree() { clear(root); }
    
    void insert(int key) { root = insert(root, key); }
    void remove(int key) { root = remove(root, key); }
    bool contains(int key) const { return contains(root, key); }
    void clear() { clear(root); root = nullptr; }

private:
    Node* root;
    
    Node* insert(Node* node, int key);
    Node* remove(Node* node, int key);
    bool contains(const Node* node, int key) const;
    void clear(Node* node);
    
    // Вспомогательные функции
    int height(Node* node) { return node ? node->height : 0; }
    int balanceFactor(Node* node) { return node ? height(node->left) - height(node->right) : 0; }
    void updateHeight(Node* node) { node->height = 1 + std::max(height(node->left), height(node->right)); }
    
    Node* rotateRight(Node* y);
    Node* rotateLeft(Node* x);
    Node* balance(Node* node);
    Node* findMin(Node* node);
};