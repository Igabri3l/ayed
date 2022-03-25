#include <iostream>

using namespace std;

int main()
{
  int v[200];
  for (int i = 0; i < 200;i++)
    v[i] = i;
  int* p;
  p = &v[199];
  do
  {
    cout << *p << endl;
    p--;
  } while (p != v);
  cout << *p << endl;
  return 0;
}
