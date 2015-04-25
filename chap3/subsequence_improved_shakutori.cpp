#include <iostream>

using namespace std;

int n, s;
const int MAX_N = 100000;
int a[MAX_N] = { 5, 1, 3, 5, 10, 7, 4, 9, 2, 8 };
int sum[MAX_N + 1];

void solve() {
  int res = n + 1;
  int i = 0, t = 0, sum = 0;

  for (;;) {
    while (t < n && sum < s)
      sum += a[t++];

    if (sum < s) break;
    else res = min(res, t -s);

    sum -= a[i++];
  }

  if (res == 0) cout << 0 << endl;
  else cout << res;
}

int main() {
  n = 10;
  s = 15;
  solve();
  return 0;
}
