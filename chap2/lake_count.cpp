#include <iostream>
#include <fstream>

#define N 10
#define M 12

using namespace std;

char lake[10][12];

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

void dump_lake() {
  cout << "------------- dump lake" << endl;
  for (int i = 0; i< 10; i++) {
    for (int j = 0; j< 12; j++)
      cout << lake[i][j] << " ";
    cout << endl;
  }
}

int main() {
  for (int i = 0; i< 10; i++)
    for (int j = 0; j< 12; j++)
      lake[i][j] = '.';

  ifstream infile;
  string line;
  int row = 0;
  
  infile.open("lake_count.txt");

  while (!infile.eof()) {
    getline(infile, line);

    int col = 0;
    const char* buf = line.c_str();

    while (*buf) {
      lake[row][col] = *buf;
      col++;  
      buf++;
    }
    row++;
  }
  infile.close();
  solve();
  return 0;
}
