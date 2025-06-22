#include "hash_table.hpp"

class HashTable {
private:
    struct Node {
        int key;
        int value;
        Node(int k, int v) : key(k), value(v) {}
    };
    
    std::vector<std::list<Node>> buckets;
    size_t itemCount = 0;
    const double loadFactorThreshold = 0.75;
    
    size_t getBucketIndex(int key) const {
        const unsigned int ukey = static_cast<unsigned int>(key);
        return (ukey * 2654435761U) % buckets.size();
    };
    
    void rehash() {
        std::vector<std::list<Node>> oldBuckets = std::move(buckets);
        buckets.resize(oldBuckets.size() * 2);
        itemCount = 0;
        
        for (auto& bucket : oldBuckets) {
            for (auto& node : bucket) {
                insert(node.key, node.value);
            }
        }
    };

public:
    HashTable(size_t initialSize = 11) : buckets(initialSize) {}
    
    void insert(int key, int value) {
        if (static_cast<double>(itemCount) / buckets.size() > loadFactorThreshold) {
            rehash();
        }
        
        size_t index = getBucketIndex(key);
        for (auto& node : buckets[index]) {
            if (node.key == key) {
                node.value = value;
                return;
            }
        }
        
        buckets[index].emplace_back(key, value);
        itemCount++;
    }
    
    bool contains(int key) const {
        if (buckets.empty()) return false;
        
        size_t index = getBucketIndex(key);
        for (const auto& node : buckets[index]) {
            if (node.key == key) {
                return true;
            }
        }
        return false;
    }
    
    int get(int key) const {
        if (buckets.empty()) {
            throw std::out_of_range("Key not found");
        }
        
        size_t index = getBucketIndex(key);
        for (const auto& node : buckets[index]) {
            if (node.key == key) {
                return node.value;
            }
        }
        throw std::out_of_range("Key not found");
    }
    
    void remove(int key) {
        if (buckets.empty()) return;
        
        size_t index = getBucketIndex(key);
        auto& bucket = buckets[index];
        
        for (auto it = bucket.begin(); it != bucket.end(); ++it) {
            if (it->key == key) {
                bucket.erase(it);
                itemCount--;
                return;
            }
        }
    }
    
    size_t size() const {
        return itemCount;
    };
    
    bool empty() const {
        return itemCount == 0;
    };
};