#include <iostream>
#include <conio.h>
#include <stdio.h>
#include <stdlib.h>
#define LONG 10000
#define VACIO -1
using namespace std;

struct Estudiante
{
  int estudianteID;
  string nombre;
  int agno;
  double promedio;
};

typedef  Estudiante mi_tdato;

/*
Procedimiento mostrarEstudiante
Pre: Recibe un estudiante por par�metro para mostrarlo en pantalla.
La estructura debe estar inicializada.
Post: Si la estructura no es vac�a se muestran sus miembros por pantalla.
El criterio de vac�o es un EstudianteID = -1
*/
void mostrarEstudiante(mi_tdato e)
{
  if (e.estudianteID != VACIO)
  {
    cout << endl << "***Datos del estudiante***" << endl;
    cout << "Id:" << e.estudianteID << endl;
    cout << "nombre:" << e.nombre << endl;
    cout << "A�o:" << e.agno << endl;
    cout << "Promedio:" << e.promedio << endl;
  }
  return;
}

/*
Funci�n leerEstudiante
Pre: Recibe un estudiante por par�metro (por referencia) para completar sus datos
Post: El usuario ingresa por teclado los valores de cada miembro y se devuelve la
estructura como resultado.
NO se asigna el ID, ya que el mismo es incremental, y para ello debe conocerse
la cantidad de elementos en el vector, por lo tanto, esta tarea se deja para el subprograma
"Insertar".
*/
mi_tdato leerEstudiante(mi_tdato& e)
{
  cout << "Ingrese nombre" << endl;
  cin >> e.nombre;
  cout << "Ingrese a�o de ingreso" << endl;
  cin >> e.agno;
  cout << "Ingrese promedio" << endl;
  cin >> e.promedio;
  return e;
}

/*
Procedimiento inicializar
Pre: Recibe un vector de estudiantes por par�metro para mostrarlo en pantalla.
Post: Vac�a cada �ndice del vector. El criterio de vac�o es un EstudianteID = -1
*/
void inicializar(mi_tdato v[])
{
  for (int i = 0; i < LONG; i++)
  {
    v[i].estudianteID = VACIO;
  }
  return;
}

/*
Procedimiento mostrar
Pre: Recibe un vector de estudiantes por par�metro para mostrarlo en pantalla.
Notar el "const" indicando que , aunque el vector se pasa por referencia
(recordar que no hace falta para vectores el "&" para pasar por referencia),
sus datos no ser�n modificados.
Post: Recorre el vector y, posicionado en cada �ndice si el estudiante no es vac�o
lo muestra por pantalla. Corta al encontrar la primer posici�n vac�a.
*/
void mostrar(const mi_tdato v[])
{
  int i = 0;
  while ((i < LONG) && (v[i].estudianteID != VACIO))
  {
    mostrarEstudiante(v[i]);
    i++;
  }
  return;
}


//Copia dos vectores
void copiar(const mi_tdato origen[], mi_tdato destino[])
{
  for (int i = 0; i < LONG; i++)
  {
    destino[i] = origen[i];
  }
  return;
}

/* Funci�n insertar.
Pre: Recibe por par�metros el dato a insertar y el vector.
Post: Intenta insertarlo en el primer lugar que encuentre vac�o, si lo hace devuelve
cero, si el vector est� lleno devuelve c�digo de error= 1 */
int insertar(mi_tdato dato, mi_tdato v[])
{
  int i = 0;
  int error = 0;
  while (i < LONG && v[i].estudianteID != VACIO)
    i++;
  if (i < LONG)
  {
    dato.estudianteID = i + 1; //+1 para no poner id 0 al primer estudiante
    v[i] = dato;
  }

  else
    error = 1;
  return error;
}

/* Funci�n cantElementos.
Pre: Recibe por par�metros el vector de estructura estudiante. No modifica sus datos as�
que se indica el "const".
Post: Devuelve la cantidad de elementos distintos de vac�o que hay en el vector.*/
int cantElementos(const mi_tdato vec[])
{
  int i = 0;
  while (i < LONG && vec[i].estudianteID != VACIO)
    i++;
  return i;

}

/*Ordenamiento por burbujeo mejorado, ordena seg�n el a�o de ingreso*/
void burbujaXagno(mi_tdato v[])
{
  mi_tdato aux;
  int j = 0;
  int tamlogico;
  tamlogico = cantElementos(v);
  for (int i = 0; i < tamlogico - 1; i++)
  {
    for (j = 0; j < tamlogico - 1 - i; j++)
    {
      if (v[j + 1].agno < v[j].agno)
      {
        aux = v[j];
        v[j] = v[j + 1];
        v[j + 1] = aux;
      }
    }
  }
}

/*Ordenamiento por burbujeo mejorado, ordena seg�n ID del estudiante*/
void burbujaXID(mi_tdato v[])
{
  mi_tdato aux;
  int j = 0;
  int tamlogico;
  tamlogico = cantElementos(v);
  for (int i = 0; i < tamlogico - 1; i++)
  {
    j = 0;
    for (j = 0; j < tamlogico - 1 - i; j++)
    {
      if (v[j + 1].estudianteID < v[j].estudianteID)
      {
        aux = v[j];
        v[j] = v[j + 1];
        v[j + 1] = aux;
      }
    }
  }
}

int busquedaBinaria(const mi_tdato vec[], int idbuscado)
{
  bool encontrado = false;
  int Iarriba = cantElementos(vec) - 1;
  int Iabajo = 0;
  int Icentro;
  int result = -1;
  while (Iabajo <= Iarriba && !encontrado)
  {
    Icentro = (Iarriba + Iabajo) / 2;
    if (vec[Icentro].estudianteID == idbuscado)
    {
      result = Icentro;
      encontrado = true;
    }
    else
    {
      if (idbuscado < vec[Icentro].estudianteID)
        Iarriba = Icentro - 1;
      else
        Iabajo = Icentro + 1;
    }
  }
  return result; // si no encontrado devuelve -1
}


void mostrarmenu()
{
  cout << "Ingrese una opci�n:" << endl;
  cout << "a - Inicializar vector" << endl;
  cout << "b - Ingresar un valor" << endl;
  cout << "c - Mostrar vector" << endl;
  cout << "d - Copiar vector" << endl;
  cout << "e - Ordenar vector por a�o de ingreso" << endl;
  cout << "f - Indicar cantidad de elementos" << endl;
  cout << "g - Buscar elemento" << endl;
  cout << "Esc - Salir" << endl;
}

int main()
{
  mi_tdato vec[LONG];
  mi_tdato vec2[LONG];
  mi_tdato dato;

  char opcion;
  do
  {
    mostrarmenu();
    do
    {
      opcion = getch();
    } while (opcion != 27 &&
      !(opcion >= 'A' && opcion <= 'G') &&
      !(opcion >= 'a' && opcion <= 'g')
      );
    switch (opcion)
    {
    case 'a':
    case 'A':
      inicializar(vec);
      break;
    case 'b':
    case 'B':
      cout << "Ingrese los datos del estudiante" << endl;
      leerEstudiante(dato);
      if (insertar(dato, vec) != 0)
        cout << "Error al intentar ingresar el dato. Vector lleno" << endl;
      else
        cout << "Dato ingresado correctamnte" << endl;

      break;
    case 'c':
    case 'C':
      mostrar(vec);
      break;
    case 'd':
    case 'D':
      /*aunque no tiene mucho sentido (porque vec2 no se
      vuelve a utilizar, esta l�nea copia vec en vec2) */
      copiar(vec, vec2);
      break;
    case 'e':
    case 'E':
      burbujaXagno(vec);
      break;
    case 'f':
    case 'F':
      cout << "La cantidad de elementos es " << cantElementos(vec) << endl;
      break;
    case 'g':
    case 'G':
      int idestudiante;
      cout << "Ingrese el id del estudiante a buscar: " << endl;
      cin >> idestudiante;
      int posicion;
      burbujaXID(vec);
      posicion = busquedaBinaria(vec, idestudiante);
      if (posicion != -1)
        cout << "El elemento se encuentra en la posicion: " << posicion << endl;
      else
        cout << "No se encuentra el elemento.";
      break;
    }
    cout << "Presione una tecla para continuar" << endl;
    getch();
    system("cls");

  } while ((int)opcion != 27); //27 es el c�digo ascii de la tecla Esc. Tengo que convertirlo a int para obtener su c�digo en tabla
  return 0;
}
