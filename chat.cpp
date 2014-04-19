/* --------------- AUTHORS ---------------
- David Pérez (hallaplay835@gmail.com).
- Iván Calvo (calvuxi@gmail.com).
*/

// #### Librerías de sistema ####
#include <fstream>

// #### UDLs ####
#include "chat.h"

// #### Namespaces ####

// #### Constantes ####

// #### Declaraciones typedef ####

// #### Implementaciones ####
void init(tChat &ch) {
	ch.nombre = "";
	ch.owner = "";
	init(ch.listaMensajes);
}

bool cargar(ifstream &file, tChat &ch, string client) {
	file >> ch.nombre;
	bool error = (file.fail() || ch.nombre == CENTINELA);

	if (!error) {
		unsigned short numMensajes;
		file >> numMensajes; // numMensajes es mayor o igual que 1.
		
		tListaMensajes lm;
		error = init(lm, numMensajes);
		if (!error) error = cargar(file, lm, ch.nombre, client);
		ch.listaMensajes = lm;
		ch.owner = ch.listaMensajes.l[0].emisor; // El primer mensaje de un chat siempre existe.
	}
	
	return error;
}