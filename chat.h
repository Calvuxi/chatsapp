#ifndef CHAT_H
#define CHAT_H
/* --------------- AUTHORS ---------------
- David P�rez (hallaplay835@gmail.com).
- Iv�n Calvo (calvuxi@gmail.com).
*/

// #### Librer�as de sistema ####
#include <string>

// #### UDLs ####
#include "listaMensajes.h"

// #### Namespaces ####
using namespace std;

// #### Constantes ####

// #### Declaraciones typedef ####
typedef struct {
	string nombre; // identificador del usuario con el que se habla.
	string owner; // identificador del usuario que inici� el chat.
	tListaMensajes listaMensajes;
} tChat;

// #### Prototipos ####
// inicializar un chat.
void init(tChat &ch);
// cargar un chat de un archivo.
bool cargar(ifstream &file, tChat &ch, string client);
// guardar chat en un archivo.
// mostrar cabecera de un chat.
// mostrar los mensajes de un chat.

#endif