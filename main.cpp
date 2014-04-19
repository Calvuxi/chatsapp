/* --------------- AUTHORS ---------------
- David Pérez (hallaplay835@gmail.com).
- Iván Calvo (calvuxi@gmail.com).
*/

// #### Librerías de sistema ####
#include <iostream>
#include <string>

// #### UDLs ####
#include "config.h"
#include "listaUsuarios.h"
#include "listaChats.h"
#include "cliente.h"

// #### Namespaces ####
using namespace std;

// #### Constantes ####

// #### Declaraciones typedef ####

// #### Prototipos ####
void chcp1252();
int readInt(string ERR_MSG, int m, int n);
string getClientName();
string login(tListaUsuarios &db, unsigned short &ind);

// #### main() ####
int main() {
	chcp1252();

	tListaUsuarios db; 
	init(db);
	if (cargar(USER_LIST, db)) cout << "No se ha podido cargar la base de datos." << endl;
	else {
		unsigned short ind;
		string cliente = login(db, ind);
		tDatosCliente cl;
		if (init(cl, cliente)) cout << "No se han podido cargar tus chats." << endl;
		else {
			if (insertar(cl.listaChats, db.l[ind].buzon)) cout << "No se ha podido cargar todo tu buzón. Además lo hemos vaciado." << endl;
			else {
				cout << "¡ÉXITO!" << endl;
			}
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

string getClientName() {
	string user;
	cout << "Por favor, introduce tu nombre de usuario: ";
	getline(cin, user);
	while (user.length() < MIN_USER_LENGTH || user.find(" ") != -1 || user.length() > MAX_USER_LENGTH) {
		cout << "El nombre de usuario no es válido." << endl;
		cout << "Nombre de usuario: ";
		getline(cin, user);
	}
	return user;
}

string login(tListaUsuarios &db, unsigned short &ind) {
	string client = getClientName();
	while (!buscar(client, db, ind)) {
		cout << "El nombre de usuario no está registrado." << endl;
		client = getClientName();
	}
	return client;
}