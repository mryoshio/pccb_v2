#include <iostream>

using namespace std;

int main() {
  int a[5] = {4, 2, 3, 1, 5};
  cout << *lower_bound(a, a+5, 3) << endl;
  cout << *upper_bound(a, a+5, 3) << endl;
  return 0;
}
