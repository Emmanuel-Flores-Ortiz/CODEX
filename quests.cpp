#include <iostream>
#include <string>
#include "guildex.h"

void questManager();

int main() {
    questManager();
    return 0;
}

void questManager() {
    int n;
    std::cout << "Escribe el n£mero de quests: " << std::endl;
    std::cin >> n;
    Quest* q = static_cast<Quest*>(calloc(n, sizeof(Quest)));

    for (int i = 0; i < n; ++i) {
        std::cout << std::endl;
        std::cout << "MISION " << (i + 1) << std::endl;
        std::cout << "Nombre de la misi¢n: " << std::endl;
        std::cin >> (*(q + i)).nombre;
        std::cout << "Lugar de la misi¢n: " << std::endl;
        std::cin >> (*(q + i)).lugar;
        std::cout << "Quin otorga la misi¢n: " << std::endl;
        std::cin >> (*(q + i)).personajeInvolucrado;
        std::cout << "Cu ntos personajes participan: " << std::endl;
        std::cin >> (*(q + i)).numeroDePersonajes;
        std::cout << "Descripci¢n: " << std::endl;
        std::cin >> (*(q + i)).accion;
        std::cout << "Recompensa (unidades): " << std::endl;
        std::cin >> (*(q + i)).recompensa;
        std::cout << "¨Est  completada? (true/false): " << std::endl;
        std::cin >> (*(q + i)).completada;
        std::cout << std::endl;
    }

    bool exit = false;
    int option = 0;

    while (!exit) {
        std::cout << "¨Qu deseas hacer?" << std::endl;
        std::cout << "1 - Agregar misi¢n" << std::endl;
        std::cout << "2 - Eliminar misi¢n" << std::endl;
        std::cout << "3 - Salir" << std::endl;
        std::cin >> option;
        switch (option) {
            case 1: {
                q = static_cast<Quest*>(realloc(q, ++n * sizeof(Quest)));
                std::cout << std::endl;
                std::cout << "MISION " << n << std::endl;
                std::cout << "Nombre de la misi¢n: " << std::endl;
                std::cin >> (*(q + (n - 1))).nombre;
                std::cout << "Lugar de la misi¢n: " << std::endl;
                std::cin >> (*(q + (n - 1))).lugar;
                std::cout << "Quin otorga la misi¢n: " << std::endl;
                std::cin >> (*(q + (n - 1))).personajeInvolucrado;
                std::cout << "Cu ntos personajes participan: " << std::endl;
                std::cin >> (*(q + (n - 1))).numeroDePersonajes;
                std::cout << "Descripci¢n: " << std::endl;
                std::cin >> (*(q + (n - 1))).accion;
                std::cout << "Recompensa (unidades): " << std::endl;
                std::cin >> (*(q + (n - 1))).recompensa;
                std::cout << "¨Est  completada? (true/false): " << std::endl;
                std::cin >> (*(q + (n - 1))).completada;
                std::cout << std::endl;
                break;
            };
            case 2: {
                q = static_cast<Quest*>(realloc(q, --n * sizeof(Quest)));
                break;
            };
            case 3: {
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
    free(q);
}
