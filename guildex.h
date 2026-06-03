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

#endif