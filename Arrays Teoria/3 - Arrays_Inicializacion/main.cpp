#include <iostream>
#include <string.h>
using namespace std;

int main()
{
  int v[20];
  /* INICIALIZACION COMPLETA */
  int v1[5] = { 12,78,34,23,66 };
  /* DEFINICION IMPLICITA DE LA DIMENSION POR INICIALIZACION */
  char caracts[] = { 'a','b','C',64 };
  int v2[] = { 4,6,4,2,3 };
  /* INICIALIZACION INCOMPLETA, COMPLETA CON VALORES NULOS: */
  int v3[20] = { 4,6,4,3 };
  /* INICIALIZACION DE STRINGS */
  char palabra[100] = "Esto es un texto";
  cout << palabra << endl;
  strcpy(palabra, "chau");
  cout << palabra << endl;
  strcpy(palabra, "x");
  cout << palabra << endl;
  cout << caracts << endl;
  /* NO SE PUEDEN ASIGNAR VECTORES */
  //v1 = v2;
  /* TAMPOCO SE PUEDE ESTABLECER SU TAMA�O EN TIEMPO DE EJECUCI�N */
  /*
  int tamagno;
  cin >> tamagno;
  int vectam[tamagno];
  */
  return 0;
}
