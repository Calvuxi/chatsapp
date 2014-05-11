/* --------------- AUTHORS ---------------
- David Pérez (hallaplay835@gmail.com).
- Iván Calvo (calvuxi@gmail.com).
*/

// #### Librerías de sistema ####

// #### UDLs ####
#include "servidor.h"

// #### Namespaces ####

// #### Constantes ####

// #### Declaraciones typedef ####

// #### Implementaciones ####
bool insertar(tListaUsuarios &db, tDatosCliente &cl) {
	int i = buscar(cl.cliente, db);
	if (i == -1) return true;
	else {
		bool error = false;
		int k;
		for (unsigned short j = 0; j < db.l[i].buzon.counter; j++) {
			string nombre = db.l[i].buzon.l[j].emisor;
			k = buscar(nombre, cl.listaChats);
			if (k == -1) { // El chat es nuevo. Crearlo e insertarlo.
				tChat ch;
				init(ch);
				ch.nombre = nombre;
				ch.owner = nombre;
				insertar(ch.listaMensajes, db.l[i].buzon.l[j]);
				error = insertar(cl.listaChats, ch);
			} else {
				insertar(cl.listaChats.l[k].listaMensajes, db.l[i].buzon.l[j]);
			}
		}
		init(db.l[i].buzon); // Vaciar el buzón.
		return error;
	}
	return true;
}