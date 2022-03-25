/* EJERCICIO 5 */
#include <stdio.h> //Se agrega para poder usar archivos
#include <iostream>
#include <conio.h>
#include <cstring>
using namespace std;

struct Medicion
{
  int medicionID;
  int instrumentoID;
  char fechahora[14];
  float valor;
  char unidad;
};

struct NodoListaMediciones
{
  Medicion info;             // Datos de el nodo
  NodoListaMediciones* sgte;  // Puntero al siguiente nodo
};

NodoListaMediciones* ObtenerUltimaMedicion(NodoListaMediciones* p)
{
  if (p)
  {
    while (p->sgte)
    {
      p = p->sgte;
    }
  }
  return p;
}

void ListarMediciones(NodoListaMediciones* lista)
{
  while (lista)
  {
    cout << "======== DATOS DE LA MEDICION " << lista->info.medicionID << "========" << endl;
    cout << "ID Instrumento, Medicion: " << lista->info.instrumentoID << ", " << lista->info.medicionID << endl;
    cout << "FECHA Y HORA: " << lista->info.fechahora << endl;
    cout << "Valor: " << lista->info.valor << " " << lista->info.unidad << endl;
    lista = lista->sgte;
  }
}

int main()
{
  FILE* f;
  NodoListaMediciones* l = NULL;
  NodoListaMediciones* aux = NULL;
  NodoListaMediciones* aux2 = NULL;
  Medicion m;
  if (f = fopen("mediciones.data", "rb"))
  {
    fread(&m, sizeof(Medicion), 1, f);
    while (!feof(f))
    {
      aux = ObtenerUltimaMedicion(l);
      if (aux)
      {
        aux2 = new NodoListaMediciones();
        aux2->info = m;
        aux2->sgte = NULL;
        aux->sgte = aux2;
      }
      else
      {
        l = new NodoListaMediciones();
        l->info = m;
        l->sgte = NULL;
      }
      fread(&m, sizeof(Medicion), 1, f);
    }
    fclose(f);
  }
  char op;
  do
  {
    cout << "Ingrese una opcion: " << endl;
    cout << "1   ->Agregar una medicion." << endl;
    cout << "2   ->Listar toda la lista." << endl;
    cout << "Esc -> Salir." << endl;
    do
    {
      op = getch();
    } while (op != 27 && op != '1' && op != '2');
    switch (op)
    {
    case '1':
      cout << "Ingrese ID instrumento:" << endl;
      cin >> m.instrumentoID;
      cout << "Ingrese ID medicion:" << endl;
      cin >> m.medicionID;
      cout << "Ingrese fechahora:" << endl;
      cin >> m.fechahora;
      cout << "Ingrese valor:" << endl;
      cin >> m.valor;
      cout << "Ingrese unidad:" << endl;
      cin >> m.unidad;
      aux = ObtenerUltimaMedicion(l);
      if (aux)
      {
        aux2 = new NodoListaMediciones();
        aux2->info = m;
        aux2->sgte = NULL;
        aux->sgte = aux2;
      }
      else
      {
        l = new NodoListaMediciones();
        l->info = m;
        l->sgte = NULL;
      }
      break;
    case '2':
      ListarMediciones(l);
      break;
    }
  } while (op != 27);
  //SALIR: GUARDA TODA LA LISTA EN EL ARCHIVO
  aux = l;
  if (f = fopen("mediciones.data", "wb"))
  {
    while (aux)
    {
      fwrite(&(aux->info), sizeof(Medicion), 1, f);
      aux2 = aux;
      aux = aux->sgte;
      delete aux2;
    }
    fclose(f);
  }
  return 0;
}
