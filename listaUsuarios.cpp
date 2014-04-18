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
bool cargar(string filename, tListaUsuarios &db) {
	ifstream file;
	file.open(filename.c_str());
	if (!file.is_open()) return false;
	else {
		string buff; unsigned short numMensajes; bool error = false;
		
		// Leer el primer usuario (o el centinela):
		tDatosUsuario user;
		error = cargar(file, user);
		if (!error) error = insertar(db, user);

		while (!error) {
			file >> numMensajes;
			getline(file, buff);
			error = file.fail();

			// Descartar los mensajes del usuario:
			unsigned short i = 0;
			while (!error && i < numMensajes) {
				getline(file, buff);
				error = file.fail();
				i++;
			}
			
			// Leer otro usuario:
			if (!error) {
				tDatosUsuario user;
				error = cargar(file, user);
				if (!error) error = insertar(db, user);
			}
		}
		file.close();

		return error;
	}
}

void init(tListaUsuarios &db) {
	db.counter = 0;
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
