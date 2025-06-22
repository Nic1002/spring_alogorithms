#include <iostream>
#include <vector>

class TableChecker {
 public:
  void readTable(std::istream& in);
  void processQueries(std::istream& in, std::ostream& out);

 private:
  int n = 0, m = 0;
  std::vector<std::vector<int>> table;
  std::vector<std::vector<int>> column_ok;
  std::vector<std::vector<int>> prefix;

  void prepareData();
  bool isRangeSorted(int l, int r) const;
};