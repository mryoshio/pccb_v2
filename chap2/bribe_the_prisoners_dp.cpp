#include <iostream>

using namespace std;

const int MAX_Q = 100;
int P, Q, A[MAX_Q+2];
int dp[MAX_Q+1][MAX_Q+2];

void d() {
  cout << "====================" << endl;
  for (int i = 0; i <= Q+1; i++) {
    for (int j = 0; j <= Q+1; j++)
      cout << dp[i][j] << "|";
    cout << endl;
  }
}

void solve() {
  A[0] = 0;
  A[Q+1] = P+1;

  for (int q = 0; q <= Q; q++)
    dp[q][q+1] = 0;

  for (int w = 2; w <= Q+1; w++) {
    for (int i = 0; i+w <= Q+1; i++) {
      int j = i + w, t = INT_MAX;

      for (int k = i + 1; k < j; k++)
        t = min(t, dp[i][k] + dp[k][j]);

      dp[i][j] = t + A[j] - A[i] - 2;
      cout << "t: " << t << ", j: " << j << ", i: " << i << endl;
      d();
    }
  }
  d();
  cout << dp[0][Q+1] << endl;
}

int main() {
  cin >> P >> Q;
  for (int i = 1; i < Q+1; i++)
    cin >> A[i];
  solve();
  return 0;
}
