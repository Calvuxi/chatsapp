#ifndef LISTAMENSAJES_H
#define LISTAMENSAJES_H
/* --------------- AUTHORS ---------------
- David P�rez (hallaplay835@gmail.com).
- Iv�n Calvo (calvuxi@gmail.com).
*/

// #### Librer�as de sistema ####

// #### UDLs ####
#include "mensaje.h"

// #### Namespaces ####

// #### Constantes ####
const unsigned short MAX_MENSAJES = 5000;

// #### Declaraciones typedef ####
typedef struct {
	tMensaje l[MAX_MENSAJES];
	unsigned short counter;
} tListaMensajes;

// #### Prototipos ####
// inicializar lista de mensajes.
// a�adir un mensaje al final.
// consultar el �ltimo elemento.
// cargar una lista de mensajes de un archivo.
// guardar una lista de mensajes en un archivo.

#endif