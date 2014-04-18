#ifndef CLIENTE_H
#define CLIENTE_H
/* --------------- AUTHORS ---------------
- David P�rez (hallaplay835@gmail.com).
- Iv�n Calvo (calvuxi@gmail.com).
*/

// #### Librer�as de sistema ####
#include <string>

// #### UDLs ####
#include "listaChats.h"

// #### Namespaces ####
using namespace std;

// #### Constantes ####

// #### Declaraciones typedef ####
typedef struct {
	string cliente;
	tListaChats listaChats;
} tDatosCliente;

// #### Prototipos ####
// inicializar los datos del cliente.
// colocar los mensajes del buz�n del servidor en los chats correspondientes.
// mostrar el men� de usuario.
// manejar el men� de usuario.
// crear un nuevo chat.

#endif