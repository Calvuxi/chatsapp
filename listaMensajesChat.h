#ifndef LISTAMENSAJESCHAT_H
#define LISTAMENSAJESCHAT_H
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
	tMensaje l[MAX_MENSAJES];
	unsigned short ini;
	unsigned short fin;
} tListaMensajesChat;

// #### Prototipos ####
// inicializar lista de mensajes.
bool init(tListaMensajesChat &lmch, unsigned short numMensajes = 0);
// añadir un mensaje al final.
bool insertar(tListaMensajesChat &lmch, tMensaje &msg);
// consultar el último elemento.
tMensaje ultimo(const tListaMensajesChat &lmch);
// cargar una lista de mensajes de un archivo.
bool cargar(ifstream &file, tListaMensajesChat &lmch, string nombre, string client = "");
// guardar una lista de mensajes en un archivo.
bool guardar(ofstream &file, const tListaMensajesChat &lmch);
// mostrar una lista de mensajes.
void mostrar(const tListaMensajesChat &lmch, string cliente);
// obtener el índice del elemento siguiente.
unsigned short next(unsigned short i);
// mover un mensaje al histórico.
bool mover(const tMensaje &msg, string cliente, string nombre);

#endif