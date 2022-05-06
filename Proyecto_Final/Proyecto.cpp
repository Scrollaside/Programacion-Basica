#include <iostream>
#include <string>
#include <conio.h>
using namespace std;

struct citas {
	string nombre;
	string hora;
	char opcion;
	int costo = 0;
	int trat = 0;
	string telefono;
	string nomtrat;
};
char menu;

void main() {
	system("color E");
	int i = 0;
	int j = 0;
	//K
	citas cita[3];


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
			if (i < 3) {
				system("cls");
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
			else {
				cout << "Maximo de citas alcanzado!" << endl;
			}
			system("pause");
		}
		else if (menu == '2') {
			cout << "\nEsa opcion aun no esta disponible!" << endl;
			system("pause");
		}
		else if (menu == '3') {
			cout << "\nEsa opcion aun no esta disponible!" << endl;
			system("pause");
		}
		else if (menu == '4') {
			system("cls");
			if (j != 0) {
				for (int k = 0; k < j; k++) {
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
			system("pause");
		}
		else if (menu != '1' && menu != '2' && menu != '3' && menu != '4' && menu != '5') {
			cout << "Esa opcion es invalida!" << endl;
			system("pause");
		}
	}
	cout << "\nCerrando sistema, que tenga un buen dia." << endl;

	system("pause");

}
