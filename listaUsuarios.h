#ifndef LISTAUSUARIOS_H
#define LISTAUSUARIOS_H
/* --------------- AUTHORS ---------------
- David Pérez (hallaplay835@gmail.com).
- Iván Calvo (calvuxi@gmail.com).
*/

// #### Librerías de sistema ####

// #### UDLs ####
#include "datosUsuario.h"

// #### Namespaces ####

// #### Constantes ####

// #### Declaraciones typedef ####
typedef struct {
	tDatosUsuario l[MAX_USUARIOS];
	unsigned short counter;
} tListaUsuarios;

// #### Prototipos ####
// inicializar una lista de usuarios.
void init(tListaUsuarios &db);
// cargar una lista de usuarios de un archivo.
bool cargar(string filename, tListaUsuarios &db);
// guardar una lista de usuarios en un archivo.
// buscar en una lista de usuarios.
int buscar(string user, const tListaUsuarios &db);
// insertar en una lista de usuarios.
bool insertar(tListaUsuarios &db, tDatosUsuario &user);

#endif