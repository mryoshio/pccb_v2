#include <iostream>

using namespace std;

#define MAX_N 1000

int memo[MAX_N + 1];

int fib(int n) {
  if (n <= 1) return n;
  if (memo[n] != 0) return memo[n];
  return memo[n] = fib(n-1) + fib(n-2);
}

int main() {
  int n;
  cout << "n: ";
  cin >> n;
  for (int i = 0; i < n; i++)
    cout << "fib(" << i << "): " << fib(i) << endl;
}
