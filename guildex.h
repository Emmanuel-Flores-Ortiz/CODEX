#include <string>
#ifndef GUILDEX_H
#define GUILDEX_H



struct Quest {
	std::string nombre;
	std::string lugar;
	std::string personajeInvolucrado;
	int numeroDePersonajes;
	std::string accion;
	int recompensa;
	bool completada;
};
struct Adventurer {
	std::string nombre;
	std::string clase;
	int nivel;
	bool activo;

};
struct Objeto {
	int id;
	std::string nombre;
	std::string categoria;
};
struct Casilla_del_objeto {
	int id = 0;
	int cantidad = 0;
};

struct Inventario {
	Casilla_del_objeto* lista_de_casilla;
	int total_de_casillas;
};

// Funciones de Miembros
void menuMembers(Adventurer* &roster, int &cantidad, int &capacidad);
void registrarMiembro(Adventurer* &roster, int &cantidad, int &capacidad);

// Funciones de tu Inventario
void agregarObjeto(Inventario& el_inventario, int &id_objeto, int &cantidad, int &opcion, std::string &x, std::string &y);
void buscarObjeto(Inventario& el_inventario, int &id_objeto, int &opcion, std::string &x, std::string &y);
void listadoObjetos(Inventario& el_inventario, int &opcion,  std::string &y);
void totalObjetos(Inventario& el_inventario, int &opcion, std::string &y);

void imprimirObjeto(Inventario& el_inventario, int &opcion,  std::string &y);
void menuObjetos(std::string &x, std::string &y, int &opcion);
void menuInventario(Inventario& el_inventario, int &id_objeto, int &cantidad, int &opcion, std::string &x, std::string &y);

// Funciones de Misiones


void questManage();

#endif