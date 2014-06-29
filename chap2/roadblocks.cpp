#include <iostream>
#include <vector>
#include <queue>
#include <climits>
#include "../common.h"

#define MAX_N 10000

using namespace std;

int N, R;
vector<edge> G[MAX_N];


int dist[MAX_N];
int dist2[MAX_N];

void solve()
{
  priority_queue<P, vector<P>,  greater<P> > q;
  fill(dist, dist + N, INT_MAX);
  fill(dist2, dist2 + N, INT_MAX);
  dist[0] = 0;
  q.push(P(0, 0));

  while (!q.empty()) {
    P p = q.top(); q.pop();
    int v = p.second, d = p.first;
    if (dist2[v] < d) continue;
    for (int i = 0; i < G[v].size(); i++) {
      edge &e = G[v][i];
      int d2 = d + e.cost;
      if (dist[e.to] > d2) {
        swap(dist[e.to], d2);
        q.push(P(dist[e.to], e.to));
      }
      if (dist2[e.to] > d2 && dist[e.to] < d2) {
        dist2[e.to] = d2;
        q.push(P(dist2[e.to], e.to));
      }
    }
  }
  cout << dist2[N - 1] << endl;
}

/*
  --- Sample Input, Output
  1 2 100
  2 3 250
  2 4 200
  3 4 100
  #=> 450
*/
int main()
{
  N = 4; R = 4; // temporary fixed
  for (int i = 0; i < R; i++) {
    int from, to, cost;
    cout << "FROM TO COST: ";
    cin >> from >> to >> cost;
    from--; to--;
    G[from].push_back((edge){ to, cost });
    G[to].push_back((edge){ from, cost });
  }
  solve();
}
