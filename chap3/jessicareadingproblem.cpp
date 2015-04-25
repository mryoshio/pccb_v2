#include <iostream>
#include <set>
#include <map>
using namespace std;

int P = 5;
int a[] = { 1, 8, 8, 8, 1 };

void solve() {
  set<int> conts;
  for (int i = 0; i < P; i++)
    conts.insert(a[i]);

  int n = conts.size();

  int s = 0, t = 0, num = 0;
  int res = P;
  map<int, int> count;

  for (;;) {
    while (t < P && num < n) {
      if (count[a[t++]]++ == 0)
        num++;
    }

    if (num < n) break;

    res = min(res, t - s);

    if (--count[a[s++]] == 0)
      num--;
  }

  cout << res << endl;
}

int main() {
  solve();
  return 0;
}
