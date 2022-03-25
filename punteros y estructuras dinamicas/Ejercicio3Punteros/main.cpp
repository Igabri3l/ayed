#include <iostream>

using namespace std;

void CrearVectorYLeerValores(int*& vec, int tam)
{
  vec = new int[tam];
  for (int i = 0; i < tam; i++)
  {
    cout << "vec[" << i << "] = ";
    cin >> vec[i];
  }
  return;
}

int* buscarMax(int* vec, int tam)
{
  int* dirMax;
  dirMax = vec;
  for (int i = 1;i < tam;i++)
  {
    if (*(vec + i) > *dirMax)
      dirMax = vec + i;
  }
  return dirMax;
}

int main()
{
  int tam;
  int* maxi = NULL;
  int* ptr = NULL;
  cout << "Ingrese el tama�o de la muestra" << endl;
  cin >> tam;
  CrearVectorYLeerValores(ptr, tam);
  maxi = buscarMax(ptr, tam);
  cout << "El maximo es: " << *maxi << " en " << maxi << endl;
  return 0;
}
