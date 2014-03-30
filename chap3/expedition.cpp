#include <iostream>
#include <queue>
using namespace std;

#define MAX_N 10000
#define MAX_L 1000000

int N, L, P;
int A[MAX_L], B[100];

void solve() {
  priority_queue<int> q;

  // first gas station
  P -= A[0];
  q.push(B[0]);

  for (int i = 1; i < N; i++) {
    while (P < (A[i] - A[i-1])) {
      if (q.empty()) {
        cout << -1 << endl;
        return;
      }
      cout << "[supply] " << q.top() << endl;
      P += q.top();
      q.pop();
    }
    P -= (A[i] - A[i-1]);
    q.push(B[i]);
  }
  if (P >= L - A[N-1]) puts("OK");
  else cout << -1 << endl;
}

int main() {
  cout << "N L P: "; cin >> N >> L >> P;
  for (int i = 0; i < N; i++) {
    cout << "A[" << i << "] B[" << i << "]: ";
    cin >> A[i] >> B[i];
  }
  solve();
  return 0;
}
