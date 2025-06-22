#include "solution.hpp"
#include <iostream>

int main() { 
  int n;
  int c;
  cin>>n;
  vector<int> a(n);
  cin>>c;
  for (int i=0; i<n; i++)
  {
    cin>>a[i];
  }
  Result result = Solve(n, c, a);

  if (result.finded)
    cout << a[result.left] << ' ' << a[result.right] << endl;
  else
    cout << "Не удалось найти ответ!" << endl;

  return 0; }
