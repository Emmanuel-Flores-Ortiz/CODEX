#include <iostream>
#include <string>
#include "guildex.h"

// Módulo 3 - Quests
// Trabajado por eduardo55722

void readQuestWithGetline(Quest &q);
void readQuestWithCin(Quest &q);
void questManager();

int main() {
    questManager();
    return 0;
}

void readQuestWithGetline(Quest &q) {
    std::cout << "Nombre de la misi¢n: " << std::endl;
	std::getline(std::cin, q.nombre);
    std::cout << "Lugar de la misi¢n: " << std::endl;
	std::getline(std::cin, q.lugar);
    std::cout << "Quin otorga la misi¢n: " << std::endl;
	std::getline(std::cin, q.personajeInvolucrado);
    std::cout << "Cu ntos personajes participan: " << std::endl;
    std::cin >> q.numeroDePersonajes;
    std::cout << "Descripci¢n: " << std::endl;
	std::getline(std::cin, q.accion);
    std::cout << "Recompensa (unidades): " << std::endl;
    std::cin >> q.recompensa;
    std::cout << "¨Est  completada? (true/false): " << std::endl;
	std::cin >> q.completada;
}

void readQuestWithCin(Quest &q) {
    std::cout << "Nombre de la misi¢n: " << std::endl;
	std::cin >> q.nombre;
	std::cin.ignore();
    std::cout << "Lugar de la misi¢n: " << std::endl;
	std::cin >> q.lugar;
	std::cin.ignore();
    std::cout << "Quin otorga la misi¢n: " << std::endl;
	std::cin >> q.personajeInvolucrado;
	std::cin.ignore();
    std::cout << "Cu ntos personajes participan: " << std::endl;
    std::cin >> q.numeroDePersonajes;
	std::cin.ignore();
    std::cout << "Descripci¢n: " << std::endl;
	std::cin >> q.accion;
	std::cin.ignore();
    std::cout << "Recompensa (unidades): " << std::endl;
    std::cin >> q.recompensa;
	std::cin.ignore();
    std::cout << "¨Est  completada? (true/false): " << std::endl;
	std::cin >> q.completada;
	std::cin.ignore();
}

void questManager() {
    int n;
    std::cout << "Escribe el n£mero de quests: " << std::endl;
    std::cin >> n;
	std::cin.ignore();
    auto* q = new Quest[n];

    for (int i = 0; i < n; ++i) {
        std::cout << std::endl;
        std::cout << "MISION " << (i + 1) << std::endl;
		readQuestWithCin(*(q + i));
        std::cout << std::endl;
    }

    bool exit = false;
    int option = 0;
    int indice = 0;

    while (!exit) {
        option = 0;
        std::cout << "N£mero de misiones: " << n << std::endl;
        std::cout << "¨Qu deseas hacer?" << std::endl;
        std::cout << "1 - Ver detalles de misi¢n" << std::endl;
        std::cout << "2 - Modificar misi¢n" << std::endl;
        std::cout << "3 - Agregar misi¢n" << std::endl;
        std::cout << "4 - Eliminar misi¢n" << std::endl;
        std::cout << "5 - Salir" << std::endl;
        std::cin >> option;
        switch (option) {
            case 1: {
				// Ver detalles de misión
                std::cout << "¨Qu misi¢n se desea ver?" << std::endl;
                std::cin >> indice;
                if (indice <= 0 || indice > n) {
                    std::cout << "No existe una misi¢n con ese ¡ndice." << std::endl;
                } else {
                    std::cout << std::endl;
                    std::cout << "MISION " << indice << std::endl;
                    --indice;
                    std::cout << "Nombre de la misi¢n: " << (*(q + indice)).nombre << std::endl;
                    std::cout << "Lugar de la misi¢n: " << (*(q + indice)).lugar << std::endl;
                    std::cout << "Quin otorga la misi¢n: " << (*(q + indice)).personajeInvolucrado << std::endl;
                    std::cout << "Personajes participantes: " << (*(q + indice)).numeroDePersonajes << std::endl;
                    std::cout << "Descripci¢n: " << (*(q + indice)).accion << std::endl;
                    std::cout << "Recompensa: " << (*(q + indice)).recompensa << " unidades" << std::endl;
                    std::cout << "¨Completada?: " << ((*(q + indice)).completada ? "S¡" : "No") << std::endl;
                    std::cout << std::endl;
                }
            };
            case 2: {
				// Modificar misión
                std::cout << "¨Qu misi¢n se desea modificar?" << std::endl;
                std::cin >> indice;
                if (indice <= 0 || indice > n) {
                    std::cout << "No existe una misi¢n con ese ¡ndice." << std::endl;
                } else {
                    --indice;
                    std::cout << std::endl;
					readQuestWithCin(*(q + indice));
                    std::cout << std::endl;
                }
                break;
            };
            case 3: {
				// Agregar misión
                q = new Quest[++n];
                std::cout << std::endl;
                std::cout << "MISION " << n << std::endl;
				readQuestWithCin(*(q + (n - 1)));
                std::cout << std::endl;
                break;
            };
            case 4: {
                // Eliminar misión
                std::cout << "¨Qu misi¢n se desea eliminar?" << std::endl;
                std::cin >> indice;
                if (indice <= 0 || indice > n) {
                    std::cout << "No existe una misi¢n con ese ¡ndice." << std::endl;
                } else {
                    --indice;
                    for (int i = 0; i < n - 1; i++) {
                        if (i >= indice) {
                            *(q + i) = *(q + i + 1);
                        }
                    }
                }
                q = new Quest[--n];
                break;
            };
            case 5: {
				// Salir
                std::cout << "Saliendo" << std::endl;
                exit = true;
                break;
            };
            default: {
                std::cout << "Ingresa una opci¢n v lida, por favor." << std::endl;
            };
        }
        std::cout << std::endl;
    }
    delete q;
}
