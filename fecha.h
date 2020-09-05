#ifndef FECHA_H_INCLUDED
#define FECHA_H_INCLUDED

struct Fecha {
	int dia, mes, anio;
};

void mostrar_fecha(Fecha);

Fecha cargar_fecha();


#endif // FECHA_H_INCLUDED
