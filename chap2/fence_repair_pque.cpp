#include <iostream>
#include <queue>

#define MAX_LEN 50000

using namespace std;

int N, L[MAX_LEN];

void solve() {
  long ans = 0;

  priority_queue<int, vector<int>, greater<int> > q;
  for (int i = 0; i < N; i++)
    q.push(L[i]);

  while (q.size() > 1) {
    int l1, l2;
    l1 = q.top(); q.pop();
    l2 = q.top(); q.pop();

    ans += l1 + l2;
   q.push(l1 + l2);   
 }
 cout << ans << endl;
}

int main() {
  cout << "N: ";
  cin >> N;
  for (int i = 0; i < N; i++) {
    cout << "input L[" << i << "]";
    cin >> L[i];
  }
  solve();
}
