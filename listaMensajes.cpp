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
		if (!error) insertar(lm, msg);
		i++;
	}
	return error;
}

bool insertar(tListaMensajes &lm, tMensaje &msg) {
	bool changes = false;
	tMensaje oldmsg = msg;
	if (lm.counter >= MAX_MENSAJES) {
		changes = true;

		oldmsg = lm.l[0]; // Mensaje a guardar en el histórico.

		// Mover los mensajes hacia la izquierda, eliminando el más antiguo.
		for (unsigned short i = 1; i < lm.counter; i++) lm.l[i - 1] = lm.l[i];
		lm.counter--;
	}

	lm.l[lm.counter] = msg;
	lm.counter++;
	msg = oldmsg;

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