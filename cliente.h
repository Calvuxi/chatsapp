#ifndef CLIENTE_H
#define CLIENTE_H
/* --------------- AUTHORS ---------------
- David P�rez (hallaplay835@gmail.com).
- Iv�n Calvo (calvuxi@gmail.com).
*/

// #### Librer�as de sistema ####

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

typedef enum tOpt { entrar, crear, eliminar, ordenar_n, ordenar_f, salir, error};
typedef string tSplitOpt[OPT_WORDS];
typedef struct {
	tOpt opt;
	unsigned int num;
} tOpts;

// #### Prototipos ####
// inicializar los datos del cliente.
void init(tDatosCliente &cl);
// colocar los mensajes del buz�n del servidor en los chats correspondientes.
// mostrar el men� de usuario.
tOpts menu(const tDatosCliente &cl);
// parsear la entrada del usuario.
tOpts parseOpt();
// splittear un string por delimitador.
void splitString(string s, string delimiter, tSplitOpt &info);
// manejar el men� de usuario.
bool manejarMenu(const tOpts &opts);
// crear un nuevo chat. **
// eliminar un chat. **
// ordenar un chat. **
// entrar.
bool login(tListaUsuarios &db, tDatosCliente &cl);
// salir.
// obtener el nombre de un cliente.
string getClientName();
// obtener la anchura de la consola.
unsigned int getWidth();
// modificar la anchura de la consola.
void setWidth(unsigned int cols);
// obtener la anchura del buffer de la consola.
unsigned int getBuffer();
// modificar la anchura del buffer de la consola.
void setBuffer(unsigned int cols);
// imprimir una l�nea separadora.
void printLine(unsigned int num, char fill);
// centrar texto.
void center(unsigned int width, string txt);
// imprimir las opciones del men�.
void printOpts(unsigned int width);
// imprimir texto a dos columnas.
void printTwoCols(unsigned int width, string str1, string str2);

// ** = funciones carcasa.

#endif