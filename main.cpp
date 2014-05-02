/* --------------- AUTHORS ---------------
- David Pérez (hallaplay835@gmail.com).
- Iván Calvo (calvuxi@gmail.com).
*/

// #### Librerías de sistema ####
#include <iostream>
#include <string>

// #### UDLs ####
#include "config.h"
#include "cliente.h"

// #### Namespaces ####
using namespace std;

// #### Constantes ####

// #### Declaraciones typedef ####

// #### Prototipos ####
void chcp1252();
int readInt(string ERR_MSG, int m, int n);
string getClientName();

// #### main() ####
int main() {
	chcp1252();

	tListaUsuarios db; 
	init(db);
	if (cargar(USER_LIST, db)) cout << "No se ha podido cargar la base de datos." << endl;
	else {
		tDatosCliente cl;
		if(login(db, cl)) cout << "No se han podido cargar los chats de " << cl.cliente << "." << endl;
		else {
			while (!manejarMenu(menu(cl)));
		}

	}

	return 0;
}

// #### UDFs ####

void chcp1252() {
	system("chcp 1252");
	system("cls");
}

int readInt(string ERR_MSG, int m, int n) {
	int input;
	cin >> input;
	while (cin.fail() || input < m || input > n) {
		cin.clear(); cin.sync();
		cout << ERR_MSG;
		cin >> input;
	}
	cin.sync();

	return input;
}