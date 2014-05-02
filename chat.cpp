/* --------------- AUTHORS ---------------
- David Pérez (hallaplay835@gmail.com).
- Iván Calvo (calvuxi@gmail.com).
*/

// #### Librerías de sistema ####
#include <fstream>
#include <iostream>
#include <iomanip>

// #### UDLs ####
#include "chat.h"

// #### Namespaces ####

// #### Constantes ####

// #### Declaraciones typedef ####

// #### Implementaciones ####
void init(tChat &ch) {
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

void mostrarCabecera(unsigned int i, const tChat &ch) {
	cout << i << ": " << ch.nombre << endl;
	cout << setfill(' ') << setw(L_PADDING) << ' ';
	mostrar(ultimo(ch.listaMensajes));
}