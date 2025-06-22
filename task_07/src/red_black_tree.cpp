#include "red_black_tree.hpp"

void RedBlackTree::Insert(int key) {
    Node *z = new Node(key, Colour::Red, nil, nil, nil);
    Node *y = nil;
    Node *x = root;

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

void RedBlackTree::FixInsert(Node *z) {
    while (z->parent->colour == Colour::Red) {
        if (z->parent == z->parent->parent->left_child) {
            Node *y = z->parent->parent->right_child;
            if (y->colour == Colour::Red) {
                z->parent->colour = Colour::Black;
                y->colour = Colour::Black;
                z->parent->parent->colour = Colour::Red;
                z = z->parent->parent;
            } else {
                if (z == z->parent->right_child) {
                    z = z->parent;
                    LeftRotate(z);
                }
                z->parent->colour = Colour::Black;
                z->parent->parent->colour = Colour::Red;
                RightRotate(z->parent->parent);
            }
        } else {
            // Симметричный случай
            Node *y = z->parent->parent->left_child;
            if (y->colour == Colour::Red) {
                z->parent->colour = Colour::Black;
                y->colour = Colour::Black;
                z->parent->parent->colour = Colour::Red;
                z = z->parent->parent;
            } else {
                if (z == z->parent->left_child) {
                    z = z->parent;
                    RightRotate(z);
                }
                z->parent->colour = Colour::Black;
                z->parent->parent->colour = Colour::Red;
                LeftRotate(z->parent->parent);
            }
        }
    }
    root->colour = Colour::Black;
}

void RedBlackTree::LeftRotate(Node *x) {
    Node *y = x->right_child;
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

void RedBlackTree::RightRotate(Node *y) {
    Node *x = y->left_child;
    y->left_child = x->right_child;
    if (x->right_child != nil) {
        x->right_child->parent = y;
    }
    x->parent = y->parent;
    if (y->parent == nil) {
        root = x;
    } else if (y == y->parent->right_child) {
        y->parent->right_child = x;
    } else {
        y->parent->left_child = x;
    }
    x->right_child = y;
    y->parent = x;
}

bool RedBlackTree::Contains(int key) const {
    return Contains(root, key);
}

bool RedBlackTree::Contains(Node* node, int key) const {
    if (node == nil) return false;
    if (node->key == key) return true;
    if (key < node->key) return Contains(node->left_child, key);
    return Contains(node->right_child, key);
}

RedBlackTree::Node* RedBlackTree::Search(int key) {
    Node* current = root;
    while (current != nil && current->key != key) {
        if (key < current->key) {
            current = current->left_child;
        } else {
            current = current->right_child;
        }
    }
    return current;
}

bool RedBlackTree::IsValid() const {
    if (root == nil) return true;

    // 1. Корень должен быть чёрным
    if (root->colour != Colour::Black) return false;

    // 2. Подсчёт чёрных узлов в путях и проверка свойств
    int blackCount = -1;
    return IsRedBlackTreeValid(root, 0, blackCount);
}

bool RedBlackTree::IsRedBlackTreeValid(Node* node, int currentBlackCount, int& totalBlackCount) const {
    if (node == nil) {
        if (totalBlackCount == -1) {
            totalBlackCount = currentBlackCount;
        } else if (currentBlackCount != totalBlackCount) {
            return false;
        }
        return true;
    }

    // 3. У красного узла оба потомка должны быть чёрными
    if (node->colour == Colour::Red) {
        if (node->left_child->colour != Colour::Black || node->right_child->colour != Colour::Black) {
            return false;
        }
    }

    int newBlackCount = currentBlackCount + (node->colour == Colour::Black ? 1 : 0);
    return IsRedBlackTreeValid(node->left_child, newBlackCount, totalBlackCount) &&
           IsRedBlackTreeValid(node->right_child, newBlackCount, totalBlackCount);
}

void RedBlackTree::Transplant(Node* u, Node* v) {
    if (u->parent == nil) {
        root = v;
    } else if (u == u->parent->left_child) {
        u->parent->left_child = v;
    } else {
        u->parent->right_child = v;
    }
    v->parent = u->parent;
}

RedBlackTree::Node* RedBlackTree::Minimum(Node* node) {
    while (node->left_child != nil) {
        node = node->left_child;
    }
    return node;
}

void RedBlackTree::FixDel(Node* x) {
    while (x != root && x->colour == Colour::Black) {
        if (x == x->parent->left_child) {
            Node* w = x->parent->right_child;
            // Случай 1: Брат x красный
            if (w->colour == Colour::Red) {
                w->colour = Colour::Black;
                x->parent->colour = Colour::Red;
                LeftRotate(x->parent);
                w = x->parent->right_child;
            }
            // Случай 2: Оба ребёнка брата чёрные
            if (w->left_child->colour == Colour::Black && w->right_child->colour == Colour::Black) {
                w->colour = Colour::Red;
                x = x->parent;
            } else {
                // Случай 3: Правый ребёнок брата чёрный
                if (w->right_child->colour == Colour::Black) {
                    w->left_child->colour = Colour::Black;
                    w->colour = Colour::Red;
                    RightRotate(w);
                    w = x->parent->right_child;
                }
                // Случай 4: Правый ребёнок брата красный
                w->colour = x->parent->colour;
                x->parent->colour = Colour::Black;
                w->right_child->colour = Colour::Black;
                LeftRotate(x->parent);
                x = root;
            }
        } else {
            // Симметричный случай (x — правый ребёнок)
            Node* w = x->parent->left_child;
            if (w->colour == Colour::Red) {
                w->colour = Colour::Black;
                x->parent->colour = Colour::Red;
                RightRotate(x->parent);
                w = x->parent->left_child;
            }
            if (w->right_child->colour == Colour::Black && w->left_child->colour == Colour::Black) {
                w->colour = Colour::Red;
                x = x->parent;
            } else {
                if (w->left_child->colour == Colour::Black) {
                    w->right_child->colour = Colour::Black;
                    w->colour = Colour::Red;
                    LeftRotate(w);
                    w = x->parent->left_child;
                }
                w->colour = x->parent->colour;
                x->parent->colour = Colour::Black;
                w->left_child->colour = Colour::Black;
                RightRotate(x->parent);
                x = root;
            }
        }
    }
    x->colour = Colour::Black;
}

void RedBlackTree::Del(int key) {
    Node* z = Search(key);
    if (z == nil) return;  

    Node* y = z;
    Node* x;
    Colour yOriginalColor = y->colour;

    // Случай 1: У z нет левого потомка
    if (z->left_child == nil) {
        x = z->right_child;
        Transplant(z, z->right_child);
    }
    // Случай 2: У z нет правого потомка
    else if (z->right_child == nil) {
        x = z->left_child;
        Transplant(z, z->left_child);
    }
    // Случай 3: У z есть оба потомка
    else {
        y = Minimum(z->right_child);
        yOriginalColor = y->colour;
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

    if (yOriginalColor == Colour::Black) {
        FixDel(x);
    }
}