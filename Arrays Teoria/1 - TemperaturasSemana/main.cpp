#include <iostream>

using namespace std;

#define VALORVACIO -200
#define CANTELEM 7

int main()
{
  float temp[CANTELEM];
  cout << temp;

  for (int i = 0; i < CANTELEM;i++)
  {
    temp[i] = VALORVACIO;
  }

  cout << endl;

  cout << "Ingrese la temp del lunes:" << endl;
  cin >> temp[0];
  cout << "Ingrese la temp del martes:" << endl;
  cin >> temp[1];
  cout << "Ingrese la temp del miercoles:" << endl;
  cin >> temp[2];
  cout << "Ingrese la temp del jueves:" << endl;
  cin >> temp[3];
  cout << "Ingrese la temp del viernes:" << endl;
  cin >> temp[4];
  cout << "Ingrese la temp del s�bado" << endl;
  cin >> temp[5];
  cout << "Ingrese la temp del domingo:" << endl;
  cin >> temp[6];
  cout << "Me voy del rango:" << endl;
  cin >> temp[7];
  cout << temp << endl;
  //Se listan todas las temperaturas
  cout << "Las temperaturas fueron:" << endl;
  for (int i = 0; i < CANTELEM + 10; i++)
  {
    cout << temp[i] << endl;
  }
  return 0;
}
