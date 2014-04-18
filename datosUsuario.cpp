/* --------------- AUTHORS ---------------
- David Pérez (hallaplay835@gmail.com).
- Iván Calvo (calvuxi@gmail.com).
*/

// #### Librerías de sistema ####
#include <fstream>

// #### UDLs ####
#include "datosUsuario.h"

// #### Namespaces ####

// #### Constantes ####

// #### Declaraciones typedef ####

// #### Implementaciones ####
bool cargar(ifstream &file, tDatosUsuario &user) {
	file >> user.usuario;
	return file.fail() || user.usuario == CENTINELA;
}