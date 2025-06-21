#include "HashTable.hpp"

void HashTable::rehash() {
  int old_capacity = capacity;
  capacity *= 2;
  std::vector<std::list<std::pair<std::string, int>>> new_table(capacity);

  for (const auto& bucket : table) {
    for (const auto& entry : bucket) {
      int idx = std::hash<std::string>{}(entry.first) % capacity;
      new_table[idx].emplace_back(entry.first, entry.second);
    }
  }

  table = std::move(new_table);
};

void HashTable::insert(const std::string& key, int value) {
  int idx = getIndex(key);
  for (auto& entry : table[idx]) {
    if (entry.first == key) {
      entry.second = value;
      return;
    }
  }
  table[idx].emplace_back(key, value);
  ++size;
  checkLoadFactorAndRehash();
};

std::optional<int> HashTable::find(const std::string& key) const {
  int idx = getIndex(key);
  for (const auto& entry : table[idx]) {
    if (entry.first == key) {
      return entry.second;
    }
  }
  return std::nullopt;
};

bool HashTable::erase(const std::string& key) {
  int idx = getIndex(key);
  for (auto it = table[idx].begin(); it != table[idx].end(); ++it) {
    if (it->first == key) {
      table[idx].erase(it);
      --size;
      return true;
    }
  }
  return false;
};

void HashTable::print() const {
  for (int i = 0; i < capacity; ++i) {
    std::cout << "[" << i << "]: ";
    for (const auto& entry : table[i]) {
      std::cout << "(" << entry.first << ": " << entry.second << ") ";
    }
    std::cout << std::endl;
  }
};