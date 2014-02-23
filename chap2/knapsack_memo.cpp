#include <iostream>
#include "../d.h"

using namespace std;

int N, W;

typedef pair<int, int> item;
item ITEMS[101];

int dp[101][10001];

int calc(int i, int w_limit) {
  if (dp[i][w_limit] > 0)
    return dp[i][w_limit];
    
  int v;
  if (i == N) {
    v = 0;
  } else {
    if (w_limit < ITEMS[i].first) {
      v = calc(i + 1, w_limit);
    } else {
      // not add ITEMS[i]
      int case_one = calc(i + 1, w_limit);
      // add ITEMS[i]
      int case_two = calc(i + 1, w_limit - ITEMS[i].first);
      case_two += ITEMS[i].second;

      v = max(case_one, case_two);
    }
  }
  return dp[i][w_limit] = v;
}

void solve() {
  int res = calc(0, W);
  cout << res << endl;
}

int main() {
  memset(dp, -1, sizeof(dp));
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
