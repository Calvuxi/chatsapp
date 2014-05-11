#ifndef MENSAJE_H
#define MENSAJE_H
/* --------------- AUTHORS ---------------
- David Pérez (hallaplay835@gmail.com).
- Iván Calvo (calvuxi@gmail.com).
*/

// #### Librerías de sistema ####
#include <string>

// #### UDLs ####

// #### Namespaces ####
using namespace std;

// #### Constantes ####

// #### Declaraciones typedef ####
typedef time_t tFecha;

typedef struct {
	string emisor;
	string receptor;
	tFecha fecha;
	string texto;
} tMensaje;

// #### Prototipos ####
// crear un mensaje nuevo.
void init(tMensaje &msg, string emisor, string receptor, tFecha fecha, string texto);
// mostrar un mensaje.
void mostrar(const tMensaje &msg, bool right = false);
// cargar un mensaje de un archivo.
bool cargar(ifstream &file, tMensaje &msg, string nombre, string client);
// guardar un mensaje de un archivo.
bool guardar(ofstream &file, const tMensaje &msg);
// mostrar la fecha en formato yyyy/mm/dd, hh:mm:ss (implementada en el guión).
void mostrar(tFecha fecha);
// convertir tFecha a string.
string tFechatoString(tFecha fecha);

#endif