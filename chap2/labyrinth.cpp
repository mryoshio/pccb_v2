#include <iostream>
#include <fstream>
#include <queue>

#define MAX_N 100
#define MAX_M 100

using namespace std;

//const int INF = 1000000000;
const int INF = 99;

typedef pair<int , int> P;

char maze[MAX_N][MAX_M+1];
int n, m;
int sx, sy;
int gx, gy;

int d[MAX_N][MAX_M];

// express right, down, left, up with two arrays.
// e.g. left: dx[2], dy[2]
int dx[4] = {1, 0, -1, 0}, dy[4] = {0, 1, 0, -1};

int bfs() {
  queue<P> q;

  for (int i = 0; i < n; i++)
    for (int j = 0; j < m; j++) d[i][j] = INF;

  q.push(P(sx, sy));
  d[sx][sy] = 0;

  while(q.size()) {
    P p = q.front(); q.pop();
    if (p.first == gx && p.second == gy) break;

    for (int i = 0; i < 4; i++) {
      int nx = p.first + dx[i], ny = p.second + dy[i];

      if (0 <= nx && nx < n && 0 <= ny && ny < m &&
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

void dump_lab() {
  cout << "------------- dump labyrinth" << endl;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j< m; j++)
      cout << maze[i][j] << " ";
    cout << endl;
  }
}

void dump_d() {
  cout << "------------- dump labyrinth" << endl;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j< m; j++)
      cout << d[i][j] << " ";
    cout << endl;
  }
}

int main() {
  ifstream infile;
  string line;
  int row = 0;
  
  infile.open("labyrinth.txt");

  while (!infile.eof()) {
    getline(infile, line);

    m = max(m, static_cast<int>(line.length()));
    const char* buf = line.c_str();
    int col = 0;

    while (*buf) {
      maze[row][col] = *buf;
      switch (*buf) {
      case 'S':
          sx = col, sy = row;
      case 'G':
          gx = col, gy = row;
      }
      col++;
      buf++;
    }
    row++;
  }
  n = row - 1;
  infile.close();
  solve();
  dump_lab();
  dump_d();
  return 0;
}
