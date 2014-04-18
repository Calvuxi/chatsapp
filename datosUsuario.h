#ifndef DATOSUSUARIO_H
#define DATOSUSUARIO_H
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
	string usuario;
	tListaMensajes buzon;
} tDatosUsuario;

// #### Prototipos ####
// inicializar un usuario.
// cargar un usuario de un archivo.
bool cargar(ifstream &file, tDatosUsuario &user);
// guardar un usuario en un archivo.

#endif