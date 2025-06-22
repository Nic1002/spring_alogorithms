#include <memory>
#include <stdexcept>

class BinarySearchTree {
private:
    struct Node {
        int key;
        std::unique_ptr<Node> left;
        std::unique_ptr<Node> right;
        
        Node(int k) : key(k), left(nullptr), right(nullptr) {}
    };

    std::unique_ptr<Node> root;
    
    void insert(std::unique_ptr<Node>& node, int key);
    bool contains(const std::unique_ptr<Node>& node, int key) const;
    int minValue(const std::unique_ptr<Node>& node) const;
    void remove(std::unique_ptr<Node>& node, int key);
    size_t size(const std::unique_ptr<Node>& node) const;

public:
    BinarySearchTree();
    ~BinarySearchTree() = default;

    void insert(int key);
    bool contains(int key) const;
    void remove(int key);
    void clear();
    size_t size() const;
    bool isEmpty() const;
    int minValue() const;
};