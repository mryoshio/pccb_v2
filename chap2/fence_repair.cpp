#include <iostream>
#include "../d.h"

using namespace std;

int N;
int L[50001];

void solve() {
  long ans = 0;
  int k = N;
  while (k > 1) {
    d(L, N);

    // min1 is index of the smallest value and
    // min2 is of the secondary smallest.
    int min1 = 0, min2 = 1;
    if (L[min1] > L[min2]) swap(min1, min2);

    for (int i = 2; i < k; i++) {
      if (L[i] < L[min1]) {
        min2 = min1;
        min1 = i;
      } else if (L[i] < L[min2]) {
        min2 = i;
      }
    }

    cout << "min1: " << min1 << ", min2: " << min2;
    cout << ", k: " << k << endl;

    int t = L[min1] + L[min2];
    ans += t;

    if (min1 == k-1) swap(min1, min2);
    L[min1] = t;
    L[min2] = L[k-1];
    k--;
  }
  cout << "ans: " << ans << endl;
}

int main() {
  cin >> N;
  for (int i = 0; i <= N; i++)
    cin >> L[i];
  solve();
  return 0;
}
