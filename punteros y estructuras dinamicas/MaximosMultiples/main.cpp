#include <iostream>
#include <conio.h>

using namespace std;

int main()
{
  int qvalores;
  int* valores;
  int maximo = -1;
  cout << "Ingrese la cantidad de valores a leer:" << endl;
  cin >> qvalores;
  valores = new int[qvalores];
  cout << "(anecdotico, posicion de memoria) valores =" << valores << endl;
  cout << "sizeof(valores) =" << sizeof(valores) << endl;
  cout << "sizeof(*valores) =" << sizeof(*valores) << endl;
  for (int i = 0;i < qvalores; i++)
  {
    cout << "Ingrese el valor " << i << " en la posicion " << (valores + i) << ":" << endl;
    cin >> valores[i]; // cin >> *(valores+i) >> endl;
    if (*(valores + i) > maximo)
      maximo = *(valores + i);
  }
  //RECORREMOS SOLO PARA VERIFICAR INGRESO
  cout << "El maximo es: " << maximo << endl;
  cout << "est� en las posiciones " << endl;
  for (int i = 0;i < qvalores; i++)
  {
    //cout << "valores["<< i << "] = *(valores+" << i << ") = " <<*(valores+i) << endl;; // cin >> *(valores+i) >> endl;
    if (valores[i] == maximo)
      cout << i << " y esta en la posicion de memoria " << (valores + i) << endl;

  }
  getch();
  return 0;
}
