#include <iostream>
#include <vector>
using namespace std;

int main() {
  long n;
  cout << "n: "; cin >> n;

  if (n == 0 || n == 1) {
    cout << "fibo(" << n << ") is " << n << endl;
    return 0;
  }

  vector<long> v(n, 1);
  v[0] = 0; v[1] = 1;

  for (long i = 2; i < n; i++)
    v[i] = v[i-1] + v[i-2];

  cout << "fibo(" << n << ") is " << v[n-1] << endl;

  return 0;
}
