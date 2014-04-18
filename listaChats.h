#ifndef LISTACHATS_H
#define LISTACHATS_H
/* --------------- AUTHORS ---------------
- David P�rez (hallaplay835@gmail.com).
- Iv�n Calvo (calvuxi@gmail.com).
*/

// #### Librer�as de sistema ####

// #### UDLs ####
#include "chat.h"

// #### Namespaces ####

// #### Constantes ####

// #### Declaraciones typedef ####
typedef struct {
	tChat l[MAX_CHATS];
	unsigned short counter;
} tListaChats;

// #### Prototipos ####
// inicializar una lista de chats.
// cargar una lista de chats de un archivo.
// guardar una lista de chats en un archivo.
// buscar un chat por nombre en una lista de chats.
// a�adir un chat al final de una lista de chats.
// eliminar un chat (por posici�n) de una lista de chats.
// mover un chat (por posici�n) al final de una lista de chats.
// ordenar una lista de chats por nombre.
// ordenar una lista de chats por fecha (de m�s antiguo a m�s reciente).

#endif