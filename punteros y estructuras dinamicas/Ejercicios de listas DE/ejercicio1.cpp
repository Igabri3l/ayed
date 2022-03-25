#include <iostream>

using namespace std;

struct Mesa
{
  int nroMesa;
  int cantVotos = 0;
};

struct NodoListaDEMesas
{
  Mesa info;             // Datos de el nodo
  NodoListaDEMesas* sgte;  // Puntero al siguiente nodo
  NodoListaDEMesas* ant;
};

void InsertarOrdenado(NodoListaDEMesas*& lista, Mesa m)
{
  NodoListaDEMesas* nuevo;
  if (!lista || m.nroMesa < lista->info.nroMesa)  //insertamos primero
  {
    if (!lista)
    {
      lista = new NodoListaDEMesas();
      lista->info = m;
      lista->ant = NULL;
      lista->sgte = NULL;
    }
    else
    {
      //Creo el nuevo nodo
      nuevo = new NodoListaDEMesas();
      nuevo->info = m;
      nuevo->sgte = lista;
      lista->ant = nuevo;
      nuevo->ant = NULL;
      lista = nuevo;
    }
  }
  else
  {
    NodoListaDEMesas* aux = lista;
    //Creo el nuevo nodo
    nuevo = new NodoListaDEMesas();
    nuevo->info = m;
    nuevo->sgte = NULL;
    nuevo->ant = NULL;
    //Ahora buscamos donde ponerlo
    while (aux->sgte && aux->sgte->info.nroMesa < m.nroMesa)
    {
      aux = aux->sgte;
    }
    if (!aux->sgte) //Estoy en el ultimo nodo de la lista, insertamos ultimo
    {
      nuevo->ant = aux;
      aux->sgte = nuevo;
    }
    else
    {
      aux->sgte->ant = nuevo;
      nuevo->sgte = aux->sgte;
      nuevo->ant = aux;
      aux->sgte = nuevo;
    }
  }
  return;
}

void Recorrer(NodoListaDEMesas* lista)
{
  while (lista)
  {
    cout << "Mesa:" << lista->info.nroMesa << " Votos: " << lista->info.cantVotos << endl;
    lista = lista->sgte;
  }
  return;
}

NodoListaDEMesas* obtenerUltimo(NodoListaDEMesas* lista)
{
  while (lista && lista->sgte)
  {
    lista = lista->sgte;
  }
  return lista;
}

void RecorrerAlReves(NodoListaDEMesas* lista)
{
  while (lista)
  {
    cout << "Mesa:" << lista->info.nroMesa << " Votos: " << lista->info.cantVotos << endl;
    lista = lista->ant;
  }
  return;
}

int main()
{
  NodoListaDEMesas* lista = NULL;
  Mesa m;
  m.nroMesa = 678;
  m.cantVotos = 240;
  InsertarOrdenado(lista, m);
  m.nroMesa = 680;
  m.cantVotos = 130;
  InsertarOrdenado(lista, m);
  m.nroMesa = 679;
  m.cantVotos = 140;
  InsertarOrdenado(lista, m);
  m.nroMesa = 677;
  m.cantVotos = 200;
  InsertarOrdenado(lista, m);
  Recorrer(lista);
  //Obtengo el ultimo para listar al reves
  NodoListaDEMesas* ultimo;
  ultimo = obtenerUltimo(lista);
  RecorrerAlReves(ultimo);

  return 0;
}
