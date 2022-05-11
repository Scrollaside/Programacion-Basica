#include <iostream>
#include <string>
#include <conio.h>
#include <windows.h>
#include <fstream>

using namespace std;

struct citas {
	string nombre;
	string hora;
	char opcion;
	int costo = 0;
	int trat = 0;
	string telefono;
	string nomtrat;
	int NumCit;
};

ofstream myfile("Citas.txt");
string line;
ifstream archivo;

//int* NumCit_ptr = nullptr;

//Declaraciones----------------------------------------------------
	char menu;
	int i = 0;
	int j = 0;
	int k = 0;
	citas cita[1000];
	float IngCit = 0;
//Declaraciones----------------------------------------------------

	void Opcion1();
	void Opcion2();
	void Opcion3();
	void Opcion4();
	
void main() {
	system("color E");
	
	while (menu != '5') {
		system("cls");
		cout << "Bienvenido, al menu para ajendar una cita dental" << endl;

		cout << "\nPresiona 1 para agendar una cita (Maximo 3 citas)" << endl;
		cout << "Presiona 2 para modificar tu cita" << endl;
		cout << "Presiona 3 para eliminar una cita" << endl;
		cout << "Presiona 4 para ver la lista de citas vigentes" << endl;
		cout << "Presiona 5 para salir del sistema" << endl;
		menu = _getch();

		if (menu == '1') {
			system("cls");
			Opcion1();
			system("pause");
		}
		else if (menu == '2') {
			Opcion2();
			system("pause");
		}
		else if (menu == '3') {
			Opcion3();
			system("pause");
		}
		else if (menu == '4') {
			system("cls");
			Opcion4();
			system("pause");
		}
		else if (menu != '1' && menu != '2' && menu != '3' && menu != '4' && menu != '5') {
			cout << "Esa opcion es invalida!" << endl;
			system("pause");
		}
		
		if (j != 0) {
			ofstream myfile("Citas.txt");
			for (int k = 0; k < j; k++) {

				myfile << "Cita " << k + 1 << endl;
				myfile << "Nombre: " << cita[k].nombre << endl;
				myfile << "Telefono: " << cita[k].telefono << endl;
				myfile << "Hora: " << cita[k].hora << endl;
				myfile << "Tratamiento: " << cita[k].opcion << "# " << cita[k].nomtrat << endl;
				myfile << "Costo: $" << cita[k].costo << endl;
				myfile << " " << endl;

			}
		}
	}
	cout << "\nCerrando sistema, que tenga un buen dia." << endl;

	system("pause");
}

//------------------------------------------------------------------------------------------------------------------------------------
void Opcion1() {
	
	cita[i].NumCit = i;
	
	cout << "Cita " << i + 1 << endl;
	cout << "> Ingrese su nombre:" << endl;
	cin.ignore(0, '\n');
	getline(cin, cita[i].nombre);

	cout << "> Ingresa la hora de la cita, en formato de 24 horas. (ej: 13:00)" << endl;
	cin.ignore(0, '\n');
	getline(cin, cita[i].hora);

	cout << "> Ingresa el tratamiento que desea aplicar" << endl;
	cout << "\n1# Limpieza dental" << endl;
	cout << "Limpieza dental completa, lavado a presion de dientes." << endl;
	cout << "Costo: $200 por tratamiento" << endl;
	cout << "\n2# Extraccion de caries" << endl;
	cout << "Extraccion de caries, curacion de encias, lavado de la zona afectada." << endl;
	cout << "Costo: $400 por tratamiento" << endl;
	cout << "\n3# Ortodoncia" << endl;
	cout << "Inicio del tratamiento para correguir dentadura, se seguira varios meses conforme al nivel de tratamiento" << endl;
	cout << "Costo: $500 por nivel de tratamiento" << endl;

	while (cita[i].costo == 0) {
		cin >> cita[i].opcion;
		switch (cita[i].opcion) {
		case '1':
			cita[i].costo = 200;
			cita[i].nomtrat = "Limpieza Dental";
			break;

		case '2':
			cita[i].costo = 400;
			cita[i].nomtrat = "Extraccion de Caries";
			break;

		case '3':
			cita[i].costo = 500;
			cita[i].nomtrat = "Ortodoncia";
			break;

		default:
			cout << "Esa opcion es invalida" << endl;
			cita[i].costo = 0;
			cita[i].nomtrat = "N/A";
			break;
		}
	}

	cout << "> Ingrese el nivel del tratamiento, con un numero" << endl;
	cin >> cita[i].trat;
	cita[i].costo *= cita[i].trat;
	cout << "Costo final: $" << cita[i].costo << endl;

	cout << "\n> Ingrese su numero de telefono" << endl;
	cin.ignore();
	getline(cin, cita[i].telefono);

	cout << "\nCita agendada!" << endl;
	cout << "Se le avisara si su cita sufre algun cambio de imprevisto." << endl;
	i++;
	j++;
	
}
void Opcion2() {
	if (j != 0) {
		system("cls");
		cout << "Ingrese el numero de cita que desea modificar: ";
		char h = 'a';
		cin >> IngCit;
		//IngCit = 1;
		IngCit -= 1;
		for (k = 0; k < j; k++) {
			if (IngCit == cita[k].NumCit) {
				cout << cita[k].nombre << endl;
				
				h = 'b';
			}
		}
		if (h == 'a') {
			cout << "No existe esa cita" << endl;
		}
	}
	else {
		cout << "\nAun no hay citas registradas" << endl;
	}
}
void Opcion3() {
	cout << "\nEsa opcion aun no esta disponible!" << endl;
}
void Opcion4() {
	
	if (j != 0) {
		for (k = 0; k < j; k++) {

			cout << "Cita " << k + 1 << endl;
			cout << "Nombre: " << cita[k].nombre << endl;
			cout << "Telefono: " << cita[k].telefono << endl;
			cout << "Hora: " << cita[k].hora << endl;
			cout << "Tratamiento: " << cita[k].opcion << "# " << cita[k].nomtrat << endl;
			cout << "Costo: $" << cita[k].costo << endl;
			cout << " " << endl;
		}
	}
	else {
		cout << "No hay citas agendadas!" << endl;
	}
}
