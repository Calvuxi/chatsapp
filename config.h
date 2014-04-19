#ifndef CONFIG_H
#define CONFIG_H
/* --------------- AUTHORS ---------------
- David P�rez (hallaplay835@gmail.com).
- Iv�n Calvo (calvuxi@gmail.com).
*/

// #### Librer�as de sistema ####
#include <string>

// #### UDLs ####

// #### Namespaces ####
using namespace std;

// #### Constantes ####
const unsigned short MAX_USUARIOS = 50;
const unsigned short MIN_USER_LENGTH = 4;
const unsigned short MAX_USER_LENGTH = 20;
const unsigned short MAX_MENSAJES = 100; // Da una excepci�n en ejecuci�n si se pone a m�s de 206.
const unsigned short MAX_CHATS = 50;

const string CENTINELA = "XXX";
const string USER_LIST = "usuarios.txt";
const string CHAT_LIST = "_chats.txt";

// #### Declaraciones typedef ####

// #### Prototipos ####

#endif