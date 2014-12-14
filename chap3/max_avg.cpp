#include <iostream>
using namespace std;

int k, n;
int v[10000] = {0};
int w[10000] = {0};
double y[10000] = {0};

bool check(double x) {
  for (int i = 0; i < n; i++)
    y[i] = v[i] - x * w[i];

  sort(y, y + n);

  double sum = 0;

  for (int i = 0; i < k; i++)
    sum += y[n - i - 1];

  return sum >= 0;
}

void solve() {
  double ub = 100000, lb = 0;
  for (int i = 0; i < 100; i++) {
    double mid = (ub + lb) / 2;
    if (check(mid)) lb = mid;
    else ub = mid;
  }
  cout << lb << endl;
  cout << ub << endl;
}

int main() {
  cout << "n k: ";
  cin >> n >> k;
  for (int i = 0; i < n; i++)
    cin >> v[i] >> w[i];

  solve();
  return 0;
}
