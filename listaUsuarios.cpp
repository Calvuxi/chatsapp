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
	if (!file.is_open()) return true;
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

bool guardar(string filename, const tListaUsuarios &db) {
	ofstream file;
	file.open(filename.c_str());
	if (!file.is_open()) return true;
	else {
		bool error = false;
		unsigned short i = 0;
		while (i < db.counter && !error) {
			error = guardar(file, db.l[i]);
			i++;
		}
		file << CENTINELA;
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

int buscar(string user, const tListaUsuarios &db) {
	int ini = 0, fin = db.counter - 1, mit;
	bool found = false;
	while (!found && ini <= fin) {
		mit = (ini + fin) / 2;
		found = (db.l[mit].usuario == user);
		if (db.l[mit].usuario > user) fin = mit - 1;
		else ini = mit + 1;
	}
	return (found ? mit : -1);
}