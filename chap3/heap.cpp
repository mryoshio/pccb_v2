#include <iostream>
#include "../d.h"

#define MAX_N 10000

using namespace std;

int heap[MAX_N];
int n;
int sz = 0;

void push(int x) {
  int i = sz++;

  while (i > 0) {
    int p = (i - 1) / 2;
    if (heap[p] <= x) break;
    heap[i] = heap[p];
    i = p;
  }
  heap[i] = x;
}

int pop() {
  int ret = heap[0];
  int x = heap[--sz];
  int i = 0;

  while (i * 2 + 1 < sz) {
    int a = i * 2 + 1, b = i * 2 + 2;
    if (b < sz && heap[b] < heap[a]) a = b;
    if (heap[a] >= x) break;
    heap[i] = heap[a];
    i = a;
  }
  heap[i] = x;
  return ret;
}

int main() {
  cout << "n: "; cin >> n;
  
  int x;
  while (cin >> x) {
    push(x);
    d(heap, n);
  }
  d(heap, n);
  return 0;
}
