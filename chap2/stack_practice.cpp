#include <iostream>
#include <stack>

using namespace std;

int main() {
  stack<int> s;
  s.push(2);
  cout << "size is " << s.size() << endl;
  cout << "top is " << s.top() << endl;
  s.pop();
  cout << "size is " << s.size() << endl;
}
