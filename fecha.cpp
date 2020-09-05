#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <cstring>
#include <locale.h>

using namespace std;
#include "fecha.h"
void mostrar_fecha(Fecha reg) {
	cout << "    Nacimiento         : ";
	cout << reg.dia << "/" << reg.mes << "/" << reg.anio << endl;
}

Fecha cargar_fecha() {
	Fecha aux;
	cout << endl;
	cout << "    D�a: ";
	cin >> aux.dia;
	while (aux.dia < 1 || aux.dia > 31) {
		cout << "    >D�a: ";
		cin >> aux.dia;
	}
	cout << "    Mes: ";
	cin >> aux.mes;
	while (aux.mes < 1 || aux.mes > 12) {
		cout << "    >Mes: ";
		cin >> aux.mes;
	}
	cout << "    A�o: ";
	cin >> aux.anio;
	while (aux.anio >2020) {
		cout << "    >A�o: ";
		cin >> aux.anio;
	}
	return aux;
}
