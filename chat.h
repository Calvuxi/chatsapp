#ifndef CHAT_H
#define CHAT_H
/* --------------- AUTHORS ---------------
- David Pérez (hallaplay835@gmail.com).
- Iván Calvo (calvuxi@gmail.com).
*/

// #### Librerías de sistema ####
#include <string>

// #### UDLs ####
#include "listaMensajes.h"

// #### Namespaces ####
using namespace std;

// #### Constantes ####

// #### Declaraciones typedef ####
typedef struct {
	string nombre; // identificador del usuario con el que se habla.
	string owner; // identificador del usuario que inició el chat.
	tListaMensajes listaMensajes;
} tChat;

// #### Prototipos ####
// inicializar un chat.
// cargar un chat de un archivo.
// guardar chat en un archivo.
// mostrar cabecera de un chat.
// mostrar los mensajes de un chat.

#endif