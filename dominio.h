#ifndef DOMINIO_H_INCLUDED
#define DOMINIO_H_INCLUDED
#define TAM_MAX 50
#include "tiposSeguros.h"

typedef struct{
int id;
char nombre[TAM_MAX];
char genero[TAM_MAX];
int activo; /// 1 = si || 0 = no.

}Artista;

typedef struct{
int id;
char nombre[TAM_MAX];
int activo; /// 1 = si || 0 = no.

}Escenario;

typedef struct{
int id;
int idArtista;
int idEscenario;
Horario inicio;
Duracion duracion;
int activo; /// 1 = si || 0 = no.

}Presentacion;

/**
*@brief Muestra por pantalla los datos de un artista.
*@param artista Estructura artista para imprimir.
*/
void mostrarUnArtista(Artista artista);

/**
*@brief Muestra por pantalla los datos de un escenario.
*@param escenario Estructura escenario para imprimir.
*/
void mostrarUnEscenario(Escenario escenario);

/**
*@brief Muestra por pantalla los datos de una presentacion.
*@param presentacion Estructura presentacion para imprimir.
*/
void mostrarUnaPresentacion(Presentacion presentacion);

#endif
