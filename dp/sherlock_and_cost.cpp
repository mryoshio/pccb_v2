#include <iostream>
#include <vector>
using namespace std;

vector<int> b;

const int max_size = 101;

void solve() {
  int dp[max_size][max_size];

  for (int i = 0; i < max_size; i++) {
    dp[0][max_size-1] = 0;
    dp[max_size-1][0] = b.at(0);
  }

  for (int i = 1; i <= b.size(); i++)
    dp[i][i] = max(b.at(i-1) + dp[i][i-1], 1 + dp[i][i-1]);
  
  for (int i = 0 ; i < b.size(); i++) {
    for (int j = 0 ; j < b.size(); j++)
      cout << dp[i][j] << " ";
    cout << endl;
  }
}

int main() {
  int t, n, bi;
  cin >> t >> n;
  for (int i = 0; i < t; i++) {
    b.clear();
    for (int j = 0; j < n; j++) {
      cin >> bi;
      b.push_back(bi);
    }
    solve();
  }
}
