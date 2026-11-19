#include <stdio.h>
#include <stdlib.h>
#include "tiposSeguros.h"
#include "dominio.h"

int main()
{
    system("color 0b");
    Horario h1 = crearUnHorario(21, 30);
    Horario h2 = crearUnHorario(25, 10);
    Horario h3 = crearUnHorario(29, 30);

    printf("Horario 21:30 valido: %d\n", h1.esValido);
    printf("Horario 25:10 valido: %d\n", h2.esValido);
    printf("Horario 29:30 valido: %d\n", h3.esValido);


    return 0;
}
