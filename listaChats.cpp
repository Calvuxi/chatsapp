/* --------------- AUTHORS ---------------
- David Pérez (hallaplay835@gmail.com).
- Iván Calvo (calvuxi@gmail.com).
*/

// #### Librerías de sistema ####
#include <fstream>

// #### UDLs ####
#include "listaChats.h"

// #### Namespaces ####

// #### Constantes ####

// #### Declaraciones typedef ####

// #### Implementaciones ####
void init(tListaChats &lch) {
	lch.counter = 0;
}

bool cargar(string filename, tListaChats &lch) {
	ifstream file;
	file.open(filename.c_str());
	if (!file.is_open()) return true;
	else {
		bool error = false; bool end = false;

		// Obtener el nombre del cliente:
		string client = filename.substr(0, filename.length() - CHAT_LIST.length());

		// Añadir chats:
		while (!error && !end) {
			tChat ch;
			init(ch);
			error = cargar(file, ch, client);
			if (!error) error = insertar(lch, ch);
			else if (ch.nombre == CENTINELA) {
				error = false; // Desactivar el flag de error en caso de que fuera el último elemento.
				end = true;
			}
		}
		file.close();

		return error;
	}
}

int buscar(string nombre, const tListaChats &lch) {
	bool found = false; string buff;
	int i = 0;
	if (i < lch.counter) buff = lch.l[i].nombre;
	
	// La lista puede estar ordenada por nombre o fecha; se debe recorrer.
	while (i < lch.counter && !found) {
		if (lch.l[i].nombre == nombre) found = true;
		else i++;
	}
	return (found ? i : -1);
}

bool insertar(tListaChats &lch, tChat &ch) {
	if (lch.counter < MAX_CHATS) {
		lch.l[lch.counter] = ch;
		lch.counter++;
		return false;
	} else return true;
}

bool eliminar(tListaChats &lch, int i) {
	if (lch.counter <= i || i < 0) return true;
	else {

		// Mover los chats hacia la izquierda, sobreescribiendo el del índice.
		for (unsigned short j = i + 1; j < lch.counter; j++) lch.l[j - 1] = lch.l[j];
		lch.counter--;

		return false;
	}
}
