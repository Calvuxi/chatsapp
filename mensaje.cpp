/* --------------- AUTHORS ---------------
- David Pérez (hallaplay835@gmail.com).
- Iván Calvo (calvuxi@gmail.com).
*/

// #### Librerías de sistema ####
#include <fstream>
#include <ctime>
#include <iostream>
#include <iomanip>

// #### UDLs ####
#include "mensaje.h"
#include "cliente.h"

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

void mostrar(const tMensaje &msg, bool right) {
	unsigned int len = msg.emisor.length() + tFechatoString(msg.fecha).length() + msg.texto.length() + 5; // Se suma 5 por " <" y ">: ".
	unsigned int width = getBuffer();

	if (right) cout << left << setfill(' ') << setw(width - len) << ' ';

	cout << msg.emisor << " <";
	mostrar(msg.fecha);
	cout << ">: " << msg.texto;
	if (!right && len != width) cout << endl;
}

bool cargar(ifstream &file, tMensaje &msg, string nombre, string client) {
	string emisor; string receptor; tFecha fecha; string texto;
	file >> emisor; file >> fecha; file.get();  getline(file, texto);
	bool error = file.fail();
	if (client == "") receptor = nombre; // Se llamó a la función para llenar una lista de usuarios.
	else receptor = (emisor == nombre ? client : nombre); // Escoger como receptor al otro participante.
	if (!error) init(msg, emisor, receptor, fecha, texto);
	return error;
}

void mostrar(tFecha fecha) {
	cout << tFechatoString(fecha);
}

string tFechatoString(tFecha fecha) {
	string text;
	tm* ltm = localtime(&fecha);
	text = to_string(1900 + ltm->tm_year) + "/" + to_string(1 + ltm->tm_mon) + "/" + to_string(ltm->tm_mday);
	text += ", " + to_string(ltm->tm_hour) + ":" + to_string(ltm->tm_min) + ":" + to_string(ltm->tm_sec);
	return text;
}