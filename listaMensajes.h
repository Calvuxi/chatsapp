#ifndef LISTAMENSAJES_H
#define LISTAMENSAJES_H
/* --------------- AUTHORS ---------------
- David Pérez (hallaplay835@gmail.com).
- Iván Calvo (calvuxi@gmail.com).
*/

// #### Librerías de sistema ####

// #### UDLs ####
#include "mensaje.h"
#include "config.h"

// #### Namespaces ####

// #### Constantes ####

// #### Declaraciones typedef ####
typedef struct {
	tMensaje *l;
	unsigned short counter;
	unsigned short capacidad;
} tListaMensajes;

// #### Prototipos ####
// inicializar lista de mensajes.
bool init(tListaMensajes &lm, unsigned short numMensajes = 0);
// añadir un mensaje al final.
bool insertar(tListaMensajes &lm, tMensaje &msg);
// consultar el último elemento.
tMensaje ultimo(const tListaMensajes &lm);
// cargar una lista de mensajes de un archivo.
bool cargar(ifstream &file, tListaMensajes &lm, string nombre, string client = "");
// guardar una lista de mensajes en un archivo.
bool guardar(ofstream &file, const tListaMensajes &lm);
// mostrar una lista de mensajes.
void mostrar(const tListaMensajes &lm, string cliente);

#endif