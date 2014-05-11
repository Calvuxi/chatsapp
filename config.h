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
const unsigned short MAX_USER_LENGTH = 50;
const unsigned short MAX_MENSAJES = 50; // Da una excepción en ejecución si se pone a más de 206.
const unsigned short MAX_CHATS = 50;
const unsigned short OPT_WORDS = 2;

const unsigned short L_PADDING = 5;
const unsigned short R_PADDING = 5;
const unsigned short MIN_WIDTH = 70;
const unsigned short MIN_BUFFER = 80;

const string CENTINELA = "XXX";
const string USER_LIST = "usuarios.txt";
const string CHAT_LIST = "_chats.txt";

const char O_ENT = 'c';
const char O_ORD = 'o';
const char O_ELI = 'e';
const char O_OFEC = 'f';
const char O_NCH = 'n';
const char O_ONOM = 'n';
const char O_SAL = 's';
const string INTRO = "<intro>";

const string opt1 = string("Entrar al chat N: ") + O_ENT + string(" N ") + INTRO;
const string opt2 = string("Crear nuevo chat: ") + O_NCH + ' ' + INTRO;
const string opt3 = string("Eliminar el chat N: ") + O_ELI + string(" N ") + INTRO;
const string opt4 = string("Ordenar chats por nombre: ") + O_ORD + ' ' + O_ONOM + ' ' + INTRO;
const string opt5 = string("Ordenar chats por fecha: ") + O_ORD + ' ' + O_OFEC + ' ' + INTRO;
const string opt6 = string("Salir: ") + O_SAL + ' ' + INTRO;

const string LOGIN_PROMPT = "Por favor, introduce tu nombre de usuario: ";
const string INVALID_USERNAME = "El nombre de usuario no es válido.";
const string LOGIN_ERR = "El nombre de usuario no está registrado.";
const string NEW_CHAT_PROMPT = "Introduce el nombre de usuario del otro participante: ";
const string CH_EXISTS = "Ya tienes un chat iniciado con ese usuario.";
const string CH_WITH_SELF = "No puedes iniciar un chat contigo mismo.";
const string INIT_CH_TEXT = "Nuevo chat iniciado por ";
const string TOO_MANY_CHATS = "No se ha podido crear el chat porque tienes demasiados chats.";
const string NEW_CHAT_SUCCESS = "Se ha creado un chat con ";
const string WRONG_INDEX = "No tienes ningún chat abierto con ese índice.";
const string DEL_CHAT_SUCCESS = "Se ha eliminado el chat con éxito.";

const unsigned int N_OPTS = 6;
const string OPTS[N_OPTS] = { opt1, opt2, opt3, opt4, opt5, opt6 };

const char LINE = '—';
const char U_SC = '_';

// #### Declaraciones typedef ####

// #### Prototipos ####

#endif