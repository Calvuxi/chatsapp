/* --------------- AUTHORS ---------------
- David Pérez (hallaplay835@gmail.com).
- Iván Calvo (calvuxi@gmail.com).
*/

// #### Librerías de sistema ####
#include <fstream>

// #### UDLs ####
#include "listaMensajesChat.h"
#include "cliente.h"

// #### Namespaces ####

// #### Constantes ####

// #### Declaraciones typedef ####

// #### Implementaciones ####
bool init(tListaMensajesChat &lmch, unsigned short numMensajes) {
	if (numMensajes <= MAX_MENSAJES) {
		lmch.ini = 0;
		lmch.fin = numMensajes - 1; // Representa la última posición ocupada.
		return false;
	}
	else return true;
}

bool cargar(ifstream &file, tListaMensajesChat &lmch, string nombre, string client) {
	bool error = false;

	unsigned short i = 0;
	unsigned short numMensajes = lmch.fin + 1;
	init(lmch);
	while (!error && i < numMensajes) {
		tMensaje msg;
		error = cargar(file, msg, nombre, client);
		if (!error) insertar(lmch, msg);
		i++;
	}
	return error;
}

void insertar(tListaMensajesChat &lmch, const tMensaje &msg) {
	if (next(lmch.fin) == lmch.ini) { // Está lleno.
		tMensaje oldmsg = lmch.l[lmch.ini]; // Mensaje a guardar en el histórico.
		lmch.ini = next(lmch.ini);
		lmch.fin = next(lmch.fin);
	}
	lmch.l[lmch.fin] = msg;
}

tMensaje ultimo(const tListaMensajesChat &lmch) {
	return lmch.l[lmch.fin];
}

bool guardar(ofstream &file, const tListaMensajesChat &lmch) {
	bool error = false;
	file << (next(lmch.fin) == lmch.ini ? MAX_MENSAJES : lmch.fin + 1) << endl;
	error = file.fail();
	unsigned short i = lmch.ini;
	while (i != lmch.fin) {
		error = guardar(file, lmch.l[i]);
		i = next(lmch, i);
	}
	if (lmch.ini != lmch.fin) error = guardar(file, lmch.l[i]); // Si no está vacío.
	return error;
}

void mostrar(const tListaMensajesChat &lmch, string cliente) {
	unsigned int width = getBuffer();
	unsigned short i = lmch.ini;
	while (i != lmch.fin) {
		mostrar(lmch.l[i], lmch.l[i].emisor == cliente);
		printLine(width, U_SC);
		i = next(lmch, i);
	}
	if (lmch.ini != lmch.fin) { // Si no está vacío.
		mostrar(lmch.l[i], lmch.l[i].emisor == cliente);
		printLine(width, U_SC);
	}
}

unsigned short next(const tListaMensajesChat &lmch, unsigned short i) {
	return (i + 1) % MAX_MENSAJES;
}