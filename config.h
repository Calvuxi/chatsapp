#ifndef CONFIG_H
#define CONFIG_H
/* --------------- AUTHORS ---------------
- David Pérez (hallaplay835@gmail.com).
- Iván Calvo (calvuxi@gmail.com).
*/

// #### Librerías de sistema ####
#include <string>

// #### UDLs ####

// #### Namespaces ####
using namespace std;

// #### Constantes ####
const unsigned short MAX_USUARIOS = 50;
const unsigned short MIN_USER_LENGTH = 4;
const unsigned short MAX_USER_LENGTH = 20;
const unsigned short MAX_MENSAJES = 100; // Da una excepción en ejecución si se pone a más de 206.
const unsigned short MAX_CHATS = 50;

const string CENTINELA = "XXX";
const string USER_LIST = "usuarios.txt";
const string CHAT_LIST = "_chats.txt";

// #### Declaraciones typedef ####

// #### Prototipos ####

#endif