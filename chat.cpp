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
void init(tChat &ch, string nombre, string owner) {
	init(ch.listaMensajes);
	if (nombre != "" && owner != "") {
		ch.nombre = nombre;
		ch.owner = owner;
		tMensaje msg;
		init(msg, owner, nombre, time(0), INIT_CH_TEXT + owner + ".");

		// La lista sólo tiene un mensaje, por lo que ini y fin deben estar a cero.
		// Es el único caso en el que insertar un mensaje no aumenta el contador.
		// Una tListaMensajesChat no puede estar vacía.
		ch.listaMensajes.l[ch.listaMensajes.fin] = msg;
	}
}

bool cargar(ifstream &file, tChat &ch, string client) {
	file >> ch.nombre;
	bool error = (file.fail() || ch.nombre == CENTINELA);

	if (!error) {
		unsigned short numMensajes;
		file >> numMensajes; // numMensajes es mayor o igual que 1.
		
		tListaMensajesChat lmch;
		error = init(lmch, numMensajes);
		if (!error) error = cargar(file, lmch, ch.nombre, client);
		ch.listaMensajes = lmch;
		ch.owner = ch.listaMensajes.l[0].emisor; // El primer mensaje de un chat siempre existe.
	}
	
	return error;
}

bool guardar(ofstream &file, const tChat &ch) {
	bool error = false;
	file << ch.nombre << endl;
	error = file.fail();
	if (!error) error = guardar(file, ch.listaMensajes);
	return error;
}

void mostrarCabecera(unsigned int i, const tChat &ch) {
	cout << i << ": " << ch.nombre << endl;
	cout << setfill(' ') << setw(L_PADDING) << ' ';
	mostrar(ultimo(ch.listaMensajes));
}