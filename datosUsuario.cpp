/* --------------- AUTHORS ---------------
- David Pérez (hallaplay835@gmail.com).
- Iván Calvo (calvuxi@gmail.com).
*/

// #### Librerías de sistema ####
#include <fstream>

// #### UDLs ####
#include "datosUsuario.h"

// #### Namespaces ####

// #### Constantes ####

// #### Declaraciones typedef ####

// #### Implementaciones ####
void init(tDatosUsuario &du) {
	du.usuario = "";
	init(du.buzon);
}

bool cargar(ifstream &file, tDatosUsuario &du) {
	file >> du.usuario;
	bool error = (file.fail() || du.usuario == CENTINELA);

	if (!error) {
		unsigned short numMensajes;
		file >> numMensajes;

		tListaMensajes lm;
		error = init(lm, numMensajes);
		if (!error) error = cargar(file, lm, du.usuario);
		du.buzon = lm;
	}

	return error;
}

bool guardar(ofstream &file, const tDatosUsuario &du) {
	bool error = false;
	file << du.usuario << endl;
	error = file.fail();
	if (!error) error = guardar(file, du.buzon);
	return error;
}