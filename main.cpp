/* --------------- AUTHORS ---------------
- David P�rez (hallaplay835@gmail.com).
- Iv�n Calvo (calvuxi@gmail.com).
*/

// #### Librer�as de sistema ####
#include <iostream>
#include <string>

// #### UDLs ####
#include "config.h"
#include "listaUsuarios.h"
#include "listaChats.h"

// #### Namespaces ####
using namespace std;

// #### Constantes ####

// #### Declaraciones typedef ####

// #### Prototipos ####
void chcp1252();
int readInt(string ERR_MSG, int m, int n);
string getClientName();
string login(tListaUsuarios &db);

// #### main() ####
int main() {
	chcp1252();

	tListaUsuarios db; 
	init(db);
	if (cargar(USER_LIST, db)) cout << "No se ha podido cargar la base de datos." << endl;
	else {
		string client = login(db);
		
		tListaChats lch;
		init(lch);
		if (cargar(client.append(CHAT_LIST), lch)) cout << "No se han podido cargar los chats de " << client << "." << endl;
		else {
			cout << "��XITO!";
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
		cout << "El nombre de usuario no es v�lido." << endl;
		cout << "Nombre de usuario: ";
		getline(cin, user);
	}
	return user;
}

string login(tListaUsuarios &db) {
	string client = getClientName();
	while (!buscar(client, db)) {
		cout << "El nombre de usuario no est� registrado." << endl;
		client = getClientName();
	}
	return client;
}