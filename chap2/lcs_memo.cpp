#include <iostream>
#include <string>
#include "../d.h"

using namespace std;

int N, M;
string S, T;
int dp[1001][1001];

int calc(int n, int m) {
  if (dp[n][m] >= 0)
    return dp[n][m];

  int v;
  if (n == N || m == M) {
    v = 0;
  } else {
    if (S[n] == T[m]) {
      v = calc(n+1, m+1) + 1;
    } else {
      v =  max(calc(n+1, m), calc(n, m+1));
    }
  }
  return dp[n][m] = v;
}

void solve() {
  int res = calc(0, 0);
  cout << res << endl;
}

int main() {
  memset(dp, -1, sizeof(dp));
  cout << "n: "; cin >> N;
  cout << "m: "; cin >> M;
  cout << "s: "; cin >> S;
  cout << "t: "; cin >> T;
  solve();
  return 0;
}
