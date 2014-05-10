/* --------------- AUTHORS ---------------
- David Pérez (hallaplay835@gmail.com).
- Iván Calvo (calvuxi@gmail.com).
*/

// #### Librerías de sistema ####
#include <string>
#include <iostream>
#include <windows.h>
#include <iomanip>

// #### UDLs ####
#include "servidor.h"
#include "cliente.h"
#include "listaUsuarios.h"

// #### Namespaces ####
using namespace std;

// #### Constantes ####

// #### Declaraciones typedef ####

// #### Implementaciones ####
void init(tDatosCliente &cl) {
	init(cl.listaChats);
}

tOpts menu(const tDatosCliente &cl) {
	
	// Obtener anchuras de pantalla y buffer:
	system("cls");
	unsigned int width = getBuffer();
	if (width < MIN_BUFFER) {
		setBuffer(MIN_BUFFER);
		width = MIN_BUFFER;
	}
	if (getWidth() < MIN_WIDTH) setWidth(MIN_WIDTH);

	// Mostrar título:
	printLine(width, LINE);
	center(width, "CHATSAPP: Chats de " + cl.cliente);
	printLine(width, LINE);
	cout << endl;
	printLine(width, U_SC);

	// Mostrar cabeceras:
	for (unsigned int i = 0; i < cl.listaChats.counter; i++) {
		mostrarCabecera(i, cl.listaChats.l[i]);
		printLine(width, U_SC);
	}
	cout << endl;

	// Mostrar opciones en dos columnas:
	printLine(width, LINE);
	printOpts(width);
	printLine(width, LINE);

	cout << endl << "Selecciona una opción: ";
	tOpts opts = parseOpt();
	while (opts.opt == error) {
		cout << "ERROR. Opción no válida. Selecciona una opción: ";
		opts = parseOpt();
	}
	return opts;
}

tOpts parseOpt() {
	string input;
	getline(cin, input);
	input += ' ';
	tSplitOpt info;
	splitString(input, " ", info);
	tOpts opts;
	if (info[0] == "n") opts.opt = crear;
	else if (info[0] == "s") opts.opt = salir;
	else if (info[0] == "o" && info[1] == "n") opts.opt = ordenar_n;
	else if (info[0] == "o" && info[1] == "f") opts.opt = ordenar_f;
	else {
		try {
			opts.num = stoi(info[1]);
			if (info[0] == "c") opts.opt = entrar;
			else if (info[0] == "e") opts.opt = eliminar;
			else opts.opt = error;
		} catch (std::invalid_argument) {
			opts.opt = error;
		}
	}
	return opts;
}

void splitString(string s, string delimiter, tSplitOpt &info) {
	size_t pos = 0;
	unsigned int i = 0;
	while ((pos = s.find(delimiter)) != std::string::npos && i < OPT_WORDS) {
		info[i] = s.substr(0, pos);
		s.erase(0, pos + delimiter.length());
		i++;
	}
}

bool manejarMenu(const tOpts &opts) {
	bool exit = false;
	switch (opts.opt) {
	case entrar:
		cout << "ENTRAR" << endl;
		break;
	case crear:
		cout << "CREAR" << endl;
		break;
	case eliminar:
		cout << "ELIMINAR" << endl;
		break;
	case ordenar_n:
		cout << "ORDENAR_N" << endl;
		break;
	case ordenar_f:
		cout << "ORDENAR_F" << endl;
		break;
	case salir:
		cout << "SALIR" << endl;
		exit = true;
		break;
	}
	return exit;
}

bool login(tListaUsuarios &db, tDatosCliente &cl) {
	init(cl);

	// Obtener el nombre del cliente.
	//cl.cliente = getClientName();
	cl.cliente = "pepe";
	while (buscar(cl.cliente, db) == -1) {
		cout << "El nombre de usuario no está registrado." << endl;
		cl.cliente = getClientName();
	}

	// Obtener la lista de chats del cliente.
	return cargar(cl.cliente + CHAT_LIST, cl.listaChats) || insertar(db, cl);
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

unsigned int getWidth() {
	unsigned int cols;
	CONSOLE_SCREEN_BUFFER_INFO csbi;
	if (GetConsoleScreenBufferInfo(
		GetStdHandle(STD_OUTPUT_HANDLE),
		&csbi)) {
		cols = csbi.srWindow.Right - csbi.srWindow.Left + 1;
	} else cols = 0;
	return cols;
}

void setWidth(unsigned int cols) {
	CONSOLE_SCREEN_BUFFER_INFO csbi;
	if (GetConsoleScreenBufferInfo(
		GetStdHandle(STD_OUTPUT_HANDLE),
		&csbi)) {

		// Aumentar el buffer si es necesario:
		if (cols > (unsigned int)csbi.dwSize.X) setBuffer(cols);

		// Ajustar el origen si no cabe en la pantalla:
		if ((csbi.srWindow.Left + cols) > (unsigned int)csbi.dwSize.Y) csbi.srWindow.Left = csbi.dwSize.X - cols - 1;

		// Calcular el ancho:
		csbi.srWindow.Right = csbi.srWindow.Left + cols - 1;

		SetConsoleWindowInfo(
			GetStdHandle(STD_OUTPUT_HANDLE),
			true,
			&csbi.srWindow
			);
	}
}

unsigned int getBuffer() {
	unsigned int cols;
	CONSOLE_SCREEN_BUFFER_INFO csbi;
	if (GetConsoleScreenBufferInfo(
		GetStdHandle(STD_OUTPUT_HANDLE),
		&csbi)) {
		cols = csbi.dwSize.X;
	} else cols = 0;
	return cols;
}

void setBuffer(unsigned int cols) {
	CONSOLE_SCREEN_BUFFER_INFO csbi;
	if (GetConsoleScreenBufferInfo(
		GetStdHandle(STD_OUTPUT_HANDLE),
		&csbi)) {

		COORD coord;
		coord.X = cols;
		coord.Y = csbi.dwSize.Y;

		SetConsoleScreenBufferSize(GetStdHandle(STD_OUTPUT_HANDLE), coord);
	}
}

void printLine(unsigned int num, char fill) {
	cout << setw(num) << setfill(fill) << fill;
	setfill(' ');
}

void center(unsigned int width, string txt) {
	unsigned int len = txt.length();
	unsigned int lpadding = 0;
	if (len < width) lpadding = (width - len) / 2;
	cout << setfill(' ') << setw(lpadding) << ' ';
	cout << txt << endl;
}

void printOpts(unsigned int width) {
	unsigned int opts = N_OPTS;
	if (N_OPTS % 2 != 0) opts = N_OPTS - 1;
	for (unsigned int i = 0; i < opts; i = i + 2) {
		printTwoCols(width, OPTS[i], OPTS[i + 1]);
		cout << endl;
	}
	if (N_OPTS % 2 != 0) printTwoCols(width, OPTS[N_OPTS - 1], " ");
}

void printTwoCols(unsigned int width, string str1, string str2) {
	unsigned int mid = 0;
	if (str1.length() + str2.length() + L_PADDING + R_PADDING > width) {
		cout << str1 << endl << str2 << endl;
	} else {
		mid = width - (str1.length() + str2.length() + L_PADDING + R_PADDING);
		cout << setfill(' ') << setw(L_PADDING) << ' ';
		cout << str1;
		cout << setfill(' ') << setw(mid) << ' ';
		cout << str2;
	}
}
