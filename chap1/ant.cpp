#include <iostream>

using namespace std;

const int MAX_N = 10^6;
int l, n, x[MAX_N];

void input() {
  cout << "l: ";
  cin >> l;

  cout << "n: ";
  cin >> n;

  for (int i = 0; i < n; i++) {
    printf("%d's distance: ", i);
    cin >> x[i];
  }
}

void solve() {

  int min_t = 1;
  for (int i = 0; i < n; i++)
    min_t = max(min_t, min(x[i], l - x[i]));

  int max_t = 1;
  for (int i = 0; i < n; i++)
    max_t = max(max_t, max(x[i], l - x[i]));

  cout << "min: " << min_t << endl;
  cout << "max: " << max_t << endl;
}

int main() {
  input();
  solve();
  return 0;
}
