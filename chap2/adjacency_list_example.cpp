#include <iostream>
#include <vector>

using namespace std;

#define MAX_V 100

vector<int> create_undirected_graph() {
  int V, E;
  vector<int> G[MAX_V];
  cout << "V E: ";
  cin >> V >> E;
  for (int i = 0; i < E; i++) {
    int s, t;
    cout << "s t: ";
    cin >> s >> t;
    G[s].push_back(t);
    G[t].push_back(s);
  }
  return G;
}

