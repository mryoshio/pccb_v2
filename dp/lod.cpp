#include <iostream>
#include <algorithm>
using namespace std;

int prices[] = { 0, 1, 5, 8, 9, 10, 17, 17, 20, 24, 30 };
int N;

void solve() {
  for (int i = 1; i <= N; i++) {
    int v = 0;
    for (int j = 1; j <= i; j++) {
      v = max(v, prices[j] + prices[i-j]);
    }
    prices[i] = v;
    cout << "lod" << i << ": " << prices[i] << endl;
  }
}

int main() {
  cout << "N: "; cin >> N;
  solve();  
}
