#include <list>
#include <string>
#include <vector>

class HashMap {
 private:
  struct KeyValuePair {
    std::string key;
    int value;
  };

  static const size_t DEFAULT_CAPACITY = 16;
  static const double LOAD_FACTOR_THRESHOLD;

  std::vector<std::list<KeyValuePair>> buckets;
  size_t size;

  size_t hash(const std::string& key) const;
  size_t getBucketIndex(const std::string& key) const;
  void rehash();

 public:
  HashMap();
  explicit HashMap(size_t initialCapacity);
  ~HashMap() = default;

  void insert(const std::string& key, int value);
  bool contains(const std::string& key) const;
  int get(const std::string& key) const;
  void remove(const std::string& key);
  size_t getSize() const;
  bool isEmpty() const;
  void clear();
};
