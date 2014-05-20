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
void pause() {
	cin.clear();
	cin.sync();
	cout << "Intro para continuar...";
	cin.ignore(INT_MAX, '\n');
}

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
	if (info[0] == "n") opts.opt = crear_ch;
	else if (info[0] == "s") opts.opt = salir;
	else if (info[0] == "o" && info[1] == "n") opts.opt = ordenar_n;
	else if (info[0] == "o" && info[1] == "f") opts.opt = ordenar_f;
	else {
		try {
			opts.num = stoi(info[1]);
			if (info[0] == "c") opts.opt = entrar_ch;
			else if (info[0] == "e") opts.opt = eliminar_ch;
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

bool manejarMenu(const tOpts &opts, tListaUsuarios &db, tDatosCliente &cl) {
	bool exit = false;
	switch (opts.opt) {
	case entrar_ch:
		if (cl.listaChats.counter <= opts.num || opts.num < 0) {
			cout << WRONG_INDEX << endl;
			pause();
		} else entrar(db.l[buscar(cl.listaChats.l[opts.num].nombre, db)].buzon, cl, opts.num);
		break;
	case crear_ch:
	{
		string nombre;
		tStatus status = crear(db, cl, nombre);
		switch (status) {
		case no_user:
			cout << LOGIN_ERR << endl;
			pause();
			break;
		case ch_exists:
			cout << CH_EXISTS << endl;
			pause();
			break;
		case ch_with_self:
			cout << CH_WITH_SELF << endl;
			pause();
			break;
		case ok:
		{
			tChat ch;
			init(ch, nombre, cl.cliente);
			if (insertar(cl.listaChats, ch)) cout << TOO_MANY_CHATS << endl;
			else {
				enviar(cl.listaChats.l[cl.listaChats.counter - 1].listaMensajes.l[0], db.l[buscar(nombre, db)].buzon);
				cout << NEW_CHAT_SUCCESS + nombre + "." << endl;
			}
			pause();
			break;
		}
		}
		break;
	}
	case eliminar_ch:
		if (eliminar(cl.listaChats, opts.num)) cout << WRONG_INDEX << endl;
		else cout << DEL_CHAT_SUCCESS << endl;
		pause();
		break;
	case ordenar_n:
		ordenarN(cl.listaChats);
		break;
	case ordenar_f:
		ordenarF(cl.listaChats);
		break;
	case salir:
		exit = true;
		break;
	}
	return exit;
}

tStatus crear(const tListaUsuarios &db, tDatosCliente &cl, string &nombre) {
	nombre = getClientName(NEW_CHAT_PROMPT, INVALID_USERNAME);
	if (buscar(nombre, db) == -1) return no_user;
	else if (buscar(nombre, cl.listaChats) != -1) return ch_exists;
	else if (nombre == cl.cliente) return ch_with_self;
	else return ok;
}

bool login(tListaUsuarios &db, tDatosCliente &cl) {
	while (buscar(cl.cliente, db) == -1) {
		cout << LOGIN_ERR << endl;
		cl.cliente = getClientName(LOGIN_PROMPT, INVALID_USERNAME);
	}

	// Obtener la lista de chats del cliente e insertar su buzón.
	bool error = cargar(cl.cliente + CHAT_LIST, cl.listaChats) || insertar(db, cl);
	if (!error) ordenarF(cl.listaChats);
	return error;
}

void entrar(tListaMensajes &buzon, tDatosCliente &cl, unsigned short ind) {
	string input;
	do {
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
		center(width, "CHAT CON " + cl.listaChats.l[ind].nombre);
		printLine(width, LINE);
		cout << endl;
		printLine(width, U_SC);

		// Mostrar lista de mensajes del chat:
		mostrar(cl.listaChats.l[ind].listaMensajes, cl.cliente);

		cout << endl;
		printLine(width, LINE);
		cout << WRITE_PROMPT;
		getline(cin, input);
		if (input != opt_exit && input != "") {
			tMensaje msg;
			init(msg, cl.cliente, cl.listaChats.l[ind].nombre, time(0), input);
			enviar(msg, buzon);
			insertar(cl.listaChats.l[ind].listaMensajes, msg);
			mover(cl.listaChats, ind);
			ind = cl.listaChats.counter - 1;
		}
	} while (input != opt_exit);
}

string getClientName(string prompt, string err_msg) {
	string user;
	cout << prompt;
	getline(cin, user);
	while (user != opt_exit && (user.length() < MIN_USER_LENGTH || user.find(" ") != -1 || user.length() > MAX_USER_LENGTH)) {
		cout << err_msg << endl;
		cout << "Nombre de usuario: <" + opt_exit + " para salir>: ";
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