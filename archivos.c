#include <stdio.h>
#include "archivos.h"


int obtenerSiguienteIdArtista()
{
    FILE *archivo;
    archivo = fopen(ARCHIVO_ARTISTAS, "rb");
    int cantidad = 0;

    if(archivo != NULL)
    {
        fseek(archivo, 0, SEEK_END);
        cantidad = ftell(archivo) / sizeof(Artista);
        fclose(archivo);
    }
    return cantidad + 1;
}

void guardarArtista(Artista artista)
{
    FILE *archivo;
    archivo = fopen(ARCHIVO_ARTISTAS, "ab");
    if(archivo != NULL)
    {
        fwrite(&artista, sizeof(Artista), 1, archivo);
        fclose(archivo);
    }

}

void leerArchivoArtistas()
{
    FILE *archivo;
    archivo = fopen(ARCHIVO_ARTISTAS, "rb");
    Artista aux;

    if(archivo != NULL)
    {
        while(fread (&aux, sizeof(Artista),1,archivo)==1)
        {
            if(aux.activo == 1)
            {
                mostrarUnArtista(aux);
            }
        }
        fclose(archivo);
    }
    else
    {
        printf("NO HAY ARTISTAS CARGADOS AUN :3\n");
    }

}

int obtenerSiguienteIdEscenario()
{
    FILE *archivo;
    archivo = fopen(ARCHIVO_ESCENARIO, "rb");
    int contador = 0;
    if(archivo !=NULL)
    {
        fseek(archivo, 0, SEEK_END);
        contador = ftell(archivo) / sizeof(Artista);
        fclose(archivo);
    }
    return contador + 1;

}

void guardarEscenario(Escenario escenario)
{
    FILE *archivo;
    archivo = fopen(ARCHIVO_ESCENARIO, "ab");
    if(archivo != NULL)
    {
        fwrite(&escenario, sizeof(Escenario), 1, archivo);
        fclose(archivo);
    }
}

void leerArchivoEscenarios()
{
    FILE *archivo;
    archivo = fopen(ARCHIVO_ESCENARIO, "rb");
    Escenario aux;

    if(archivo != NULL)
    {
        while(fread(&aux, sizeof(Escenario), 1, archivo)== 1)
        {
            mostrarUnEscenario(aux);
        }
        fclose(archivo);
    }
    else
    {
        printf("No hay escenarios cargados aun :_( \n");
    }

}


