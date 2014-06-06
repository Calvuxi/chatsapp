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
	lch.l = new tChat[10];
	lch.counter = 0;
	lch.capacidad = 10;
}

bool cargar(string filename, tListaChats &lch) {
	ifstream file;
	file.open(filename.c_str());
	if (!file.is_open()) return true;
	else {
		bool error = false; int i = 0, n;

		// Obtener el nombre del cliente:
		string client = filename.substr(0, filename.length() - CHAT_LIST.length());
		file >> n;
		if (lch.l != NULL) delete[] lch.l;
		if (n == 0) init(lch);
		else {
			lch.capacidad = ((n + 9) / 10) * 10;
			lch.l = new tChat[lch.capacidad];
		}
		// Añadir chats:
		while (!error && i<n) {
			tChat ch;
			init(ch);
			error = cargar(file, ch, client);
			if (!error) error = insertar(lch, ch);
			i++;
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
		file << lch.counter << endl;
		while (i < lch.counter && !error) {
			error = guardar(file, lch.l[i]);
			i++;
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
	if (lch.counter < lch.capacidad) {
		lch.l[lch.counter] = ch;
		lch.counter++;
	} else {
		tChat *old = lch.l;
		lch.capacidad = (lch.capacidad*3) / 2 + 1;
		lch.l = new tChat[lch.capacidad];
		for (int i = 0; i < lch.counter; i++) {
			lch.l[i] = old[i];
		}
		delete [] old;
		lch.l[lch.counter] = ch;
		lch.counter++;
	}
	return false;
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
	unsigned short j;
	for (unsigned short i = 0; i < lch.counter - 1; i++) {
		j = getMin(lch, i, lch.counter);
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