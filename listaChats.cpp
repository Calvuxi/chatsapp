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

bool guardar(string filename, const tListaChats &lch) {
	ofstream file;
	file.open(filename.c_str());
	if (!file.is_open()) return true;
	else {
		bool error = false;
		unsigned short i = 0;
		while (i < lch.counter && !error) {
			error = guardar(file, lch.l[i]);
			i++;
		}
		file << CENTINELA;
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

void mover(tListaChats &lch, unsigned short ind) {
	tChat ch = lch.l[ind];
	for (unsigned short i = ind; i < lch.counter - 1; i++) lch.l[i] = lch.l[i + 1];
	lch.l[lch.counter - 1] = ch;
}

void ordenarN(tListaChats &lch) {
	for (unsigned short i = 1; i < lch.counter; i++) {
		tChat elem = lch.l[i];
		unsigned short pos = i - 1;
		bool found = lch.l[pos].nombre <= elem.nombre;
		while (pos > 0 && !found) {
			lch.l[pos + 1] = lch.l[pos];
			pos--;
			found = lch.l[pos].nombre <= elem.nombre;
		}
		if (found) lch.l[pos + 1] = elem;
		else {
			lch.l[1] = lch.l[0];
			lch.l[0] = elem;
		}
	}
}

void ordenarF(tListaChats &lch) {
	for (unsigned short i = 0; i < lch.counter - 1; i++) {
		unsigned short j = getMin(lch, i + 1, lch.counter);
		if (j > i) swap(lch, i, j);
	}
}

unsigned short getMin(tListaChats &lch, unsigned short i, unsigned short j) {
	unsigned short k = i;
	time_t elem = ultimo(lch.l[k].listaMensajes).fecha;
	while (i < j) {
		if (ultimo(lch.l[i].listaMensajes).fecha < elem) {
			k = i;
			elem = ultimo(lch.l[k].listaMensajes).fecha;
		}
		i++;
	}
	return k;
}

void swap(tListaChats &lch, unsigned short i, unsigned short j) {
	tChat tmp = lch.l[j];
	lch.l[j] = lch.l[i];
	lch.l[i] = tmp;
}