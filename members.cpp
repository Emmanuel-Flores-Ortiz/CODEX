#include <iostream>
#include <cstdlib>
#include <string>
#include "guildex.h"

void registrarMiembro(Adventurer* &roster, int &cantidad, int &capacidad);
void darDeBaja(Adventurer* roster, int &cantidad);
void buscarMiembro(Adventurer* roster, int cantidad);
void listarMiembros(Adventurer* roster, int cantidad);
void menuMembers(Adventurer* &roster, int &cantidad, int &capacidad);


void registrarMiembro(Adventurer* &roster, int &cantidad, int &capacidad) {
    if (cantidad == capacidad) {
        capacidad = capacidad * 2;
        Adventurer* temp = (Adventurer*) realloc(roster, capacidad * sizeof(Adventurer));
        if (temp == NULL) {
            std::cout << "Error: no se pudo ampliar la memoria." << std::endl;
            return;
        }
        roster = temp;
    }

    Adventurer nuevo;
    nuevo.activo = true;

    std::cout << "Nombre del aventurero: ";
    std::cin >> nuevo.nombre;
    std::cout << "Clase (Guerrero/Mago/Arquero): ";
    std::cin >> nuevo.clase;
    std::cout << "Nivel (1-100): ";
    std::cin >> nuevo.nivel;

    roster[cantidad] = nuevo;
    cantidad = cantidad + 1;

    std::cout << ">> " << nuevo.nombre << " registrado en el gremio." << std::endl;
}


void darDeBaja(Adventurer* roster, int &cantidad) {
    if (cantidad == 0) {
        std::cout << "No hay miembros registrados." << std::endl;
        return;
    }

    std::string nombre;
    std::cout << "Nombre del aventurero a dar de baja: ";
    std::cin >> nombre;

    bool encontrado = false;
    for (int i = 0; i < cantidad; i++) {
        if (roster[i].nombre == nombre && roster[i].activo == true) {
            roster[i].activo = false;
            encontrado = true;
            std::cout << ">> " << nombre << " ha sido dado de baja." << std::endl;
            break;
        }
    }

    if (encontrado == false) {
        std::cout << "No se encontro un miembro activo con ese nombre." << std::endl;
    }
}


void buscarMiembro(Adventurer* roster, int cantidad) {
    if (cantidad == 0) {
        std::cout << "No hay miembros registrados." << std::endl;
        return;
    }

    std::string nombre;
    std::cout << "Nombre a buscar: ";
    std::cin >> nombre;

    bool encontrado = false;
    for (int i = 0; i < cantidad; i++) {
        if (roster[i].nombre == nombre) {
            std::cout << "--- Miembro encontrado ---" << std::endl;
            std::cout << "Nombre: " << roster[i].nombre << std::endl;
            std::cout << "Clase:  " << roster[i].clase  << std::endl;
            std::cout << "Nivel:  " << roster[i].nivel  << std::endl;
            if (roster[i].activo == true) {
                std::cout << "Estado: Activo" << std::endl;
            } else {
                std::cout << "Estado: Inactivo" << std::endl;
            }
            encontrado = true;
            break;
        }
    }

    if (encontrado == false) {
        std::cout << "No se encontro ningun miembro con ese nombre." << std::endl;
    }
}


void listarMiembros(Adventurer* roster, int cantidad) {
    std::cout << "=== ROSTER DEL GREMIO ===" << std::endl;

    bool hayActivos = false;
    for (int i = 0; i < cantidad; i++) {
        if (roster[i].activo == true) {
            std::cout << "[" << (i + 1) << "] "
                      << roster[i].nombre
                      << " | Clase: " << roster[i].clase
                      << " | Nivel: " << roster[i].nivel
                      << std::endl;
            hayActivos = true;
        }
    }

    if (hayActivos == false) {
        std::cout << "No hay miembros activos en el gremio." << std::endl;
    }
}


void menuMembers(Adventurer* &roster, int &cantidad, int &capacidad) {
    int opcion;

    do {
        std::cout << "\n--- MODULO: MIEMBROS ---" << std::endl;
        std::cout << "1 - Registrar aventurero"    << std::endl;
        std::cout << "2 - Dar de baja aventurero"  << std::endl;
        std::cout << "3 - Buscar aventurero"        << std::endl;
        std::cout << "4 - Listar todos los miembros" << std::endl;
        std::cout << "0 - Volver al menu principal" << std::endl;
        std::cout << "Opcion: ";
        std::cin >> opcion;

        switch (opcion) {
            case 1:
                registrarMiembro(roster, cantidad, capacidad);
                break;
            case 2:
                darDeBaja(roster, cantidad);
                break;
            case 3:
                buscarMiembro(roster, cantidad);
                break;
            case 4:
                listarMiembros(roster, cantidad);
                break;
            case 0:
                std::cout << "Volviendo al menu principal..." << std::endl;
                break;
            default:
                std::cout << "Opcion no valida." << std::endl;
        }
    } while (opcion != 0);
}