/* --------------- AUTHORS ---------------
- David Pérez (hallaplay835@gmail.com).
- Iván Calvo (calvuxi@gmail.com).
*/

// #### Librerías de sistema ####
#include <fstream>

// #### UDLs ####
#include "listaMensajes.h"
#include "cliente.h"

// #### Namespaces ####

// #### Constantes ####

// #### Declaraciones typedef ####

// #### Implementaciones ####
bool init(tListaMensajes &lm, unsigned short numMensajes) {
	lm.capacidad = ((numMensajes + 9) / 10) * 10;
	lm.l = new tMensaje[lm.capacidad];
	lm.counter = numMensajes;
	return false;
}

bool cargar(ifstream &file, tListaMensajes &lm, string nombre, string client) {
	bool error = false;

	unsigned short i = 0;
	unsigned short numMensajes = lm.counter;
	init(lm);
	while (!error && i < numMensajes) {
		tMensaje msg;
		error = cargar(file, msg, nombre, client);
		if (!error) insertar(lm, msg);
		i++;
	}
	return error;
}

bool insertar(tListaMensajes &lm, tMensaje &msg) {
	bool changes = false;
	if (lm.counter >= lm.capacidad) {
		tMensaje *old = lm.l;
		lm.capacidad = (lm.capacidad * 3) / 2 + 1;
		lm.l = new tMensaje[lm.capacidad];
		for (int i = 0; i < lm.counter; i++) {
			lm.l[i] = old[i];
		}
		delete[] old;
	}
	lm.l[lm.counter] = msg;
	lm.counter++;
	return changes;
}

tMensaje ultimo(const tListaMensajes &lm) {
	return lm.l[lm.counter - 1];
}

bool guardar(ofstream &file, const tListaMensajes &lm) {
	bool error = false;
	file << lm.counter << endl;
	error = file.fail();
	unsigned short i = 0;
	while (i < lm.counter && !error) {
		error = guardar(file, lm.l[i]);
		i++;
	}
	return error;
}

void mostrar(const tListaMensajes &lm, string cliente) {
	unsigned int width = getBuffer();
	for (unsigned short i = 0; i < lm.counter; i++) {
		mostrar(lm.l[i], lm.l[i].emisor == cliente);
		printLine(width, U_SC);
	}
}