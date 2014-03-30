#include <iostream>
#include <queue>

using namespace std;

int main() {
  priority_queue<int> q;
  q.push(1);
  q.push(3);
  q.push(5);
  q.push(7);
  q.push(9);
  q.push(2);
  q.push(4);
  q.push(6);
  q.push(8);
  while (! q.empty()) {
    cout << q.top() << endl; // print max val in queue
    q.pop();
  }
}
