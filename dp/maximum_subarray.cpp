#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<vector<long> > vs;

void solve(vector<long> v) {
  vector<long> contiguous_dp(v.size()), non_contiguous_dp(v.size());

  contiguous_dp[0] = v[0];
  non_contiguous_dp[0] = v[0];

  for (int i = 1; i < v.size(); i++) {
    contiguous_dp[i] = max(v[i], v[i] + contiguous_dp[i-1]);
    non_contiguous_dp[i] = max(v[i], max(v[i] + non_contiguous_dp[i-1], non_contiguous_dp[i-1]));
  }
  cout << *max_element(contiguous_dp.begin(), contiguous_dp.end()) << " " << 
    *max_element(non_contiguous_dp.begin(), non_contiguous_dp.end()) << endl;
}

int main() {
  int t; cin >> t;

  while (t--) {
    vector<long> v;
    long n; cin >> n;

    while (n--) {
      int a; cin >> a;
      v.push_back(a);
    }
    vs.push_back(v);
  }
  for (int i = 0; i < vs.size(); i++)
    solve(vs[i]);
  return 0;
}
