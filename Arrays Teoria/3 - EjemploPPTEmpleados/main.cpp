#include <iostream>


using namespace std;
int main()
{
	int sueldo[5];
	int horas[5];
	float valorhora;

	cout << "Ingrese el sueldo y la cantidad de horas extra trabajadas de los \
	empleados" << endl;
	for (int cont = 0; cont < 5; cont++)
	{
		cout << "Empleado Nro" << (cont + 1) << ": " << endl;
        cout << "Sueldo: ";
        cin >> sueldo[cont];
		cout << "Horas extra: ";
		cin >> horas[cont];
	}
	cout << "Ingrese el precio hora extra de los empleados: ";
	cin >> valorhora;
	cout << "******* TOTAL POR EMPLEADO ********" << endl;
	cout.precision(2);
	//ios::fixed Se muestran exactamente la cantidad de decimales establecidos en precision
	//ios::showpoint: Muestra 2 decimales siempre, aunque sea X.00
	cout.setf(ios::fixed | ios::showpoint);
	float TotalEmpleado;
	for (int cont = 0; cont < 5; cont++)
	{
 		TotalEmpleado = sueldo[cont] + horas[cont] * valorhora;
		cout << "Empleado Nro" << (cont + 1);
		cout << ": $" << TotalEmpleado << endl;
	}
	return 0;
}
