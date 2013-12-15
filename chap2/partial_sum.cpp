#include <iostream>

#define MAX_N 20

using namespace std;

int a[MAX_N];
int n, k;

bool dfs(int i, int sum) {
  if (i == n) return sum == k;

  if (dfs(i + 1, sum)) return true;

  if (dfs(i + 1, sum + a[i])) return true;

  return false;
}

void solve() {
  if (dfs(0, 0)) cout << "Yes" << endl;
  else cout << "No" << endl;
}

int main() {
  cout << "n: "; cin >> n;
  for (int i = 0; i < n; i++) {
    cout << "a[" << i << "]: ";
    cin >> a[i];
  }
  cout << "k: "; cin >> k;
  solve();
}
