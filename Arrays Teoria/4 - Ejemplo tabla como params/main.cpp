/*********************************** TABLAS ***********************************/

#include <iostream>
#include <ctime>
#include <cstdlib>
#define M 10
#define N 10
using namespace std;


void alterar_tabla(int t[][N])
{
  t[1][1] = 27;
  return;
}

int main()
{
  int tabla[M][N];
  //cargo los datos de la tabla con algunos valores
  //vamos a generar n�meros random, primero inicializamos el random:
  srand(time(0));
  for (int i = 0; i < M; i++)
  {
    for (int j = 0; j < N; j++)
    {
      tabla[i][j] = rand() % 100;
    }
  }
  alterar_tabla(tabla);
  //Ahora mostramos todos los elementos cargados:
  for (int i = 0; i < M; i++)
  {
    for (int j = 0; j < N; j++)
    {
      cout << tabla[i][j] << " ";
    }
    cout << endl;
  }
  return 0;


}
