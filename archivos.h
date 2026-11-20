
#ifndef ARCHIVOS_H_INCLUDED
#define ARCHIVO_H_INCLUDED


#include "dominio.h"


#define ARCHIVO_ARTISTAS "artistas.dat"


/**
*@brief Calcula el proximo ID autoincremental disponible para un artista.
*@return Entero con el nuevo ID.
*/
int obtenerSiguienteIdArtista();

/**
*@brief Guarda un artista al final de un archivo binario.
*@param artista Estructura artista a persistir.
*/
void guardarArtista(Artista artista);

/**
*@brief Lee archivo binario y muestra a los artistas que estan activos.
*/
void leerArchivoArtistas();


#define ARCHIVO_ESCENARIO "escenario.dat"

/**
*@brief Calcula el proximo ID autoincremental disponible para un escenario.
*@return Entero con el nuevo ID. (empezando de 1)
*/
int obtenerSiguienteIdEscenario();

/**
*@brief Guarda un escenario al final del archivo binario.
*@param escenario Estructura escenario a persistir.
*/
void guardarEscenario(Escenario escenario);

/**
*@brief Lee el archivo binario y muestra por pantalla los escenarios que esten activos (1).
*/
void leerArchivoEscenarios();






#endif
