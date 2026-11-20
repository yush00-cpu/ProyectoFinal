#include <stdio.h>
#include "dominio.h"

void mostrarUnArtista(Artista artista)
{
    printf("---------------------------\n");
    printf("ID DEL ARTISTA: %d\n", artista.id);
    printf("NOMBRE: %s\n", artista.nombre);
    printf("GENERO: %s\n", artista.genero);
    printf("---------------------------\n");
}

void mostrarUnEscenario(Escenario escenario)
{
    printf("---------------------------------------------------\n");
    printf("ID DEL ESCENARIO: %d | NOMBRE DEL ESCENARIO: %s\n", escenario.id, escenario.nombre);
    printf("---------------------------------------------------\n");
}

void mostrarUnaPresentacion(Presentacion presentacion)
{
   printf("----------------------------------------------------------------------------------------------------\n");
    printf("ID PRESENTACION: %d | ID ARTISTA: %d | ID ESCENARIO: %d | INICIO: %02d:%02d | DURACION: %02d:%02d hs\n",
           presentacion.id,
           presentacion.idArtista,
           presentacion.idEscenario,
           presentacion.inicio.horas,
           presentacion.inicio.minutos,
           presentacion.duracion.horas,
           presentacion.duracion.minutos);
    printf("----------------------------------------------------------------------------------------------------\n");
}
