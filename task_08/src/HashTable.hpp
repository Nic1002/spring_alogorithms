#include <string>
#include <vector>

class HashTable {
 public:
  HashTable();

  void add(std::string key, int value);
  void remove(std::string key);
  int get(std::string key);

 private:
  enum struct Label {
    Empty = 0,
    Full = 1,
    Deleted = 2,
  };
  struct Elem {
    Label CurrentLabel;
    int Value;
    std::string Key;
  };
  int EngagedSpace = 0;
  std ::vector<Elem> data;
  size_t MyHash(std::string value);
  void Resize();
  Elem ZeroElem = {Label::Empty, 0};
};