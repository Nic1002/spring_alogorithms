#include "RB_Tree.hpp"

class RedBlackTree{
    private:
        enum Colour {RED, BLACK};

        struct Node{
            int key;
            Colour colour;
            Node* left_child;
            Node* right_child;
            Node* parent;

            Node(int k, Colour c = BLACK, Node* l = nullptr, Node* r = nullptr, Node* p = nullptr): key(k), colour(c), left_child(l), right_child(r), parent(p) {}
        };

        Node* root;
        Node* nil;

        void DeleteTree(Node* knot){
            if (knot != nil){
                DeleteTree(knot->left_child);
                DeleteTree(knot->right_child);
                delete knot;
            }
        };
        
        void LeftRotate(Node* knot){
            Node* r = knot->right_child;
            knot->right_child = r->left_child;
            if (r->left_child != nil){
                r->left_child->parent = knot;
            }
            r->parent = knot->parent;
            if (knot->parent == nil){
                root = r;
            } else if (knot == knot->parent->left_child){
                knot->parent->right_child = r;
            } else {
                knot->parent->right_child = r;
            }
            r->left_child = knot;
            knot->parent = r;
        };

        void RightRotate(Node* knot){
            Node* l = knot->left_child;
            knot->left_child = l->right_child;
            if (l->right_child != nil){
                l->right_child->parent = knot;
            }
            l->parent = knot->parent;
            if (knot->parent == nil){
                root = l;
            } else if (knot == knot->left_child){
                knot->parent->left_child = l;
            } else {
                knot->parent->right_child =l;
            }
            l->right_child = knot;
            knot->parent = l;
        };

        void Transplant(Node* root1, Node* root2){
            if(root1->parent == nil){
                root = root1;
            } else if(root1 == root1->parent->left_child){
                root1->parent->left_child = root2;
            } else {
                root1->parent->right_child = root2;
            }
            root2->parent = root1->parent;
        };

        void FixInsert(Node* knot){
            while(knot->parent->colour == RED){
                if(knot->parent == knot->parent->parent->left_child){
                    Node* y = knot->parent->parent->right_child;
                    if(y->colour == RED){
                        knot->parent->colour = BLACK;
                        y->parent->colour = BLACK;
                        knot->parent->parent->colour = RED;
                        knot = knot->parent->parent;
                    } else {
                        if(knot == knot->parent->right_child){
                            knot = knot->parent;
                            LeftRotate(knot);
                        }
                        knot->parent->colour = BLACK;
                        knot->parent->parent->colour = RED;
                        RightRotate(knot->parent->parent);
                    }
                } else{
                    Node* y =knot->parent->parent->left_child;
                    if(y->colour == RED){
                        knot->parent->colour = BLACK;
                        y->colour = BLACK;
                        knot->parent->parent->colour = RED;
                        knot = knot->parent->parent;
                    } else {
                        if(knot == knot->parent->left_child){
                            knot = knot->parent;
                            RightRotate(knot);
                        }
                        knot->parent->colour = BLACK;
                        knot->parent->parent->colour = RED;
                        LeftRotate(knot->parent->parent);
                    }
                }
            }
            root->colour = BLACK;
        };

        void FixDelete(Node* knot){
            while (knot != root && knot->colour == BLACK) {
            if (knot == knot->parent->left_child) {
                Node* w = knot->parent->right_child;
                if (w->colour == RED) {
                    w->colour = BLACK;
                    knot->parent->colour = RED;
                    LeftRotate(knot->parent);
                    w = knot->parent->right_child;
                }
                if (w->left_child->colour == BLACK && w->right_child->colour == BLACK) {
                    w->colour = RED;
                    knot = knot->parent;
                } else {
                    if (w->right_child->colour == BLACK) {
                        w->left_child->colour = BLACK;
                        w->colour = RED;
                        RightRotate(w);
                        w = knot->parent->right_child;
                    }
                    w->colour = knot->parent->colour;
                    knot->parent->colour = BLACK;
                    w->right_child->colour = BLACK;
                    LeftRotate(knot->parent);
                    knot = root;
                }
            } else {
                Node* w = knot->parent->left_child;
                if (w->colour == RED) {
                    w->colour = BLACK;
                    knot->parent->colour = RED;
                    RightRotate(knot->parent);
                    w = knot->parent->left_child;
                }
                if (w->right_child->colour == BLACK && w->left_child->colour == BLACK) {
                    w->colour = RED;
                    knot = knot->parent;
                } else {
                    if (w->left_child->colour == BLACK) {
                        w->right_child->colour = BLACK;
                        w->colour = RED;
                        LeftRotate(w);
                        w = knot->parent->left_child;
                    }
                    w->colour = knot->parent->colour;
                    knot->parent->colour = BLACK;
                    w->left_child->colour = BLACK;
                    RightRotate(knot->parent);
                    knot = root;
                    }
                }
            }
            knot->colour = BLACK;
        };

        Node* GetMinimum(Node* knot){
            while (knot->left_child != nil){
                knot = knot->right_child;
            }
            return knot;
        };

        Node* GetMaximum(Node* knot){
            while(knot->right_child != nil){
                knot = knot->right_child;
            }
            return knot;
        };

        Node* FindSuccessor(Node* knot){
            if(knot->right_child != nil){
                return GetMinimum(knot->right_child);
            }
            Node* y = knot->parent;
            while(y != nil && knot == y->right_child){
                knot = y;
                y = y->parent;
            }
            return y;
        };

        Node* FindPredecessor(Node* knot){
            if (knot->left_child != nil){
                return GetMaximum(knot->left_child);
            }
            Node* y = knot->parent;
            while(y != nil && knot == y->left_child){
                knot = y;
                y = y->parent;
            }
            return y;
        };

        int CheckBlackHeight(Node* knot){
            if (knot == nil) {return 1;}
        
            int leftHeight = CheckBlackHeight(knot->left_child);
            int rightHeight = CheckBlackHeight(knot->right_child);
        
            if (leftHeight == -1 || rightHeight == -1 || leftHeight != rightHeight) {
                return -1;
            }
        
            return leftHeight + (knot->colour == BLACK ? 1 : 0);
        };

    public:
        void FindKey(int key){
            Node* current = root;
            while (current != nil) {
                if (key == current->key) {
                    cout << "Key " << key << " found in the tree.\n";
                    return;
                } else if (key < current->key) {
                    current = current->left_child;
                } else {
                    current = current->right_child;
                }
            }
            cout << "Key " << key << " not found in the tree.\n";
        };

        void InsertKey(int key){
            Node* z = new Node(key, BLACK ,nil, nil, nil);
            Node* y = nil;
            Node* x = root;
            while (x != nil){
                y = x;
                if (z->key < x->key){
                    x = x->left_child;
                } else{
                    x = x->right_child;
                }
            }
            z->parent = y;
            if (y == nil){
                root = z;
            } else if (z->key < y->key){
                y->left_child = z;
            } else{
                y->right_child = z;
            }
            FixInsert(z);
        };

        void DeleteKey(int key){
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
        
            if (original_color == BLACK) {
                FixDelete(x);
            }
        };

        bool Search(int key) {
            Node* current = root;
            while (current != nil) {
                if (key == current->key)
                    return true;
                else if (key < current->key)
                    current = current->left_child;
                else
                    current = current->right_child;
            }
            return false;
        };
        
        void InOrder(Node* knot){
            if(knot != nil){
                InOrder(knot->left_child);
                std::cout << knot->key << " ";
                InOrder(knot->right_child);
            }
        };

        int GetMinimum(){
            if (root == nil) {
                std::cerr << "Tree is empty!\n";
            }
            return GetMinimum(root)->key;
        };

        int GetMaximum(){
            if (root == nil) {
                std::cerr << "Tree is empty!\n";
            }
            return GetMaximum(root)->key;
        };

        int FindSuccessor(int key){   
            Node* current = root;
            while (current != nil && current->key != key) {
                if (key < current->key) {
                    current = current->left_child;
                } else {
                    current = current->right_child;
                }
            };
            if (current == nil) {
                std::cerr << "Key not found!\n";
            };
            Node* succ = FindSuccessor(current);
            if (succ == nil) {
                std::cerr << "No successor exists!\n";
            };
            return succ->key;
        };

        int FindPredecessor(int key){
            Node* current = root;
            while (current != nil && current->key != key) {
                if (key < current->key) {
                    current = current->left_child;
                } else {
                    current = current->right_child;
                }
            };
            if (current == nil) {
                std::cerr << "Key not found!\n";
            };
            Node* pred = FindPredecessor(current);
            if (pred == nil) {
                std::cerr << "No predecessor exists!\n";
            };
            return pred->key;
        };

        void CheckRBProperties(){
            if (root->colour != BLACK) {
                std::cerr << "RB Property violation: Root is not black!\n";
            };
            std::stack<Node*> s;
            s.push(root);
            while (!s.empty()) {
            Node* current = s.top();
            s.pop();
            
            if (current == nil) continue;
            
            if (current->colour == RED) {
                if (current->left_child->colour != BLACK || 
                    current->right_child->colour != BLACK) {
                    std::cerr << "RB Property violation: Red node has red child!\n";
                    return;
                }
            }
            
            if (current->right_child != nil) {s.push(current->right_child);};
            if (current->left_child != nil) {s.push(current->left_child);};
            }
        };

        void PrintTree(){
            if (root == nil) {
            std::cout << "Tree is empty.\n";
            return;
            }
            std::queue<Node*> q;
            q.push(root);
            int level = 0;
            while (!q.empty()) {
                int levelSize = q.size();
                std::cout << "Level " << level++ << ": ";
                for (int i = 0; i < levelSize; i++) {
                    Node* current = q.front();
                    q.pop();
                    if (current == nil) {
                        std::cout << "NIL ";
                        continue;
                    };
                    std::cout << current->key << (current->colour == RED ? "R" : "B") << " ";
                    if (current->left_child != nil || current->right_child != nil) {
                        q.push(current->left_child);
                        q.push(current->right_child);
                    } else {
                        q.push(nil);
                        q.push(nil);
                    }
                }
                std::cout << std::endl;
            }
        };

        RedBlackTree() {
            nil = new Node(-1, BLACK);
            nil->colour = BLACK;
            nil->left_child = nil;
            nil->right_child = nil;
            nil->parent = nil;
            root = nil;
        };
        
        ~RedBlackTree(){
           DeleteTree(root);
           delete nil;
        };
};