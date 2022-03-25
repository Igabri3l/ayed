#include <iostream>
#include <conio.h>
#include "pilas.h"

using namespace std;

int main()
{
  NodoPila* mipila = NULL;
  char letra;
  while ((letra = getche()) != 27)
  {
    push(mipila, letra);
  }
  cout << endl;
  while (mipila)
  {
    cout << pop(mipila);
  }
  getch();
  return 0;
}
