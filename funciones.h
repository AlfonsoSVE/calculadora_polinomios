#ifndef FUNCIONES_H
#define FUNCIONES_H

#include"funciones.h"
#include<stdio.h>
#include<string.h>
#include<stdlib.h>

typedef struct polinomio pol;
typedef struct monomio mon;

struct monomio{
	int grado;
	float coef;
	mon *sig;
};

struct polinomio{
	int num;
	mon *primero;
};

pol* crear_polinomio();
mon* crear_monomio(int e, float c);
pol* llenar_polinomio();
void agregar(pol *p, int e, float c);

#endif




