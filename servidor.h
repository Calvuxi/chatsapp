#ifndef SERVIDOR_H
#define SERVIDOR_H
/* --------------- AUTHORS ---------------
- David P�rez (hallaplay835@gmail.com).
- Iv�n Calvo (calvuxi@gmail.com).
*/

// #### Librer�as de sistema ####

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
// obtener el buz�n de mensajes de un usuario.
bool insertar(tListaUsuarios &db, tDatosCliente &cl);

#endif