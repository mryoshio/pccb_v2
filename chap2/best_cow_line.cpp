#include <iostream>

using namespace std;

// p.45

#define MAX_N 2000

int N;
char S[MAX_N + 1];

void solve() {
  int a = 0;
  int b = N - 1;
  bool left;
  
  while (a <= b) {
    // see insider chars if S[a] == S[b] in loop
    for (int i = 0; a + i <= b; i++) {
      if (S[a+i] < S[b-i]) {
        left = true;
        break;
      } else if (S[a+i] > S[b-i]) {
        left = false;
        break;
      }
    }
    if (left) putchar(S[a++]);
    else putchar(S[b--]);
  }
  cout << endl;
  return;
}

int main() {
  cout << "input some string: ";
  cin >> S;
  N = strlen(S);
  solve();
}
