/* --------------- AUTHORS ---------------
- David Pérez (hallaplay835@gmail.com).
- Iván Calvo (calvuxi@gmail.com).
*/

// #### Librerías de sistema ####

// #### UDLs ####
#include "listaUsuarios.h"
#include <fstream>

// #### Namespaces ####

// #### Constantes ####

// #### Declaraciones typedef ####

// #### Implementaciones ####
void init(tListaUsuarios &db) {
	db.counter = 0;
}

bool cargar(string filename, tListaUsuarios &db) {
	ifstream file;
	file.open(filename.c_str());
	if (!file.is_open()) return false;
	else {
		bool error = false; bool end = false;
		
		// Añadir datos de usuario:
		while (!error && !end) {
			tDatosUsuario du;
			init(du);
			error = cargar(file, du);
			if (!error) error = insertar(db, du);
			else if (du.usuario == CENTINELA) {
				error = false; // Desactivar el flag de error en caso de que fuera el último elemento.
				end = true;
			}
		}
		file.close();

		return error;
	}
}

bool insertar(tListaUsuarios &db, tDatosUsuario &user) {
	if (db.counter < MAX_USUARIOS) {
		db.l[db.counter] = user;
		db.counter++;
		return false;
	} else return true;
}

bool buscar(string user, tListaUsuarios &db) {
	bool found = false; string buff;
	unsigned short i = 0;
	if (i < db.counter) buff = db.l[i].usuario;
	while (buff <= user && !found && i < db.counter) {
		if (db.l[i].usuario == user) found = true;
		i++;
	}
	return found;
}