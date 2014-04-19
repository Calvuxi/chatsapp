/* --------------- AUTHORS ---------------
- David P�rez (hallaplay835@gmail.com).
- Iv�n Calvo (calvuxi@gmail.com).
*/

// #### Librer�as de sistema ####

// #### UDLs ####
#include "cliente.h"

// #### Namespaces ####

// #### Constantes ####

// #### Declaraciones typedef ####

// #### Implementaciones ####
bool init(tDatosCliente &cl, string cliente) {
	cl.cliente = cliente;
	tListaChats lch;
	init(lch);
	if (cargar(cliente.append(CHAT_LIST), lch)) return true;
	else {
		cl.listaChats = lch;
		return false;
	}
}

bool insertar(tListaChats &lch, tListaMensajes &lm) {
	bool error = false;
	unsigned short i = 0;
	while (!error && i < lm.counter) {
		unsigned short ind;
		if (buscar(lm.l[i].emisor, lch, ind)) { // Se infiere que no puedes recibir
												// mensajes de ti mismo.
			error = insertar(lch.l[ind].listaMensajes, lm.l[i]);
		} else error = true;
		i++;
	}
	init(lm); // Vaciar el buz�n.

	return error;
}