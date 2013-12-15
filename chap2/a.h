#include <fstream>

using namespace std;

template<typename T>
void dump(T data, int row, int col) {
  cout << "------------- DUMP" << endl;
  for (int y = 0; y < row; y++) {
    for (int x = 0; x < col; x++)
      cout << data[x][y] << " ";
    cout << endl;
  }
}

template<typename T>
pair<int, int> parse_data(T data, string file_name) {
  ifstream infile;
  string line;
  int row = 0;
  int n = 0;
  int m = 0;

  infile.open(file_name);

  while (!infile.eof()) {
    getline(infile, line);
    const char* buf = line.c_str();
    int col = 0;

    m = max(m, static_cast<int>(line.length()));

    while (*buf) {
      data[col][row] = *buf;
      col++;  
      buf++;
    }
    row++;
  }
  n = row - 1;
  infile.close();

  return make_pair(n, m);
}
