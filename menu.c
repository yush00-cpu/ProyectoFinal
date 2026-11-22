#include <stdlib.h>
#include <stdio.h>
#include "string.h"
#include "menu.h"
#include "archivos.h"

void limpiarBuffer();
void menuArtistas();
void menuEscenarios();
void menuPresentaciones();
void mostrarMensajeResultadoPresentacion(int resultado);


void limpiarBuffer()
{
    int c;
    while((c = getchar()) != '\n' && c != EOF);
}

void iniciarMenuPrincipal()
{
    int opccion;
    do
    {

        system("cls");
        printf("******************************\n");
        printf(" SISTEMA DE GESTION DEL FESTIVAL \n");
        printf("******************************\n");
        printf("1. Gestionar Artista.\n");
        printf("2. Gestionar Escenario.\n");
        printf("3. Gestionar Presentacion.\n");
        printf("0 salir...\n");
        printf("******************************\n");
        printf("SELECCIONE UNA OPCCION. \n");
        scanf("%d", &opccion);
        limpiarBuffer();

        switch(opccion)
        {
        case 1:
            menuArtistas();
            break;
        case 2:
            menuEscenarios();
            break;
        case 3:
            menuPresentaciones();
            break;
        case 0:
            printf("Saliendo del sistema....\n");
            break;
        default:
            printf("Opccion invalida.... \n");
            system("pause");
        }

    }
    while(opccion != 0);
}

void menuArtistas()
{
    int opccion;
    int id;
    Artista aux;

    do
    {
        system("cls");
        printf("**************************\n");
        printf("     MENU DE ARTISTAS     \n");
        printf("**************************\n");
        printf("1. Cargar nuevo artista.\n");
        printf("2. Mostrar artistas activos.\n");
        printf("3. Modificar artista. \n");
        printf("4. Dar de baja un artista. \n");
        printf("0. Salir al menu principal...\n");
        printf("**************************\n");
        printf("SELECCIONE UNA OPCCION. \n");
        scanf("%d", &opccion);
        limpiarBuffer();

        switch(opccion)
        {
        case 1:
            aux.id = obtenerSiguienteIdEscenario();
            printf("Ingrese nombre del artista a cargar: \n");
            fgets(aux.nombre, 50, stdin);
            aux.nombre [strcspn(aux.nombre, "\n")] = '\0';

            printf("Ingrese el genero musical del artista ingresado: \n");
            fgets(aux.genero, 50, stdin);
            aux.genero [strcspn(aux.genero, "\n")] = '\0';

            aux.activo = 1;
            guardarArtista(aux);
            printf("Artista cargado correctamente con ID: %d\n", aux.id);
            system("pause");
            break;
        case 2:
            printf("===LISTA DE ARTISTAS CARGADOS===\n");
            leerArchivoArtistas();
            system("pause");
            break;

        case 3:
            printf("Ingrese ID del artista a modificar.\n");
            scanf("%d", &id);
            limpiarBuffer();

            aux = buscarArtistaPorId(id);
            if(aux.activo == 1)
            {
                mostrarUnArtista(aux);
                printf("Ingrese el nuevo nombre: \n");
                fgets(aux.nombre, 50, stdin);
                aux.nombre [strcspn(aux.nombre, "\n")] = '\0';

                printf("Ingrese el nuevo genero: \n");
                fgets(aux.genero, 50, stdin);
                aux.genero [strcspn(aux.genero, "\n")] = '\0';

                if(modificarArtista(aux) == 1)
                {
                    printf("ARTISTA MODIFICADO CON EXITO.\n");
                }
                else
                {
                    printf("NO SE ENCONTRO ARTISTA CON EL ID INGRESADO.\n");
                }
            }
            system("pause");
            break;
        case 4:
            printf("Ingrese el ID del artista a dar de baja. \n");
            scanf("%d", &id);
            limpiarBuffer();

            if(darDeBajaArtista(id) == 1)
            {
                printf("ARTISTA DADO DE BAJA CORRECTAMENTE.\n");
            }
            else
            {
                printf("NO SE ENCONTRO ARTISTA CON EL ID INGRESADO. \n");
            }
            system("pause");
            break;

        case 0:
            break;

        default:
            printf("Opccion invalida..\n");
            system("pause");
        }
    }
    while(opccion != 0);

}


void menuEscenarios()
{
    int opccion;
    Escenario aux;
    int id;

    do
    {
        system("cls");
        printf("**************************\n");
        printf("    MENU DE ESCENARIOS    \n");
        printf("**************************\n");
        printf("1. Cargar nuevo escenario.\n");
        printf("2. Mostrar escenarios activos.\n");
        printf("3. Modificar escenario. \n");
        printf("4. Dar de baja un escenario. \n");
        printf("0. Salir al menu principal...\n");
        printf("**************************\n");
        printf("SELECCIONE UNA OPCCION. \n");
        scanf("%d", &opccion);
        limpiarBuffer();

        switch(opccion)
        {
        case 1:
            aux.id = obtenerSiguienteIdEscenario();
            printf("Ingrese nombre del nuevo escenario: \n");
            fgets(aux.nombre, 50, stdin);
            aux.nombre [strcspn(aux.nombre, "\n")] = '\0';

            aux.activo = 1;
            guardarEscenario(aux);
            printf("Escenario guardado con exito! con el ID: %d \n", aux.id);
            system("pause");
            break;

        case 2:
            printf("=== LISTA DE ESCENARIOS ACTIVOS ===\n");
            leerArchivoEscenarios();
            system("pause");
            break;
        case 3:
            printf("Ingrese ID del escenario que desea modificar: \n");
            scanf("%d", &id);
            limpiarBuffer();

            aux = buscarEscenarioPorId(id);
            if(aux.activo == 1)
            {
                mostrarUnEscenario(aux);
                printf("Ingrese su nuevo nombre: \n");
                fgets(aux.nombre, 50, stdin);
                aux.nombre [strcspn(aux.nombre, "\n")] = '\0';

                if(modificarEscenario(aux) == 1)
                {
                    printf("ESCENARIO MODIFICADO CON EXITO.\n");
                }
            }
            else
            {
                printf("NO SE ENCONTRO ESCENARIO CON ID INGRESADO.\n");
            }
            system("pause");
            break;
        case 4:
            printf("Ingrese ID del escenario que desea dar de baja. \n");
            scanf("%d", &id);
            limpiarBuffer();

            if(darDebajaEscenario(id) == 1)
            {
                printf("ESCENARIO DADO DE BAJA CON EXITO.\n");
            }
            else
            {
                printf("NO SE ENCONTRO ESCENARIO CON ID INGRESADO.\n");
            }
            system("pause");
            break;
        case 0:
            break;
        default:
            printf("Opccion no valida...\n");
            system("pause");

        }

    }
    while(opccion != 0);
}

void mostrarMensajeResultadoPresentacion(int resultado)
{
    switch(resultado)
    {
    case 1:
        printf("Operacion realizada con exito.\n");
        break;
    case -1:
        printf("ERROR: El horario o la duracion son invalidos.\n");
        break;
    case -2:
        printf("ERROR: No existe Artista activo con ese ID  .\n");
        break;
    case -3:
        printf("ERROR: No existe Escenario activo con ese ID  .\n");
        break;
    case -4:
        printf("ERROR: superposicion con el horario.\n");
        break;
    default:
        printf("Error al acceder al archivo PRESENTACIONES.\n");
        break;

    }

}

void menuPresentaciones()
{
int opccion;
int id;
int horas;
int minutos;
int resultado;
Presentacion aux;
do{
        system("cls");
    printf("0000000000000000000000000000000000000000000000000\n");
    printf("00000000000 GESTION DE PRESENTACIONES 00000000000\n");
    printf("0000000000000000000000000000000000000000000000000\n");
    printf("1. Cargar nueva presentacion.\n");
    printf("2. Mostrar Presentaciones Activas.\n");
    printf("3. Modificar presentacion.\n");
    printf("4. Dar de baja una presentacion.\n");
    printf("0. Volver al menu principal...\n");
    printf("_________________________________________________\n");
    printf("Seleccione una opccion. \n");
    scanf("%d", &opccion);
    limpiarBuffer();

    switch(opccion){
case 1:
    aux.id = obtenerSiguienteIdPresentacion();
    printf("Ingrese ID del artista: \n");
    scanf("%d", &aux.idArtista);
    limpiarBuffer();

    printf("Ingrese ID del escenario: \n");
    scanf("%d", &aux.idEscenario);
    limpiarBuffer();

    printf("Ingrese hora de incio (0 - 23)\n");
    scanf("%d", &horas);
    limpiarBuffer();

    printf("Ingrese minutos de inicio (0-59) \n");
    scanf("%d", &minutos);
    limpiarBuffer();
    aux.inicio = crearUnHorario(horas, minutos);

    printf("Ingrese horas de duracion: \n");
    scanf("%d", &horas);
    limpiarBuffer();

    printf("Ingrese minutos de duracion (0-59) \n");
    scanf("%d", &minutos);
    limpiarBuffer();

    aux.duracion = crearDuracion(horas, minutos);

    resultado = guardarPresentacion(aux);
    mostrarMensajeResultadoPresentacion(resultado);
    system("pause");
    break;

case 2:
        printf("uwuwuwuwuwuw LISTA DE PRESENTACIONES uwuwuwuwuwuw\n");
        leerArchivoPresnetacion();
        system("pause");
        break;

case 3:
    printf("Ingrese ID de la presentacion que desea modificar. \n");
    scanf("%d", &id);
    limpiarBuffer();

    aux = buscarPresentacionPorId(id);
    if(aux.activo == 1){
        mostrarUnaPresentacion(aux);

        printf("Ingresa nuevo ID artista: \n");
        scanf("%d", &aux.idArtista);
        limpiarBuffer();

        printf("Ingresa nuevo ID escenario: \n");
        scanf("%d", &aux.idEscenario);
        limpiarBuffer();

        printf("Ingrese nueva hora de inicio: (0-23)\n");
        scanf("%d", &horas);
        limpiarBuffer();

        printf("Ingrese nuevos minutos de inicio: (0-59)\n");
        scanf("%d", &minutos);
        limpiarBuffer();
        crearUnHorario(horas, minutos);

        printf("Ingresa nueva hora de duracion: \n");
        scanf("%d", &horas);
        limpiarBuffer();

        printf("Ingresa nuevos minutos de duracion (0-59)\n");
        scanf("%d", &minutos);
        limpiarBuffer();
        crearDuracion(horas, minutos);

        resultado = modificarPresentacion(aux);
        mostrarMensajeResultadoPresentacion(resultado);

    }else
    {
        printf("No se encontro una presentacion activa con ese ID.\n");
    }
        system("pause");
            break;


case 4:
    printf("Ingrese ID de la presentacion que desea dar de baja: \n");
    scanf("%d", &id);
    limpiarBuffer();

    if(darDeBajaPresentacion(id) == 1){
        printf("La presentacion se dio de baja de forma correcta!\n");
    }else
    {
        printf("No se encontro presentacion con ese ID.\n");
    }
    system("pause");
    break;

case 0:
    break;
default:
    printf("Opccion invalidad \n");
    system("pause");
    }

}while(opccion != 0);



}
