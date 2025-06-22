#include "RB_Tree.hpp"

class RedBlackTree {
private:
    enum Colour { RED, BLACK };

    struct Node {
        int key;
        Colour colour;
        Node* left_child;
        Node* right_child;
        Node* parent;

        Node(int k, Colour c = RED, Node* l = nullptr, Node* r = nullptr, Node* p = nullptr) 
            : key(k), colour(c), left_child(l), right_child(r), parent(p) {}
    };

    Node* root;
    Node* nil;

    void DeleteTree(Node* knot) {
        if (knot != nil) {
            DeleteTree(knot->left_child);
            DeleteTree(knot->right_child);
            delete knot;
        }
    }

    void LeftRotate(Node* x) {
        Node* y = x->right_child;
        x->right_child = y->left_child;
        
        if (y->left_child != nil) {
            y->left_child->parent = x;
        }
        
        y->parent = x->parent;
        
        if (x->parent == nil) {
            root = y;
        } else if (x == x->parent->left_child) {
            x->parent->left_child = y;
        } else {
            x->parent->right_child = y;
        }
        
        y->left_child = x;
        x->parent = y;
    }

    void RightRotate(Node* x) {
        Node* y = x->left_child;
        x->left_child = y->right_child;
        
        if (y->right_child != nil) {
            y->right_child->parent = x;
        }
        
        y->parent = x->parent;
        
        if (x->parent == nil) {
            root = y;
        } else if (x == x->parent->right_child) {
            x->parent->right_child = y;
        } else {
            x->parent->left_child = y;
        }
        
        y->right_child = x;
        x->parent = y;
    }

    void Transplant(Node* u, Node* v) {
        if (u->parent == nil) {
            root = v;
        } else if (u == u->parent->left_child) {
            u->parent->left_child = v;
        } else {
            u->parent->right_child = v;
        }
        v->parent = u->parent;
    }

    void FixInsert(Node* z) {
        while (z->parent->colour == RED) {
            if (z->parent == z->parent->parent->left_child) {
                Node* y = z->parent->parent->right_child;
                if (y->colour == RED) {
                    z->parent->colour = BLACK;
                    y->colour = BLACK;
                    z->parent->parent->colour = RED;
                    z = z->parent->parent;
                } else {
                    if (z == z->parent->right_child) {
                        z = z->parent;
                        LeftRotate(z);
                    }
                    z->parent->colour = BLACK;
                    z->parent->parent->colour = RED;
                    RightRotate(z->parent->parent);
                }
            } else {
                Node* y = z->parent->parent->left_child;
                if (y->colour == RED) {
                    z->parent->colour = BLACK;
                    y->colour = BLACK;
                    z->parent->parent->colour = RED;
                    z = z->parent->parent;
                } else {
                    if (z == z->parent->left_child) {
                        z = z->parent;
                        RightRotate(z);
                    }
                    z->parent->colour = BLACK;
                    z->parent->parent->colour = RED;
                    LeftRotate(z->parent->parent);
                }
            }
        }
        root->colour = BLACK;
    }

    void FixDelete(Node* x) {
        while (x != root && x->colour == BLACK) {
            if (x == x->parent->left_child) {
                Node* w = x->parent->right_child;
                if (w->colour == RED) {
                    w->colour = BLACK;
                    x->parent->colour = RED;
                    LeftRotate(x->parent);
                    w = x->parent->right_child;
                }
                if (w->left_child->colour == BLACK && w->right_child->colour == BLACK) {
                    w->colour = RED;
                    x = x->parent;
                } else {
                    if (w->right_child->colour == BLACK) {
                        w->left_child->colour = BLACK;
                        w->colour = RED;
                        RightRotate(w);
                        w = x->parent->right_child;
                    }
                    w->colour = x->parent->colour;
                    x->parent->colour = BLACK;
                    w->right_child->colour = BLACK;
                    LeftRotate(x->parent);
                    x = root;
                }
            } else {
                Node* w = x->parent->left_child;
                if (w->colour == RED) {
                    w->colour = BLACK;
                    x->parent->colour = RED;
                    RightRotate(x->parent);
                    w = x->parent->left_child;
                }
                if (w->right_child->colour == BLACK && w->left_child->colour == BLACK) {
                    w->colour = RED;
                    x = x->parent;
                } else {
                    if (w->left_child->colour == BLACK) {
                        w->right_child->colour = BLACK;
                        w->colour = RED;
                        LeftRotate(w);
                        w = x->parent->left_child;
                    }
                    w->colour = x->parent->colour;
                    x->parent->colour = BLACK;
                    w->left_child->colour = BLACK;
                    RightRotate(x->parent);
                    x = root;
                }
            }
        }
        x->colour = BLACK;
    }

    Node* GetMinimum(Node* knot) {
        while (knot->left_child != nil) {
            knot = knot->left_child;
        }
        return knot;
    }

    Node* GetMaximum(Node* knot) {
        while (knot->right_child != nil) {
            knot = knot->right_child;
        }
        return knot;
    }

    Node* FindSuccessor(Node* knot) {
        if (knot->right_child != nil) {
            return GetMinimum(knot->right_child);
        }
        Node* y = knot->parent;
        while (y != nil && knot == y->right_child) {
            knot = y;
            y = y->parent;
        }
        return y;
    }

    Node* FindPredecessor(Node* knot) {
        if (knot->left_child != nil) {
            return GetMaximum(knot->left_child);
        }
        Node* y = knot->parent;
        while (y != nil && knot == y->left_child) {
            knot = y;
            y = y->parent;
        }
        return y;
    }

    int CheckBlackHeight(Node* knot) {
        if (knot == nil) return 1;
        
        int leftHeight = CheckBlackHeight(knot->left_child);
        int rightHeight = CheckBlackHeight(knot->right_child);
        
        if (leftHeight == -1 || rightHeight == -1 || leftHeight != rightHeight) {
            return -1;
        }
        
        return leftHeight + (knot->colour == BLACK ? 1 : 0);
    }

public:
    void InsertKey(int key) {
        Node* z = new Node(key, RED, nil, nil, nil);
        Node* y = nil;
        Node* x = root;
        
        while (x != nil) {
            y = x;
            if (z->key < x->key) {
                x = x->left_child;
            } else {
                x = x->right_child;
            }
        }
        
        z->parent = y;
        if (y == nil) {
            root = z;
        } else if (z->key < y->key) {
            y->left_child = z;
        } else {
            y->right_child = z;
        }
        
        FixInsert(z);
    }

    void DeleteKey(int key) {
        Node* z = root;
        while (z != nil && z->key != key) {
            if (key < z->key) {
                z = z->left_child;
            } else {
                z = z->right_child;
            }
        }
        
        if (z == nil) return;
        
        Node* y = z;
        Colour original_color = y->colour;
        Node* x;
        
        if (z->left_child == nil) {
            x = z->right_child;
            Transplant(z, z->right_child);
        } else if (z->right_child == nil) {
            x = z->left_child;
            Transplant(z, z->left_child);
        } else {
            y = GetMinimum(z->right_child);
            original_color = y->colour;
            x = y->right_child;
            
            if (y->parent == z) {
                x->parent = y;
            } else {
                Transplant(y, y->right_child);
                y->right_child = z->right_child;
                y->right_child->parent = y;
            }
            
            Transplant(z, y);
            y->left_child = z->left_child;
            y->left_child->parent = y;
            y->colour = z->colour;
        }
        
        delete z;
        
        if (original_color == BLACK) {
            FixDelete(x);
        }
    }

    bool Search(int key) {
        Node* current = root;
        while (current != nil) {
            if (key == current->key) {
                return true;
            } else if (key < current->key) {
                current = current->left_child;
            } else {
                current = current->right_child;
            }
        }
        return false;
    }
    
    int GetMinimum() {
        if (root == nil) {
            throw runtime_error("Tree is empty");
        }
        return GetMinimum(root)->key;
    }

    int GetMaximum() {
        if (root == nil) {
            throw runtime_error("Tree is empty");
        }
        return GetMaximum(root)->key;
    }

    int FindSuccessor(int key) {
        Node* current = root;
        while (current != nil && current->key != key) {
            if (key < current->key) {
                current = current->left_child;
            } else {
                current = current->right_child;
            }
        }
        
        if (current == nil) {
            throw runtime_error("Key not found");
        }
        
        Node* succ = FindSuccessor(current);
        if (succ == nil) {
            throw runtime_error("No successor exists");
        }
        return succ->key;
    }

    int FindPredecessor(int key) {
        Node* current = root;
        while (current != nil && current->key != key) {
            if (key < current->key) {
                current = current->left_child;
            } else {
                current = current->right_child;
            }
        }
        
        if (current == nil) {
            throw runtime_error("Key not found");
        }
        
        Node* pred = FindPredecessor(current);
        if (pred == nil) {
            throw runtime_error("No predecessor exists");
        }
        return pred->key;
    }

    bool CheckRBProperties() {
        if (root == nil) return true;
        
        // Property 1: Root is black
        if (root->colour != BLACK) {
            return false;
        }
        
        // Property 2: Both children of red node are black
        stack<Node*> s;
        s.push(root);
        while (!s.empty()) {
            Node* current = s.top();
            s.pop();
            
            if (current->colour == RED) {
                if (current->left_child->colour == RED || 
                    current->right_child->colour == RED) {
                    return false;
                }
            }
            
            if (current->left_child != nil) s.push(current->left_child);
            if (current->right_child != nil) s.push(current->right_child);
        }
        
        // Property 3: All paths have same black height
        return CheckBlackHeight(root) != -1;
    }

    void PrintTree() {
        if (root == nil) {
            cout << "Tree is empty\n";
            return;
        }
        
        queue<Node*> q;
        q.push(root);
        int level = 0;
        
        while (!q.empty()) {
            int size = q.size();
            cout << "Level " << level++ << ": ";
            
            for (int i = 0; i < size; i++) {
                Node* current = q.front();
                q.pop();
                
                cout << current->key << (current->colour == RED ? "R" : "B") << " ";
                
                if (current->left_child != nil) q.push(current->left_child);
                if (current->right_child != nil) q.push(current->right_child);
            }
            cout << endl;
        }
    }

    RedBlackTree() {
        nil = new Node(-1, BLACK);
        nil->left_child = nil;
        nil->right_child = nil;
        nil->parent = nil;
        root = nil;
    }
    
    ~RedBlackTree() {
        DeleteTree(root);
        delete nil;
    }
};