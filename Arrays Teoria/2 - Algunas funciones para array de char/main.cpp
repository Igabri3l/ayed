#include <iostream>
#include <string.h>
#include <stdio.h>

using namespace std;

int main()
{
  int  longitud;
  char str1[15] = "Hola";
  char str2[15] = ", que tal?";
  //str3 la vamos a inicializar en null (string vac�o):
  char str3[30] = "\0";
  //La siguiente asignaci�n es inv�lida, no debe hacerse:
  //str3= "INVALIDO";
  /********* LECTURA DE TEXTO CON ESPACIOS ***/
  gets(str3); //Si str3 fuera string (C++ se usar�a getline()
  cout << str3 << endl;
  //Se vac�a la cadena, cualquiera de las 2 siguientes l�neas es v�lida:
  //strcpy(str3,"");
  str3[0] = '\0';
  /*********** LONGITUD DE CADENA ************/
  /* Calculemos la longitud de cada uno: */
  longitud = strlen(str1);
  cout << "La longitud de str1 es: " << longitud << endl;
  longitud = strlen(str2);
  cout << "La longitud de str2 es: " << longitud << endl;
  longitud = strlen(str3);
  cout << "La longitud de str3 es: " << longitud << endl;
  /*********** CONCATENACI�N  ****************/
  /*La siguiente l�nea es INVALIDA para el uso de strings como arrays de char,
  s� ser�a v�lida si se usara el tipo de dato string:*/
  //str3 = str1 + str2;
  // Entonces, si queremos poner en str3 la concatenaci�n de str1 y str2:
  strcat(str3, str1);
  strcat(str3, str2);
  cout << "La concatenacion de str1 y str2 es: " << str3 << endl;
  /********** COMPARACION ****************/
  if (strcmp(str1, "Hola") == 0)
    cout << "Las cadenas son iguales" << endl;
  else
    cout << "Las cadenas NO son iguales" << endl;
  /************ BUSQUEDA   ***************/
  // strstr devuelve un puntero a la cadena buscada o nulo si no se encuentra:
  if (strstr(str2, "tal"))
    cout << "El texto 'tal' se encuentra en str2" << endl;
  else
    cout << "El texto 'tal' NO se encuentra en str2" << endl;
  /************ BUSCAR Y REEMPLAZAR ******/
  char* puntero;
  puntero = strstr(str3, "Hola");
  strncpy(puntero, "Buenas", 6);
  cout << str3 << endl;
  return 0;
}
