/* --------------- AUTHORS ---------------
- David Pérez (hallaplay835@gmail.com).
- Iván Calvo (calvuxi@gmail.com).
*/

// #### Librerías de sistema ####
#include <fstream>
#include <ctime>
#include <iostream>

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

void mostrar(const tMensaje &msg) {
	cout << msg.emisor << " <"; 
	mostrar(msg.fecha);
	cout << ">: " << msg.texto << endl;
}

bool cargar(ifstream &file, tMensaje &msg, string nombre, string client) {
	string emisor; string receptor; tFecha fecha; string texto;
	file >> emisor; file >> fecha; getline(file, texto);
	bool error = file.fail();
	if (client == "") receptor = nombre; // Se llamó a la función para llenar una lista de usuarios.
	else {
		receptor = (emisor == nombre ? client : nombre); // Escoger como receptor al otro participante.
	}
	if (!error) init(msg, emisor, receptor, fecha, texto);
	return error;
}

void mostrar(tFecha fecha) {
	tm* ltm = localtime(&fecha);
	cout << 1900 + ltm->tm_year << "/" << 1 + ltm->tm_mon << "/" << ltm->tm_mday;
	cout << ", " << ltm->tm_hour << ":" << ltm->tm_min << ":" << ltm->tm_sec;
}