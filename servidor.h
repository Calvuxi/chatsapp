#ifndef SERVIDOR_H
#define SERVIDOR_H
/* --------------- AUTHORS ---------------
- David Pérez (hallaplay835@gmail.com).
- Iván Calvo (calvuxi@gmail.com).
*/

// #### Librerías de sistema ####

// #### UDLs ####
#include "listaUsuarios.h"
#include "cliente.h"

// #### Namespaces ####

// #### Constantes ####

// #### Declaraciones typedef ####
typedef struct {
	tListaUsuarios listaUsuarios;
} tServidor;

// #### Prototipos ####
// enviar un mensaje.
void enviar(const tMensaje &msg, tListaMensajes &buzon);
// obtener el buzón de mensajes de un usuario.
bool insertar(tListaUsuarios &db, tDatosCliente &cl);

#endif