#include <iostream>

using namespace std;

class Node {
public:
  int val;
  Node *lnd, *rnd;
  Node(int v): val(v) {}
};

int main() {
  Node *n = new Node(3);
  cout << n->val << endl;
  return 0;
}
