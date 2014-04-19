#ifndef CLIENTE_H
#define CLIENTE_H
/* --------------- AUTHORS ---------------
- David Pérez (hallaplay835@gmail.com).
- Iván Calvo (calvuxi@gmail.com).
*/

// #### Librerías de sistema ####
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
bool init(tDatosCliente &cl, string cliente);
// colocar los mensajes del buzón del servidor en los chats correspondientes.
bool insertar(tListaChats &lch, tListaMensajes &lm);
// mostrar el menú de usuario.
// manejar el menú de usuario.
// crear un nuevo chat.

#endif