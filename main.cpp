//
// Created by alfre on 12/06/2026.
//

#include <iostream>
#include "Guildex.h"
#include "asset.h"


#include <cstdlib>
using namespace std;

int main() {

    int cantMiembros = 0;
    int capMiembros = 0;

    while (capMiembros <= 0) {
        cout << "capacidad de Miembros: ";
        cin >> capMiembros;

        if (capMiembros <= 0) {
            cout << "El gremio debe iniciar con al menos 1 espacio disponible.\n" << endl;
        }
    }

    cout << capMiembros << " Espacios" << endl;

    Adventurer* rosterGremio = (Adventurer*) calloc(capMiembros, sizeof(Adventurer));

    if (rosterGremio == NULL) {
        cout << "No se pudo iniciar el sistema." << endl;
        return 1;
    }

    cout << "Cargando interfaz" << endl;

    menuPrincipal(rosterGremio, cantMiembros, capMiembros);

    cout << "\n Liberando los recursos" << endl;

    free(rosterGremio);
    rosterGremio = NULL;

    cout << "Programa cerrado limpiamente." << endl;
    return 0;
}