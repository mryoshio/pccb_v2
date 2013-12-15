#include <iostream>
#include "a.h"

#define MAX_N 100
#define MAX_M 100

using namespace std;

int N, M;
char lake[MAX_N][MAX_M];

void dfs(int x, int y) {
  lake[x][y] = '.';

  for (int dx = -1; dx <= 1; dx++)
    for (int dy = -1; dy <= 1; dy++) {
      int nx = x + dx, ny = y + dy;

      if (0 <= nx && nx < N && 
          0 <= ny && ny < M &&
          lake[nx][ny] == 'W') dfs(nx, ny);
    }
  return;
}

void solve() {
  int res = 0;
  for (int i = 0; i < N; i++)
    for (int j = 0; j < M; j++)
      if (lake[i][j] == 'W') {
        dfs(i, j);
        res++;
      }
  printf("%d\n", res);
}

int main() {
  pair<int, int> p = parse_data(lake, "lake_count.txt");
  N = p.first;
  M = p.second;
  dump(lake, N, M);
  solve();
  return 0;
}
