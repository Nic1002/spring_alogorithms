#include "hashmap.hpp"
#include <functional>
#include <stdexcept>

const double HashMap::LOAD_FACTOR_THRESHOLD = 0.75;

HashMap::HashMap() : HashMap(DEFAULT_CAPACITY) {}

HashMap::HashMap(size_t initialCapacity) : buckets(initialCapacity), size(0) {}

size_t HashMap::hash(const std::string& key) const {
    return std::hash<std::string>{}(key);
}

size_t HashMap::getBucketIndex(const std::string& key) const {
    return hash(key) % buckets.size();
}

void HashMap::rehash() {
    std::vector<std::list<KeyValuePair>> oldBuckets = std::move(buckets);
    buckets.resize(oldBuckets.size() * 2);
    size = 0;

    for (auto& bucket : oldBuckets) {
        for (auto& pair : bucket) {
            insert(pair.key, pair.value);
        }
    }
}

void HashMap::insert(const std::string& key, int value) {
    size_t index = getBucketIndex(key);
    for (auto& pair : buckets[index]) {
        if (pair.key == key) {
            pair.value = value;
            return;
        }
    }

    buckets[index].push_back({key, value});
    size++;

    if (static_cast<double>(size) / buckets.size() > LOAD_FACTOR_THRESHOLD) {
        rehash();
    }
}

bool HashMap::contains(const std::string& key) const {
    size_t index = getBucketIndex(key);
    for (const auto& pair : buckets[index]) {
        if (pair.key == key) {
            return true;
        }
    }
    return false;
}

int HashMap::get(const std::string& key) const {
    size_t index = getBucketIndex(key);
    for (const auto& pair : buckets[index]) {
        if (pair.key == key) {
            return pair.value;
        }
    }
    throw std::out_of_range("Key not found");
}

void HashMap::remove(const std::string& key) {
    size_t index = getBucketIndex(key);
    auto& bucket = buckets[index];

    for (auto it = bucket.begin(); it != bucket.end(); ++it) {
        if (it->key == key) {
            bucket.erase(it);
            size--;
            return;
        }
    }
}

size_t HashMap::getSize() const {
    return size;
}

bool HashMap::isEmpty() const {
    return size == 0;
}

void HashMap::clear() {
    for (auto& bucket : buckets) {
        bucket.clear();
    }
    size = 0;
}