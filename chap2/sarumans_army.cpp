#include <iostream>

using namespace std;

// p.47

#define MAX_N 1000
#define MAX_R 1000
#define MAX_X 1000

int N = 6;
int X[] = {1, 7, 15, 20, 30, 50};
int R = 10;

void solve() {
  int i = 0, c = 0;
  while (i < N) {
    int s = X[i++];
    while (i < N && X[i] <= s+R) i++;
    int p = X[i-1];
    cout << "marked X[" << i-1 << "]: " << X[i-1] << endl;
    while (i < N && X[i] <= p+R) i++;
    c++;
  }
  cout << c << endl;
  return;
}

int main() {
  solve();
}
