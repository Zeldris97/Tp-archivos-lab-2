#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <cstring>
#include <locale.h>
#include "rlutil.h"
using namespace std;
#include "interfaz.h"
using namespace rlutil;
#include "usuario.h"
#include "fecha.h"

const char* FILE_USUARIOS = "usuarios.dat";

Usuario cargar_usuario() {
	Usuario a, * aux;
	aux = &a;
	int ID;
	cout << "    NUEVO USUARIO" << endl << endl;
	cout << "    ID        : ";
	cin >> ID;

	// Validamos el código que no se repita en la lista
	while (buscar_usuario(ID) >= 0) {
		cout << "    >ID        : ";
		cin >> ID;
	}
	// Fin de la validación de código
	aux->ID = ID;

	cout << "    Nombres   : ";
	cin.ignore();
	cin.getline(aux->nombres, 50);
	while (aux->nombres[0] == '\0'|| aux->nombres[0] == ' ') {
		cout << "    >Nombres   : ";
		cin.getline(aux->nombres, 50);
	}

	cout << "    Apellidos : ";
	cin.getline(aux->apellidos, 50);
	while (aux->apellidos[0] == '\0'|| aux->apellidos[0] == ' ') {
		cout << "    >Apellidos : ";
		cin.getline(aux->apellidos, 50);
	}
	cout << "    Fecha de nacimiento: (dd/mm/aaaa)";
	aux->nacimiento=cargar_fecha();

	aux->altura = cargar_altura();
	aux->peso = cargar_peso();

	cout << "    Perfil de actividad: ";
	cin >> aux->perfil;
	while (aux->perfil != 'A' && aux->perfil != 'a' && aux->perfil != 'B' && aux->perfil != 'b' && aux->perfil != 'C' && aux->perfil != 'c') {
		cout << "    >Perfil de actividad: ";
		cin >> aux->perfil;
	}
	aux->apto=cargar_apto();
	/*cout << "    Apto médico         : ";
	cin >> aux->apto;
	while (aux->apto != 1 && aux->apto != 0) {
		cout << endl << "    >Apto médico        : ";
		cin >> aux->apto;
	}*/
	aux->estado = true;
	return a;
}

int buscar_usuario(int codigo_buscado) {
	Usuario reg;
	FILE* f;
	int pos = 0;
	f = fopen("usuarios.dat", "rb");
	if (f == NULL) {
		return -1;
	}
	while (fread(&reg, sizeof(Usuario), 1, f)) {
		if (codigo_buscado == reg.ID) {
			fclose(f);
			return pos;
		}
		pos++;
	}
	fclose(f);
	return -1;
}

bool guardar_usuario(Usuario reg) {
	bool grabo;
	FILE* f;
	f = fopen("usuarios.dat", "ab");//crea el archivo y agrega registro al final
	if (f == NULL) {
		return false;
	}
	grabo = fwrite(&reg, sizeof(Usuario), 1, f);
	fclose(f);
	return grabo;
}
bool guardar_usuario2(Usuario reg) {
	bool grabo;
	FILE* f;
	f = fopen("usuarios.dat", "wb");//crea el archivo o lo reescribi
	if (f == NULL) {
		return false;
	}
	grabo = fwrite(&reg, sizeof(Usuario), 1, f);
	fclose(f);
	return grabo;
}

void listar_usuario() {
	Usuario reg;
	FILE* f;
	f = fopen("usuarios.dat", "rb");
	if (f == NULL) {
		cout << "No se puede leer el archivo.";
		return;
	}
	while (fread(&reg, sizeof(Usuario), 1, f)) {
		mostrar_usuario(reg);
		cout << endl;
	}
	fclose(f);
}
void mostrar_usuario(Usuario reg) {
	cout << "    ID                 : " << reg.ID << endl;
	cout << "    Nombres            : " << reg.nombres << endl;
	cout << "    Apellidos          : " << reg.apellidos << endl;
	mostrar_fecha(reg.nacimiento);
	cout << "    Altura             : " << reg.altura << " cm" << endl;
	cout << "    Peso               : " << reg.peso << " kg" << endl;
	mostrar_perfil_actividad(reg);
	cout << "    Apto médico        : " << reg.apto << endl;
	cout << "    Estado             : " << reg.estado << endl;
}

float cargar_altura() {
	float altura;
	cout << "    Altura(cm):";
	cin >> altura;
	while (altura < 0) {
		cout << "    >Altura(cm):";
		cin >> altura;
	}
	return altura;
}
float cargar_peso() {
	float peso;
	cout << "    Peso  (kg):";
	cin >> peso;
	while (peso < 0) {
		cout << "    >Peso  (kg):";
		cin >> peso;
	}
	return peso;
}

void listar_participante_x_id() {
	title("LISTADO DE PARTICIPANTE x ID");
	gotoxy(1, 5);
	int codigo, pos;
	cout << "    Ingresar código a buscar: ";
	cin >> codigo;
	pos = buscar_usuario(codigo);
	if (pos >= 0) {
		mostrar_usuario(leer_usuario(pos));
	}
	else {
		msj("No existe el participante", 15, 3);
	}
}
Usuario leer_usuario(int pos) {
	Usuario reg;
	FILE* p = fopen(FILE_USUARIOS, "rb");
	if (p == NULL) {
		reg.ID = 0;
		return reg;
	}
	fseek(p, pos * sizeof(Usuario), SEEK_SET);
	fread(&reg, sizeof(Usuario), 1, p);
	fclose(p);
	return reg;
}

int cargar_apto() {
	char opc;

	cout << "    Apto médico    (S/N): ";
	cin >> opc;
	switch (opc){
	case 's':
	case 'S':
		return 1;
		break;
	case 'n':
	case 'N':
		return 0;
		break;
	}
}
void mostrar_perfil_actividad(Usuario reg) {
	switch (reg.perfil){
	case 'a':
	case 'A': cout << "    Perfil de actividad: " << 'A' << endl;
		break;
	case 'b':
	case 'B': cout << "    Perfil de actividad: " << 'B' << endl;
		break;
	case 'c':
	case 'C': cout << "    Perfil de actividad: " << 'C' << endl;
		break;
	}
}
