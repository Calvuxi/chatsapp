/* --------------- AUTHORS ---------------
- David P�rez (hallaplay835@gmail.com).
- Iv�n Calvo (calvuxi@gmail.com).
*/

// #### Librer�as de sistema ####

// #### UDLs ####
#include "listaMensajes.h"

// #### Namespaces ####

// #### Constantes ####

// #### Declaraciones typedef ####

// #### Implementaciones ####
bool init(tListaMensajes &lm, unsigned short numMensajes) {
	if (numMensajes <= MAX_MENSAJES) {
		lm.counter = numMensajes;
		return false;
	} else return true;
}

bool cargar(ifstream &file, tListaMensajes &lm, string nombre, string client) {
	bool error = false;

	unsigned short i = 0;
	unsigned short numMensajes = lm.counter;
	init(lm);
	while (!error && i < numMensajes) {
		tMensaje msg;
		error = cargar(file, msg, nombre, client);
		if (!error) error = insertar(lm, msg);
		i++;
	}
	return error;
}

bool insertar(tListaMensajes &lm, tMensaje &msg) {
	if (lm.counter < MAX_MENSAJES) {
		lm.l[lm.counter] = msg;
		lm.counter++;
		return false;
	}
	else return true;
}