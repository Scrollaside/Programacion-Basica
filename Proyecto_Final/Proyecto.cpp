#include <iostream>
#include <string>
#include <conio.h>
#include <windows.h>
#include <fstream>

using namespace std;
//
struct citas {
	string nombre;
	string hora;
	char opcion;
	int costo = 0;
	int trat = 0;
	string telefono;
	string nomtrat;
	int NumCit = 0;
};

ofstream myfile("Citas.txt");

//Declaraciones----------------------------------------------------
	char menu;
	int i = 0;
	int j = 0;
	int k = 0;
	citas cita[1000];
	float IngCit = 0;
	char opcion2;
	char h;
//Declaraciones----------------------------------------------------

	void Opcion1();
	void Opcion2();
	void Opcion3();
	void Opcion4();
	
void main() {
	system("color E");
	
	while (menu != '5') {
		system("color E");
		system("cls");
		cout << "Bienvenido al menu para ajendar una cita dental" << endl;

		cout << "\n> Presiona 1 para agendar una cita." << endl;
		cout << "> Presiona 2 para modificar tu cita." << endl;
		cout << "> Presiona 3 para eliminar una cita." << endl;
		cout << "> Presiona 4 para ver la lista de citas vigentes." << endl;
		cout << "> Presiona 5 para salir del sistema." << endl;
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

				myfile << "Cita #" << k + 1 << endl;
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

//--------------------------------------------------------------------------------------------------------------------------------------------
//--------------------------------------------------------------------------------------------------------------------------------------------

void Opcion1() {
	
	cita[i].NumCit = i;
	
	cout << "Cita #" << i + 1 << endl;
	cout << "> Ingrese su nombre:" << endl;
	getline(cin, cita[i].nombre);

	cout << "> Ingresa la hora de la cita, en formato de 24 horas. (ej: 13:00): " << endl;
	cin.ignore(0, '\n');
	getline(cin, cita[i].hora);

	cout << "> Ingresa el tratamiento que desea aplicar: " << endl;
	cout << "\n1# Limpieza dental" << endl;
	cout << "Limpieza dental completa, lavado a presion de dientes." << endl;
	cout << "Costo: $200 por tratamiento" << endl;
	cout << "\n2# Extraccion de caries" << endl;
	cout << "Extraccion de caries, curacion de encias, lavado de la zona afectada." << endl;
	cout << "Costo: $400 por tratamiento." << endl;
	cout << "\n3# Ortodoncia" << endl;
	cout << "Inicio del tratamiento para correguir dentadura, se seguira varios meses conforme al nivel de tratamiento." << endl;
	cout << "Costo: $500 por nivel de tratamiento." << endl;

	while (cita[i].costo == 0) {
		system("color E");
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
			system("color C");
			cout << "Esa opcion es invalida." << endl;
			cita[i].costo = 0;
			cita[i].nomtrat = "N/A";
			break;
		}
	}

	cout << "> Ingrese el nivel del tratamiento, con un numero: " << endl;
	cin >> cita[i].trat;
	cita[i].costo *= cita[i].trat;
	cout << "Costo final: $" << cita[i].costo << endl;

	cout << "\n> Ingrese su numero de telefono: " << endl;
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
		cout << "> Ingrese el numero de cita que desea modificar: ";
		opcion2;
		h = 'a';
		cin >> IngCit;
		cin.ignore();
		
		IngCit -= 1;
		for (k = 0; k < j; k++) {
			if (IngCit == cita[k].NumCit) {
				cout << "Cita #" << k + 1 << endl;
				cout << "Nombre: " << cita[k].nombre << endl;
				cout << "Telefono: " << cita[k].telefono << endl;
				cout << "Hora: " << cita[k].hora << endl;
				cout << "Tratamiento: " << cita[k].opcion << "# " << cita[k].nomtrat << endl;
				cout << "Costo: $" << cita[k].costo << endl;
				
				cout << "\n> Seleccione la opcion que quiere modificar:" << endl;
				cout << "1.- Nombre" << endl;
				cout << "2.- Hora" << endl;
				cout << "3.- Tratamiento y Nivel" << endl;
				cout << "4.- Telefono" << endl;
				cout << "5.- Cancelar" << endl;

				while (h == 'a') {
					cin >> opcion2;
					cin.ignore();
					switch (opcion2) {
					case '1':
						cout << "Nombre actual: " << cita[k].nombre << endl;
						cout << "Nombre nuevo: ";
						getline(cin, cita[k].nombre);
						cout << "Cambio aplicado!" << endl;
						h = 'b';
						break;
					case '2':
						cout << "Hora agendada: " << cita[k].hora << endl;
						cout << "Hora nueva: ";
						cin.ignore();
						getline(cin, cita[k].hora);
						cout << "Cambio aplicado!" << endl;
						h = 'b';
						break;
					case '3':
						cout << "Tratamiento actual: " << cita[k].opcion << "# " << cita[k].nomtrat << endl;
						cout << "Costo actual: $" << cita[k].costo << endl;
						cout << "Tratamiento nuevo: " << endl;

						cout << "\n1# Limpieza dental" << endl;
						cout << "Limpieza dental completa, lavado a presion de dientes." << endl;
						cout << "Costo: $200 por tratamiento" << endl;
						cout << "\n2# Extraccion de caries" << endl;
						cout << "Extraccion de caries, curacion de encias, lavado de la zona afectada." << endl;
						cout << "Costo: $400 por tratamiento" << endl;
						cout << "\n3# Ortodoncia" << endl;
						cout << "Inicio del tratamiento para correguir dentadura, se seguira varios meses conforme al nivel de tratamiento." << endl;
						cout << "Costo: $500 por nivel de tratamiento" << endl;

						cita[k].costo = 0;
						while (cita[k].costo == 0) {
							cin >> cita[k].opcion;
							switch (cita[k].opcion) {
							case '1':
								cita[k].costo = 200;
								cita[k].nomtrat = "Limpieza Dental";
								break;

							case '2':
								cita[k].costo = 400;
								cita[k].nomtrat = "Extraccion de Caries";
								break;

							case '3':
								cita[k].costo = 500;
								cita[k].nomtrat = "Ortodoncia";
								break;

							default:
								cout << "Esa opcion es invalida" << endl;
								cita[k].costo = 0;
								cita[k].nomtrat = "N/A";
								break;
							}
						}

						cout << "> Ingrese el nivel del tratamiento, con un numero: " << endl;
						cin >> cita[k].trat;
						cin.ignore();
						cita[k].costo *= cita[k].trat;
						cout << "Costo final: $" << cita[k].costo << endl;
						cout << "Cambio aplicado!" << endl;
						h = 'b';
						break;
					case '4':
						cout << "Telefono actual: " << cita[k].telefono << endl;
						cout << "Telefono nuevo: ";
						cin.ignore();
						getline(cin, cita[k].telefono);
						cout << "Cambio aplicado!" << endl;
						h = 'b';
						break;
					case '5':
						cout << "Cancelando, volviendo al menu principal." << endl;
						h = 'b';
						break;
					default:
						cout << "Esa opcion es invalida!" << endl;
						break;
					}
				}
			}
		}
		if (h == 'a') {
			system("color C");
			cout << "No existe esa cita, revise la lista de citas." << endl;
			cout << "Regresando al menu principal." << endl;
		}
	}
	else {
		cout << "\nAun no hay citas registradas" << endl;
	}
}
void Opcion3() {
	if (j != 0) {
		system("cls");
		cout << "> Ingrese el numero de cita que desea eliminar: ";
		
		h = 'a';
		cin >> IngCit;
		cin.ignore();
		
		IngCit -= 1;
		for (k = 0; k < j; k++) {
			if (IngCit == cita[k].NumCit) {
				cout << "Cita #" << k + 1 << endl;
				cout << "Nombre: " << cita[k].nombre << endl;
				cout << "Telefono: " << cita[k].telefono << endl;
				cout << "Hora: " << cita[k].hora << endl;
				cout << "Tratamiento: " << cita[k].opcion << "# " << cita[k].nomtrat << endl;
				cout << "Costo: $" << cita[k].costo << endl;
				cout << "\n> Presione 1 para confirmar, presione cualquier otra tecla para cancelar." << endl;
				h = _getch();
				if (h == '1') {
					IngCit += 1;
					if (IngCit == i) {
						i -= 1;
						j -= 1;
						cout << "Registro recorrido." << endl;
					}
					cita[k].nombre = "N/A";
					cita[k].telefono = "N/A";
					cita[k].hora = "N/A";
					cita[k].opcion = '0';
					cita[k].costo = 00;
					cita[k].trat = 00;
					cita[k].nomtrat = "N/A";
					cita[k].NumCit = 00;

					cout << "\nCita eliminada!" << endl;
					IngCit -= 1;
				}
				else {
					cout << "\nCancelando, volviendo al menu principal." << endl;
				}
				
			}
		}
		if (h == 'a') {
			system("color C");
			cout << "No existe esa cita, revise la lista de citas." << endl;
			cout << "Regresando al menu principal." << endl;
		}
	}
	else {
		cout << "\nAun no hay citas registradas!" << endl;
	}
}
void Opcion4() {
	
	if (j != 0) {
		system("cls");
		for (k = 0; k < j; k++) {

			cout << "Cita #" << k + 1 << endl;
			cout << "Nombre: " << cita[k].nombre << endl;
			cout << "Telefono: " << cita[k].telefono << endl;
			cout << "Hora: " << cita[k].hora << endl;
			cout << "Tratamiento: " << cita[k].opcion << "# " << cita[k].nomtrat << endl;
			cout << "Costo: $" << cita[k].costo << endl;
			cout << " " << endl;
		}
	}
	else {
		cout << "\nAun no hay citas registradas!" << endl;
	}
}
