#include <iostream>
#include <queue>

using namespace std;

int main() {
  queue<int> q;
  q.push(2);
  cout << "size is " << q.size() << endl;
  cout << "front is " << q.front() << endl;
  q.pop();
  cout << "size is " << q.size() << endl;
}
