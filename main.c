#include <stdio.h>
#include <stdlib.h>
#include "string.h"
#include "tiposSeguros.h"
#include "dominio.h"
#include "archivos.h"

int main()
{
    system("color 0b");
    Horario h1 = crearUnHorario(21, 30);
    Horario h2 = crearUnHorario(25, 10);


    printf("Horario 21:30 valido: %d\n", h1.esValido);
    printf("Horario 25:10 valido: %d\n", h2.esValido);

    Artista a1;
    a1.id = obtenerSiguienteIdArtista();

    printf("Ingresa el nombre del artista invitado.\n");
    fgets(a1.nombre, 50, stdin);
    a1.nombre [strcspn(a1.nombre, "\n")] = '\0';

    printf("Ingresa el genero del artista invitado.\n");
    fgets(a1.genero, 50, stdin);
    a1.genero [strcspn(a1.genero, "\n")] = '\0';

    a1.activo = 1;

    guardarArtista(a1);
    leerArchivoArtistas();

    Escenario e1;
    e1.id = obtenerSiguienteIdEscenario();
    printf("Ingresa el nombre del escenario.\n");
    fgets(e1.nombre, 50, stdin);
    e1.nombre [strcspn(e1.nombre, "\n")] = '\0';
    e1.activo = 1;

    guardarEscenario(e1);
    leerArchivoEscenarios();


    return 0;
}
