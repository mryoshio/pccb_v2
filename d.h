#include <iostream>

using namespace std;

void d(int *array, int border) {
  cout << "[debug] ";
  for (int i = 0; i < border; i++)
    cout << " | " << array[i];
  cout << " | " << endl;
}
