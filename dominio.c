#include <stdio.h>
#include "dominio.h"

void mostrarUnArtista(Artista artista){
    printf("**ID DEL ARTISTA: %d || NOMBRE: %s || GENERO: %s**\n", artista.id, artista.nombre, artista.genero);
}

void mostrarUnEscenario(Escenario escenario){
    printf("**ID DEL ESCENARIO: %d || NOMBRE DEL ESCENARIO: %s**\n", escenario.id, escenario.nombre);
}

void mostrarUnaPresentacion(Presentacion presentacion){
    printf("**ID DE LA PRESENTACION: %d || ID ARTISTA: %d || ID ESCENARIO: %d || INICIO DEL SHOW: %02d:%02d || DURACION DEL SHOW: %02d:%02d hs**\n",
           presentacion.id,
           presentacion.idArtista,
           presentacion.idEscenario,
           presentacion.inicio.horas,
           presentacion.inicio.minutos,
           presentacion.duracion.horas,
           presentacion.duracion.minutos);

}
