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
bool enviar(tMensaje &msg, tListaMensajes &buzon) {
	return insertar(buzon, msg);
}

bool insertar(tListaUsuarios &db, tDatosCliente &cl) {
	int i = buscar(cl.cliente, db);
	if (i == -1) return true;
	else {
		bool error = false;
		int k;
		for (unsigned short j = 0; j < db.l[i]->buzon.counter; j++) {
			string nombre = db.l[i]->buzon.l[j].emisor;
			k = buscar(nombre, cl.listaChats);
			if (k == -1) { // El chat es nuevo. Crearlo e insertarlo.
				tChat ch;
				init(ch, nombre, nombre);
				ch.listaMensajes.l[0] = db.l[i]->buzon.l[j]; // Insertar el mensaje, pero no subir el contador porque el chat está vacío.
				error = insertar(cl.listaChats, ch);
			} else {
				if (insertar(cl.listaChats.l[k].listaMensajes, db.l[i]->buzon.l[j])) { // Actualizar histórico.
					mover(db.l[i]->buzon.l[j], cl.cliente, cl.listaChats.l[k].nombre);
				}
			}
		}
		init(db.l[i]->buzon); // Vaciar el buzón.
		return error;
	}
	return true;
}