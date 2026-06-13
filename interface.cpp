#include <iostream>
#include "guildex.h"
#include "interface.h"

#include "quests.h"
using namespace std;

void menuPrincipal() {
	//miembros
	int cantidadM=0;
	int capacidadM=2;
	Adventurer* roster =new Adventurer[capacidadM];


	//inventario
	Inventario Ninventario;
	Ninventario.total_de_casillas=0;
	Ninventario.lista_de_casilla=nullptr;
	string x_decorativa = "====================================================\n";
	string y_decorativa = "----------------------------------------------------\n";

	int id_objeto=0;
	int cantidadobjeto=0;

	int opcion;

	do {

		cout << "\n===== GX =====\n";
		cout << "1. Miembros\n";
		cout << "2. Inventario\n";
		cout << "3. Misiones\n";
		cout << "0. Salir\n";
		cin >> opcion;

		switch(opcion) {

			case 1:
				menuMembers(roster, cantidadM,  capacidadM);
				break;

			case 2:
				menuInventario(Ninventario, id_objeto, cantidadobjeto, opcion, x_decorativa, y_decorativa);

				break;

			case 3:
				questManager();
				break;

			case 0:
				cout << "Adios.\n";
				break;

			default:
				cout << "Opcion invalida.\n";
		}

	} while(opcion != 0);
	delete [] roster;
	if (Ninventario.lista_de_casilla != nullptr) {
		delete [] Ninventario.lista_de_casilla;
	}
}