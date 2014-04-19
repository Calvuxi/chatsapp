#ifndef LISTAMENSAJES_H
#define LISTAMENSAJES_H
/* --------------- AUTHORS ---------------
- David P�rez (hallaplay835@gmail.com).
- Iv�n Calvo (calvuxi@gmail.com).
*/

// #### Librer�as de sistema ####

// #### UDLs ####
#include "mensaje.h"
#include "config.h"

// #### Namespaces ####

// #### Constantes ####

// #### Declaraciones typedef ####
typedef struct {
	tMensaje l[MAX_MENSAJES];
	unsigned short counter;
} tListaMensajes;

// #### Prototipos ####
// inicializar lista de mensajes.
bool init(tListaMensajes &lm, unsigned short numMensajes = 0);
// a�adir un mensaje al final.
bool insertar(tListaMensajes &lm, tMensaje &msg);
// consultar el �ltimo elemento.
// cargar una lista de mensajes de un archivo.
bool cargar(ifstream &file, tListaMensajes &lm, string nombre, string client = "");
// guardar una lista de mensajes en un archivo.

#endif