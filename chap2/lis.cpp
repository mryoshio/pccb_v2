#include <iostream>
#include "../d.h"

#define MAX_N 1000

int a[MAX_N+1];
int dp[MAX_N+1];
int n;

using namespace std;

void solve() {
  int ans = 0;
  for (int i = 0; i < n; i++) {
    dp[i] = 1; // minimum LCS for a[i]
    for (int j = 0; j < i; j++)
      if (a[j] < a[i])
        dp[i] = max(dp[i], dp[j] +1);
    ans = max(ans, dp[i]);
  }
  printf( "ans: %d\n", ans);
  d(dp, n);
}

int main() {
  cout << "n: "; cin >> n;
  for (int i = 0; i < n; i++) {
    cout << "a[" << i << "]: ";
    cin >> a[i];
  }
  solve();
}

