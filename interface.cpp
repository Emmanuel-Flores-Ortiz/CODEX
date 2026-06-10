#include <iostream>
#include "guildex.h"
#include "interface.h"
#include "quests.h"
#include "Inventory.cpp"
#include "members.cpp"
using namespace std;

void menuPrincipal() {

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
				registrarMiembro();
				break;

			case 2:
				agregarObjeto();
				break;

			case 3:
				questManage();
				break;

			case 0:
				cout << "Adios.\n";
				break;

			default:
				cout << "Opcion invalida.\n";
		}

	} while(opcion != 0);
}