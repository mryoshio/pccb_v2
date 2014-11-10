#include <iostream>
#include <algorithm>
using namespace std;

const int N = 10;
int dp[N+1][N+1];
string str1;
string str2;

void solve() {
  for (int i = 0; i <= N+1; i++) {
    dp[0][i] = 0;
    dp[i][0] = 0;
  }

  for (int i = 1; i <= str1.size(); i++) {
    for (int j = 1; j <= str2.size(); j++) {
      if (str1[i-1] == str2[j-1]) {
        dp[i][j] = dp[i-1][j-1] + 1;
      } else {
        dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
      }
    }
  }

  for (int i = 0; i <= str1.size(); i++) {
    for (int j = 0; j <= str2.size(); j++)
      cout << dp[i][j] << " ";
    cout << endl;
  }
}

// input example: "ABCBDA BDCABA"
int main() {
  cout << "str1 str2: ";
  cin >> str1 >> str2;
  solve();
  return 0;
}
