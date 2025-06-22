#pragma once
enum class Colour{ Red = 0, Black };

class RedBlackTree {
private:
    struct Node {
        int key;
        Colour colour;
        Node *left_child;
        Node *right_child;
        Node *parent;

        Node(int key, Colour colour, Node *left_child, Node *right_child, Node *parent = nullptr)
            : key(key), colour(colour), left_child(left_child), right_child(right_child), parent(parent) {}

        bool operator!=(const Node &other) const {
            return this->key != other.key;
        }
    };

    Node *root;
    Node *nil;

    bool IsRedBlackTreeValid(Node* node, int blackCount, int& currentBlackCount) const;
    bool Contains(Node* node, int key) const;

    void Transplant(Node* u, Node* v);
    Node* Minimum(Node* node);

    void Clear(Node* node) {
        if (node == nil || node == nullptr) return;
        
        Clear(node->left_child);
        Clear(node->right_child);
        
        if (node != nil) {
            delete node;
        }
    }

public:
    RedBlackTree() {
        nil = new Node(0, Colour::Black, nullptr, nullptr);
        nil->left_child = nil;
        nil->right_child = nil;
        nil->parent = nil;
        root = nil;
    }

    ~RedBlackTree() {
        Clear(root);
        delete nil;
    }

    void Insert(int key);
    void Del(int key);
    void FixInsert(Node *z);
    void FixDel(Node *x);
    void LeftRotate(Node *x);
    void RightRotate(Node *y);
    Node* Search(int key);

    bool Contains(int key) const;
    bool IsValid() const;
};