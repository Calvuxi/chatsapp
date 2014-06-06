#ifndef LISTACHATS_H
#define LISTACHATS_H
/* --------------- AUTHORS ---------------
- David P�rez (hallaplay835@gmail.com).
- Iv�n Calvo (calvuxi@gmail.com).
*/

// #### Librer�as de sistema ####

// #### UDLs ####
#include "chat.h"

// #### Namespaces ####

// #### Constantes ####

// #### Declaraciones typedef ####
typedef struct {
	tChat *l;
	unsigned short counter;
	unsigned short capacidad;
} tListaChats;

// #### Prototipos ####
// inicializar una lista de chats.
void init(tListaChats &lch);
// cargar una lista de chats de un archivo.
bool cargar(string filename, tListaChats &lch);
// guardar una lista de chats en un archivo.
bool guardar(string filename, const tListaChats &lch);
// buscar un chat por nombre en una lista de chats.
int buscar(string nombre, const tListaChats &lch);
// a�adir un chat al final de una lista de chats.
bool insertar(tListaChats &lch, tChat &ch);
// eliminar un chat (por posici�n) de una lista de chats.
bool eliminar(tListaChats &lch, int i);
// mover un chat (por posici�n) al final de una lista de chats.
void mover(tListaChats &lch, unsigned short ind);
// ordenar una lista de chats por nombre.
void ordenarN(tListaChats &lch);
// ordenar una lista de chats por fecha (de m�s antiguo a m�s reciente).
void ordenarF(tListaChats &lch);
// obtener el �ndice del chat m�s antiguo en lch[i..j-1] (inclusive).
unsigned short getMin(tListaChats &lch, unsigned short i, unsigned short j);
// intercambiar lch[i] y lch[j].
void swap(tListaChats &lch, unsigned short i, unsigned short j);

#endif