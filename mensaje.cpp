/* --------------- AUTHORS ---------------
- David P�rez (hallaplay835@gmail.com).
- Iv�n Calvo (calvuxi@gmail.com).
*/

// #### Librer�as de sistema ####
#include <fstream>

// #### UDLs ####
#include "mensaje.h"

// #### Namespaces ####

// #### Constantes ####

// #### Declaraciones typedef ####

// #### Implementaciones ####
void init(tMensaje &msg, string emisor, string receptor, tFecha fecha, string texto) {
	msg.emisor = emisor;
	msg.receptor = receptor;
	msg.fecha = fecha;
	msg.texto = texto;
}

bool cargar(ifstream &file, tMensaje &msg, string nombre, string client) {
	string emisor; string receptor; tFecha fecha; string texto;
	file >> emisor; file >> fecha; getline(file, texto);
	bool error = file.fail();
	if (client == "") receptor = nombre; // Se llam� a la funci�n para llenar una lista de usuarios.
	else {
		receptor = (emisor == nombre ? client : nombre); // Escoger como receptor al otro participante.
	}
	if (!error) init(msg, emisor, receptor, fecha, texto);
	return error;
}