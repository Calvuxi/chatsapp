#ifndef CLIENTE_H
#define CLIENTE_H
/* --------------- AUTHORS ---------------
- David Pérez (hallaplay835@gmail.com).
- Iván Calvo (calvuxi@gmail.com).
*/

// #### Librerías de sistema ####

// #### UDLs ####
#include "listaChats.h"
#include "listaUsuarios.h"

// #### Namespaces ####

// #### Constantes ####

// #### Declaraciones typedef ####
typedef struct {
	string cliente;
	tListaChats listaChats;
} tDatosCliente;

typedef enum tOpt { entrar, crear_ch, eliminar_ch, ordenar_n, ordenar_f, salir, error};
typedef enum tStatus { ok, no_user, ch_exists, ch_with_self };
typedef string tSplitOpt[OPT_WORDS];
typedef struct {
	tOpt opt;
	int num;
} tOpts;

// #### Prototipos ####
// pausar la ejecución hasta que se pulse intro.
void pause();
// inicializar los datos del cliente.
void init(tDatosCliente &cl);
// colocar los mensajes del buzón del servidor en los chats correspondientes.
// mostrar el menú de usuario.
tOpts menu(const tDatosCliente &cl);
// parsear la entrada del usuario.
tOpts parseOpt();
// splittear un string por delimitador.
void splitString(string s, string delimiter, tSplitOpt &info);
// manejar el menú de usuario.
bool manejarMenu(const tOpts &opts, const tListaUsuarios &db, tDatosCliente &cl);
// crear un nuevo chat. **
tStatus crear(const tListaUsuarios &db, tDatosCliente &cl, string &nombre);
// eliminar un chat. **
// ordenar un chat. **
// entrar.
bool login(tListaUsuarios &db, tDatosCliente &cl);
// salir.
// obtener el nombre de un cliente.
string getClientName(string prompt, string err_msg);
// obtener la anchura de la consola.
unsigned int getWidth();
// modificar la anchura de la consola.
void setWidth(unsigned int cols);
// obtener la anchura del buffer de la consola.
unsigned int getBuffer();
// modificar la anchura del buffer de la consola.
void setBuffer(unsigned int cols);
// imprimir una línea separadora.
void printLine(unsigned int num, char fill);
// centrar texto.
void center(unsigned int width, string txt);
// imprimir las opciones del menú.
void printOpts(unsigned int width);
// imprimir texto a dos columnas.
void printTwoCols(unsigned int width, string str1, string str2);

// ** = funciones carcasa.

#endif