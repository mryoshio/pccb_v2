#include <iostream>
#include "../d.h"

#define MAX_N 1000
#define INF MAX_N

int a[MAX_N+1];
int dp[MAX_N+1];
int n;

using namespace std;

void solve() {
  fill(dp, dp + n, INF);
  for (int i = 0; i < n; i++)
    *lower_bound(dp, dp + n, a[i]) = a[i];
  printf( "ans: %d\n", lower_bound(dp, dp + n, INF) - dp);
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

