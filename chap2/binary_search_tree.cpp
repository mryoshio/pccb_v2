#include <iostream>
#include <stack>

using namespace std;

class Node {
public:
  int val;
  Node *left, *right;
  Node(int v): val(v) {}
};

Node *insert(Node *p, int x) {
  if (p == nullptr) {
    Node *n = new Node(x);
    n->left = n->right = nullptr;
    return n;
  } else {
    if (x < p->val) p->left = insert(p->left, x);
    else p->right = insert(p->right, x);
    return p;
  }
}

bool find(Node *p, int x) {
  if (p == nullptr) return false;
  else if (x == p->val) return true;
  else if (x < p->val) return find(p->left, x);
  else return find(p->right, x);
}

Node *remove(Node *p, int x) {
  if (p == nullptr) return nullptr;
  else if (x < p->val) remove(p->left, x);
  else if (x > p->val) remove(p->right, x);
  else if (p->left == nullptr) {
    Node *q = p->right;
    delete p;
    return q;
  } else if (p->left->right == nullptr) {
    Node *q = p->left;
    q->right = p->right;
    delete p;
    return q;
  } else {
    Node *q;
    for (q = p->left; q->right != nullptr; q = q->right);
    q->left = p->left;
    q->right = p->right;
    delete p;
    return q;
  }
  return p;
}

void d_tree(Node *p) {
  if (p->left != nullptr)
    d_tree(p->left);

  cout << p->val << " ";

  if (p->right != nullptr)
    d_tree(p->right);
}

int main() {
  Node *r = insert(nullptr, 4);
  insert(r, 5);
  insert(r, 7);
  insert(r, 3);
  insert(r, 1);
  insert(r, 10);
  d_tree(r);
  cout << endl;
  return 0;
}
