#include <iostream>
#include <vector>

#define MAX_V 100

using namespace std;

vector<int> G[MAX_V];

void vertex_test() {
  int V, E;
  cin >> V >> E;
  int i;
  for (i = 0; i < E; i++) {
    int s, t;
    cin >> s >> t;
    G[s].push_back(t);
    // G[t].push_back(s); // when undirected graph
  }
  for (i = 0; i < MAX_V; i++)
    if (G[i].size() > 0) {
      cout << "[" << i << "] ";
      vector<int>::iterator it = G[i].begin();
      while (it != G[i].end()) {
        cout << *it << ", ";
        it++;
      }
      cout << endl;
    }
}

int main() {
  vertex_test();
}
