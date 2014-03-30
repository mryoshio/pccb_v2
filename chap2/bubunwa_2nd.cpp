#include <iostream>

using namespace std;

#define MAX_N 100001

int n;
int a[MAX_N];
int m[MAX_N];
int K;
bool dp[MAX_N+1];

void solve() {
  memset(dp, -1, sizeof(dp));
  dp[0] = 0;

  for (int i = 0; i < n; i++) {
    for (int j = 0; j <= K; j++) {
      if (dp[j] >= 0) {
        dp[j] = m[i];
      } else if (j < a[i] || dp[j - a[i]] <= 0) {
        dp[j] = -1;
      } else {
        dp[j] = dp[j - a[i]] - 1;
      }
    }
  }
  if (dp[K] >= 0) puts("YES");
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
