#include <iostream>
#include <queue>
#include "a.h"

#define MAX_N 100
#define MAX_M 100

using namespace std;

const int INF = 1000000000;
typedef pair<int, int> P;

char maze[MAX_N][MAX_M+1];
int N, M;
int sx, sy, gx, gy;
int d[MAX_N][MAX_M];

// express right, down, left, up with two arrays.
// e.g. left: dx[2], dy[2]
int dx[4] = {1, 0, -1, 0}, dy[4] = {0, 1, 0, -1};

int bfs() {
  queue<P> q;

  for (int i = 0; i < N; i++)
    for (int j = 0; j < M; j++) d[i][j] = INF;

  q.push(P(sx, sy));
  d[sx][sy] = 0;

  while(q.size()) {
    P p = q.front(); q.pop();
    if (p.first == gx && p.second == gy) break;

    for (int i = 0; i < 4; i++) {
      int nx = p.first + dx[i], ny = p.second + dy[i];

      if (0 <= nx && nx < N && 0 <= ny && ny < M &&
          maze[nx][ny] != '#' && d[nx][ny] == INF) {
        q.push(P(nx, ny));
        d[nx][ny] = d[p.first][p.second] + 1;
      }
    }
  }
  return d[gx][gy];
}

void solve() {
  int res = bfs();
  printf("%d\n", res);
}

int main() {
  pair<int, int> p = parse_data(maze, "labyrinth.txt");
  N = p.first;
  M = p.second;
  for (int y = 0; y < N; y++) {
    for (int x = 0; x < M; x++) {
      switch (maze[x][y]) {
      case 'S':
        sx = x, sy = y;
        break;
      case 'G':
        gx = x, gy = y;
        break;
      }
    }
  }
  dump(maze, N, M);
  solve();
  return 0;
}
