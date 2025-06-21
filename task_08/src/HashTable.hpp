#pragma once

#include <iostream>
#include <list>
#include <optional>
#include <string>
#include <vector>

class HashTable {
 private:
  std::vector<std::list<std::pair<std::string, int>>> table;
  int capacity;
  int size;

  int getIndex(const std::string& key) const {
    return std::hash<std::string>{}(key) % capacity;
  }

  void rehash();

  void checkLoadFactorAndRehash() {
    if (size > capacity / 2) {
      rehash();
    }
  }

 public:
  HashTable(int init_capacity = 8) : capacity(init_capacity), size(0) {
    table.resize(capacity);
  }

  void insert(const std::string& key, int value);

  std::optional<int> find(const std::string& key) const;

  bool erase(const std::string& key);

  void print() const;
};