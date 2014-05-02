#ifndef MENSAJE_H
#define MENSAJE_H
/* --------------- AUTHORS ---------------
- David P�rez (hallaplay835@gmail.com).
- Iv�n Calvo (calvuxi@gmail.com).
*/

// #### Librer�as de sistema ####
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
void mostrar(const tMensaje &msg);
// cargar un mensaje de un archivo.
bool cargar(ifstream &file, tMensaje &msg, string nombre, string client);
// guardar un mensaje de un archivo.
// mostrar la fecha en formato yyyy/mm/dd, hh:mm:ss (implementada en el gui�n).
void mostrar(tFecha fecha);

#endif