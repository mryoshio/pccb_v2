#include <iostream>

using namespace std;

#define MAX_N 100001

int n;
int a[MAX_N];
int m[MAX_N];
int K;
bool dp[MAX_N+1][MAX_N+1];

void solve() {
  dp[0][0] = true;
  for (int i = 0; i < n; i++)
    for (int j = 0; j <= K; j++)
      for (int k = 0; k <= m[i] && k * a[i] <= j; k++)
        dp[i+1][j] |= dp[i][j-k*a[i]];
  if (dp[n][K]) puts("YES");
  else puts("NO");
}

int main() {
  cout << "n: "; cin >> n;
  for (int i = 0; i < n; i++) {
    cout << "a[" << i << "]" << " " << "m[" << i << "]";
    cin >> a[i] >> m[i];
  }
  cout << "K: "; cin >> K;
  solve();
  return 0;
}
