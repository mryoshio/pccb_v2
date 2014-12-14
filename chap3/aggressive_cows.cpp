#include <iostream>
#include <algorithm>
using namespace std;

int N, M;
int X[100000] = {0};

bool check(long distance) {
  int last = 0;
  for (int cow = 1; cow < M; cow++) {
    int cur = last + 1;
    while (cur < N && X[cur] - X[last] < distance)
      cur++;
    if (cur == N) return false;
    last = cur;
  }
  return true;
}

void solve() {
  long lb = 0, ub = 1000000000;
  while (ub - lb > 1) {
    int mid = (lb + ub) / 2;
    if (check(mid)) lb = mid;
    else ub = mid;
  }
  cout << lb << endl;
}

int main() {
  cout << "N M: ";
  cin >> N >> M;

  for (int i = 0; i < N; i++)
    cin >> X[i];

  sort(X, X + N);

  solve();
  return 0;
}
