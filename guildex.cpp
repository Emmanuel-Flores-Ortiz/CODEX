#include "guildex.h"
#include <string>

struct Quest {
	std::string lugar;
	std::string personajeInvolucrado;
	int numeroDePersonajes;
	std::string accion;
	int recompensa;
	bool completada;
};
