#include <vector>

class HashTable {
 public:
  HashTable();
  HashTable(std ::vector<int> InputData) : data{InputData} {};

  void add (int elem);
 private:
  std ::vector<int> data;
};