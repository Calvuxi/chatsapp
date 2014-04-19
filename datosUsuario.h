#ifndef DATOSUSUARIO_H
#define DATOSUSUARIO_H
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
	string usuario;
	tListaMensajes buzon;
} tDatosUsuario;

// #### Prototipos ####
// inicializar un usuario.
void init(tDatosUsuario &du);
// cargar un usuario de un archivo.
bool cargar(ifstream &file, tDatosUsuario &du);
// guardar un usuario en un archivo.

#endif