#include <iostream>

using namespace std;

// use case: when not to use array's acutual size 
void d(int *array, int size) {
  cout << "[debug] ";
  for (int i = 0; i < size; i++)
    cout << " | " << array[i];
  cout << " | " << endl;
}

void d(pair<int, int> *array, int size) {
  cout << "[debug] ";
  for (int i = 0; i < size; i++) {
    cout << " | (" << array[i].first;
    cout << ", " << array[i].second << ")";
  }
  cout << " | " << endl;
}

template<typename T>
void d(vector<T> a, int size) {
  cout << "[debug] ";
  for (int i = 0; i < size; i++)
    cout << "|" << a[i];
  cout << "|" << endl;
}

