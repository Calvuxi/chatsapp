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
	if (!file.is_open()) return false;
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

bool insertar(tListaChats &lch, tChat &ch) {
	if (lch.counter < MAX_CHATS) {
		lch.l[lch.counter] = ch;
		lch.counter++;
		return false;
	} else return true;
}
