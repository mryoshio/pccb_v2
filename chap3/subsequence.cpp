#include <iostream>

using namespace std;

int n, s;
const int MAX_N = 100000;
int a[MAX_N] = { 5, 1, 3, 5, 10, 7, 4, 9, 2, 8 };
int sum[MAX_N + 1];

void solve() {
  for (int i = 0; i < n; i++)
    sum[i + 1] = sum[i] + a[i];

  if (sum[n] < s) {
    cout << 0 << endl;
    return;
  }

  int res = n;
  for (int i = 0; sum[i] + s <= sum[n]; i++) {
    int t = lower_bound(sum + i, sum + n, sum[i] + s) - sum;
    res = min(res, t-i);
  }
  cout << res << endl;
}

int main() {
  n = 10;
  s = 15;
  solve();
  return 0;
}
