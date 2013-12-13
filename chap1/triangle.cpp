#include <iostream>

using namespace std;

const int MAX_N = 100;
int n, a[MAX_N];

void input() {
  cout << "n: ";
  cin >> n;
  for (int i = 0; i < n; i++) {
    printf("%d's length: ", i);
    cin >> a[i];
  }
}

void solve() {
  int len, max_len, ans = 0;

  for (int i = 0; i < n; i++)
    for (int j = i + 1; j < n; j++)
      for (int k = j + 1; k < n; k++) {
        len = a[i] + a[j] + a[k];
        max_len = max(a[i], max(a[j], a[k]));
        if (len >= 2 * max_len)
          ans = max(ans, len);
      }
  cout << ans << endl;
}

int main() {
  input();
  solve();
  return 0;
}
