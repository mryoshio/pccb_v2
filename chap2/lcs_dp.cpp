#include <iostream>
#include <string>
#include "../d.h"

using namespace std;

int N, M;
string S, T;
int dp[1001][1001];

void dump() {
  for (int i = 0; i < N+1; i++) {
    for (int j = 0; j < M+1; j++) {
      cout << dp[i][j] << ' ';
    }
    cout << endl;
  }
}

void solve() {
  for (int i = 0; i < N; i++) {
    for (int j = 0; j < M; j++) {
      if (S[i] == T[j]) {
        dp[i+1][j+1] = dp[i][j] + 1;
      } else {
        dp[i+1][j+1] = max(dp[i+1][j], dp[i][j+1]);
      }
    }
  }
  // dump();
  cout << dp[N][M] << endl;
}

int main() {
  memset(dp, 0, sizeof(dp));
  cout << "n: "; cin >> N;
  cout << "m: "; cin >> M;
  cout << "s: "; cin >> S;
  cout << "t: "; cin >> T;
  solve();
  return 0;
}
