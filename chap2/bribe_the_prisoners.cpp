#include <algorithm>
#include <climits>
#include <iostream>
#include <vector>
using namespace std;

int min_num = INT_MAX;

void solve(int num, int i, vector<int> prisoners, vector<int> targets) {
  prisoners[targets[i]-1] = false;

  for (int l = targets[i]-2; l >= 0; l--) {
    if (prisoners[l] == false) break;
    num++;    
  }

  for (int r = targets[i]; r < prisoners.size(); r++) {
    if (prisoners[r] == false) break;
    num++;    
  }

  bool last = true;
  for (int j = 0; j < targets.size(); j++) {
    if (prisoners[targets[j]-1] == true) {
      solve(num, j, prisoners, targets);
      last = false;
    }
  }

  if (last)
    if (min_num > num) min_num = num;
}

int main() {
  int p, q;
  cin >> p >> q;

  vector<int> prisoners(p);
  vector<int> targets(q);
  fill(prisoners.begin(), prisoners.end(), true);

  for (int i = 0; i < q; i++)
    cin >> targets[i];

  for (int i = 0; i < q; i++)
    solve(0, i, prisoners, targets);

  cout << min_num << endl;

  return 0;
}
