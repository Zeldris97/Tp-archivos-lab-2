#ifndef USUARIO_H_INCLUDED
#define USUARIO_H_INCLUDED

#include "fecha.h"

struct Usuario {
	int ID;
	char nombres[50];
	char apellidos[50];
	Fecha nacimiento;
	float altura;
	float peso;
	char perfil;
	bool apto;
	bool estado;
};


Usuario cargar_usuario();
int buscar_usuario(int);
bool guardar_usuario(Usuario);
void listar_usuario();
void mostrar_usuario(Usuario);
bool guardar_usuario2(Usuario);
void listar_participante_x_id();
Usuario leer_usuario(int pos);

float cargar_altura();
float cargar_peso();
int cargar_apto();
void mostrar_perfil_actividad(Usuario);


#endif // USUARIO_H_INCLUDED
