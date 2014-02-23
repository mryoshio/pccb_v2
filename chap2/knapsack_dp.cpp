#include <iostream>
#include "../d.h"

using namespace std;

int N, W;

typedef pair<int, int> item;
item ITEMS[101];

int dp[101][10001];

void solve() {
  for (int i = 0; i < N; i++) {
    for (int j = 0; j <= W; j++) {
      if (j < ITEMS[i].first) {
        dp[i+1][j] = dp[i][j];
      } else {
        dp[i+1][j] = max(dp[i][j], dp[i][j - ITEMS[i].first] + ITEMS[i].second);
      }
    }
  }
  cout << dp[N][W] << endl;
}

int main() {
  memset(dp, 0, sizeof(dp));
  cout << "N: "; cin >> N;
  cout << "W: "; cin >> W;
  for (int i = 0; i < N; i++) {
    int w, v;
    cout << i << "th w v: ";
    cin >> w >> v;
    ITEMS[i] = make_pair(w, v);
  }
  solve();
  return 0;
}
