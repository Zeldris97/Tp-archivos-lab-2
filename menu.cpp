#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <cstring>
#include <locale.h>

using namespace std;
#include "interfaz.h"
#include "rlutil.h"
using namespace rlutil;
#include "menu.h"
#include "usuario.h"

void menu_principal() {
	int opcion,i;
	do{
	system("cls");
	title("LARA®", APP_TITLEFORECOLOR, APP_TITLEBACKCOLOR);
	//gotoxy(1, 3);

	for (i = 0; i < 23; i++) {
		gotoxy(i + 4, 3); printf("*");
		gotoxy(9, 4); printf("MENÚ PRINCIPAL ");
		gotoxy(i + 4, 5); printf("*");
		gotoxy(4, 4); printf("*");
		gotoxy(26, 4); printf("*");
	}

	gotoxy(1,6);
		//cout << "    MENÚ PRINCIPAL" << endl<<endl;
		cout << "    1. USUARIOS" << endl;
		cout << "    2. ENTRENAMIENTOS" << endl;
		cout << "    3. REPORTES " << endl;
		cout << "    4. CONFIGURACIÓN " << endl<<endl;
		cout << "    0. SALIR" << endl;
		cout << "    ------------------------------" << endl;

		cout <<"    Opcion-> ";
		cin >> opcion;


			switch (opcion) {
			case 1:
				menu_usuario();
				break;
			case 2:
				break;
			case 3:
				break;
			case 4:
				break;
			case 0:	return;
				break;
			}
	} while (opcion != 0);

}

void menu_usuario() {
	int opcion;
	bool grabo;
	do {
		system("cls");
		title("LARA®", APP_TITLEFORECOLOR, APP_TITLEBACKCOLOR);
		for (int i = 0; i < 23; i++) {
			gotoxy(i + 4, 3); printf("*");
			gotoxy(9, 4); printf("MENÚ USUARIOS ");
			gotoxy(i + 4, 5); printf("*");
			gotoxy(4, 4); printf("*");
			gotoxy(26, 4); printf("*");
		}

		gotoxy(1, 6);
		//cout << "    MENÚ USUARIOS" << endl << endl;
		cout << "    1. NUEVO USUARIO" << endl;
		cout << "    2. MODIFICAR USUARIO" << endl;
		cout << "    3. NUEVO ARCHIVO*****" << endl;
		cout << "    4. LISTAR USUARIO POR ID " << endl;
		cout << "    5. LISTAR TODOS LOS USUARIOS " << endl;
		cout << "    6. ELIMINAR USUARIO" << endl << endl;
		cout << "    0. VOLVER AL MENÚ PRINCIPAL" << endl;
		cout << "    ------------------------------" << endl;

		cout << "    Opcion-> ";
		cin >> opcion;


		switch (opcion) {
		case 1:
			rlutil::cls();
			title("LARA®", APP_TITLEFORECOLOR, APP_TITLEBACKCOLOR);
			gotoxy(1, 3);
			grabo = guardar_usuario(cargar_usuario());
			if (grabo) {
				msj("El participante se guardó correctamente.", APP_FORECOLOR, APP_OKCOLOR);
			}
			else {
				msj("El participante no se guardó.", APP_FORECOLOR, APP_ERRORCOLOR);
			}
			break;
		case 2:
			break;
		case 3:
			rlutil::cls();
			title("LARA®", APP_TITLEFORECOLOR, APP_TITLEBACKCOLOR);
			gotoxy(1, 3);
			grabo = guardar_usuario2(cargar_usuario());
			if (grabo) {
				msj("El participante se guardó correctamente.", APP_FORECOLOR, APP_OKCOLOR);
			}
			else {
				msj("El participante no se guardó.", APP_FORECOLOR, APP_ERRORCOLOR);
			}
			break;
		case 4:
			rlutil::cls();
			title("LARA®", APP_TITLEFORECOLOR, APP_TITLEBACKCOLOR);
			gotoxy(1, 3);
			gotoxy(1, 3);
			cout << "    USUARIO POR ID" << endl << endl;
			listar_participante_x_id();
			rlutil::anykey();
			break;
		case 5:
			rlutil::cls();
			title("LARA®", APP_TITLEFORECOLOR, APP_TITLEBACKCOLOR);
			gotoxy(1, 3);
			cout << "    LISTA DE USUARIOS" << endl << endl;
			listar_usuario();
			system("pause");
			break;
		case 0: return;
			break;
		}
	} while (opcion != 0);

}
