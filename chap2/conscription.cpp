#include "../common.h"

#define MAX_R 50000

int N, M, R;
int x[MAX_R], y[MAX_R], d[MAX_R];

using namespace std;

int prim() {
  int V = N + M;
  int mincost[MAX_R];
  bool used[MAX_R];

  for (int i = 0; i < V; i++) {
    mincost[i] = INT_MAX;
    used[i] = false;
  }

  mincost[0] = 0;
  int res = 0;

  while (true) {
    int v = -1;
    for (int u = 0; u < V; u++)
      if (!used[u] && (v == -1 || mincost[u] < mincost[v]))
        v = u;
    if (v == -1) break;
    used[v] = true;
    res += mincost[v];
    for (int u = 0; u < V; u++)
      mincost[u] = min(mincost[u], d[u]);
  }
  return res;
}

void solve() {
  cout << 10000 * (N + M) + prim() << endl;
}

void input() {
  N = 5; M = 5; R = 8;
  int rels[8][3] = {
    { 4, 3, 6831 }, { 1, 3, 4583 },
    { 0, 0, 6592 }, { 0, 1, 3063 },
    { 3, 3, 4975 }, { 1, 3, 2049 },
    { 4, 2, 2104 }, { 2, 2, 781 }
  };
  for (int i = 0; i < 8; i++) {
    x[i] = rels[i][0];
    y[i] = rels[i][1];
    d[i] = rels[i][2];
  }
}

int main() {
  input();

  solve();
  return 0;
}
