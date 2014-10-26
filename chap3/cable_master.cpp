#include <iostream>
#include <cmath>
using namespace std;

int N, K;
double L[10000];

bool check(double x){
  int n = 0;
  for (int i = 0; i < N; i++)
    n += (int)(L[i]/x);
  return n >= K;
}

void solve() {
  double lb = 0, ub = 100000;
  for (int i = 0; i < 100; i++) {
    double mid = (lb+ub)/2;
    if (check(mid)) lb = mid;
    else ub = mid;
  }
  cout << floor(ub*100)/100 << endl;
}

int main() {
  cin >> N;
  cin >> K;
  for (int i = 0; i < N; i++)
    cin >> L[i];
  solve();
}
