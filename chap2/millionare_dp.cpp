#include <iostream>
using namespace std;

int M, X;
double P;

double dp[2][(1 << 15) + 1];

void solve() {
  int n = 1 << M;

  double *prev = dp[0], *next = dp[1];
  memset(prev, 0, sizeof(double) * (n + 1));
  prev[n] = 1.0;

  for (int r = 0; r < M; r++) {
    for (int i = 0; i <= n; i++) {
      int jub = min(i, n-i);
      double t = 0.0;
      for (int j = 0; j <= jub; j++)
        t = max(t, P * prev[i+j] + (1-P)*prev[i-j]);
      next[i] = t;
    }
    swap(prev, next);
  }
  int i = (long long)X*n/1000000;

  cout << "=========" << endl;

  for (int o = 0; o < 2; o++) {
    for (int oo = 0; oo < 10; oo++)
      cout << dp[o][oo] << " ";
    cout << endl;
  }

  cout << prev[i] << endl;
}

int main() {
  cout << "Round: "; cin >> M;
  cout << "Probability: "; cin >> P;
  cout << "Money: "; cin >> X;
  solve();
}
