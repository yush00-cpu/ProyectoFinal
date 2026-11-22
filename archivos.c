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
        contador = ftell(archivo) / sizeof(Escenario);
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

int darDeBajaArtista(int id){
FILE *archivo = fopen(ARCHIVO_ARTISTAS, "r+b");
Artista aux;
int encontrado = 0;

if(archivo != NULL){
    while(encontrado == 0 && fread(&aux, sizeof(Artista), 1, archivo)==1){
        if(aux.id == id && aux.activo == 1){
            aux.activo = 0;
            fseek(archivo, -(long)sizeof(Artista), SEEK_CUR);
            fwrite(&aux, sizeof(Artista), 1, archivo);
            encontrado = 1;
        }
    }
    fclose(archivo);
}
return encontrado;

}

int darDebajaEscenario(int id){
FILE *Archivo = fopen(ARCHIVO_ESCENARIO, "r+b");
Escenario aux;
int encontrado = 0;

if(Archivo != NULL){
    while(encontrado == 0 && fread(&aux, sizeof(Escenario),1,Archivo)==1){
        if(aux.id == id && aux.activo == 1){
            aux.activo = 0;
            fseek(Archivo, -(long)sizeof(Escenario), SEEK_CUR);
            fwrite(&aux, sizeof(Escenario), 1, Archivo);
            encontrado = 1;
        }
    }
    fclose(Archivo);
}
return encontrado;
}

Artista buscarArtistaPorId(int id){
    FILE *archivo = fopen(ARCHIVO_ARTISTAS, "rb");
    Artista aux;
    int encontrado = 0;

    if(archivo != NULL){
        while(encontrado == 0 && fread(&aux, sizeof(Artista), 1, archivo)==1){
            if(aux.id == id && aux.activo == 1){
                encontrado = 1;
            }
        }
        fclose(archivo);
    }
    if(encontrado == 0){
        aux.activo = 0;
    }
    return aux;
}


Escenario buscarEscenarioPorId(int id){
FILE *archivo = fopen(ARCHIVO_ESCENARIO, "rb");
int encontrado = 0;
Escenario aux;

if(archivo != NULL){
    while(encontrado == 0 && fread(&aux, sizeof(Escenario), 1, archivo)== 1){
        if(aux.id == id && aux.activo == 1){
            encontrado = 1;
        }
    }
    fclose(archivo);
}
if(encontrado == 0){
    aux.activo = 0;
}
return aux;
}

Presentacion buscarPresentacionPorId(int id){
FILE *archivo;
Presentacion aux;
int encontrado = 0;
archivo = fopen(ARCHIVO_PRESENTACIONES, "rb");

if(archivo !=NULL){
    while(encontrado == 0 && fread(&aux, sizeof(Presentacion), 1, archivo)== 1){
        if(aux.id == id && aux.activo == 1){
            encontrado = 1;
        }
    }
    fclose(archivo);
}
if(encontrado == 0){
    aux.activo = 0;
}
return aux;
}



int modificarArtista(Artista artistaModificado){
FILE *archivo;
archivo = fopen(ARCHIVO_ARTISTAS, "r+b");
int encontrado = 0;
Artista aux;

if(archivo != NULL){
    while(encontrado == 0 && fread(&aux, sizeof(Artista), 1, archivo)== 1){
        if(aux.id == artistaModificado.id && aux.activo == 1){
            artistaModificado.activo = 1;
            fseek(archivo, -(long)sizeof(Artista), SEEK_CUR);
            fwrite(&aux, sizeof(Artista), 1, archivo);
            encontrado = 1;
        }
    }
    fclose(archivo);
}

return encontrado;
}

int modificarEscenario(Escenario escenarioModificado){
    FILE *archivo;
    archivo = fopen(ARCHIVO_ESCENARIO, "r+b");
    int encontrado = 0;
    Escenario aux;

    if(archivo != NULL){
        while(encontrado == 0 && fread(&aux, sizeof(Escenario), 1, archivo)== 1){
            if(aux.id == escenarioModificado.id && aux.activo == 1){
                escenarioModificado.activo = 1;
                fseek(archivo, -(long)sizeof(Escenario), SEEK_CUR);
                fwrite(&escenarioModificado, sizeof(Escenario), 1, archivo);
                encontrado = 1;
            }
        }
        fclose(archivo);
    }
    return encontrado;
}


int obtenerSiguienteIdPresentacion(){
FILE *archivo = fopen(ARCHIVO_PRESENTACIONES, "rb");
int cantidad = 0;

if(archivo != NULL){
     fseek(archivo, 0, SEEK_END);
     cantidad = ftell(archivo) / sizeof(Presentacion);
     fclose(archivo);
}
return cantidad + 1;
}

int verificarSuperposicion(Presentacion presentacion){
FILE *archivo;
archivo = fopen(ARCHIVO_PRESENTACIONES, "rb");
Presentacion aux;
int superpuesto = 0;
int inicioNueva = presentacion.inicio.horas * 60 + presentacion.inicio.minutos;
int finNueva = inicioNueva + (presentacion.duracion.horas * 60 + presentacion.duracion.minutos);
int inicioExistente;
int finExistente;

if(archivo != NULL){
    while(superpuesto == 0 &&fread(&aux, sizeof(Presentacion), 1, archivo)== 1){
        if(aux.activo == 1 && aux.id != presentacion.id && aux.idEscenario == presentacion.idEscenario){
            inicioExistente = aux.inicio.horas * 60 + aux.inicio.minutos;
            finExistente = inicioExistente + (aux.duracion.horas * 60 + aux.duracion.minutos);

            if (inicioNueva < finExistente && inicioExistente < finNueva){
                superpuesto = 1;
            }
        }
    }
    fclose(archivo);
}
return superpuesto;
}

int guardarPresentacion(Presentacion presentacion){
FILE *archivo;
Artista art;
Escenario escen;

if(presentacion.inicio.esValido == 0 || presentacion.duracion.esValido == 0){
    return -1;
}

art = buscarArtistaPorId(presentacion.idArtista);
if(art.activo == 0){
    return -2;
}
escen = buscarEscenarioPorId(presentacion.idEscenario);
if(escen.activo == 0){
    return -3;
}
if(verificarSuperposicion(presentacion)== 1){
    return -4;
}

archivo = fopen(ARCHIVO_PRESENTACIONES, "ab");
if(archivo != NULL){
    presentacion.activo = 1;
    fwrite(&presentacion, sizeof(Presentacion), 1, archivo);
    fclose(archivo);
    return 1;
}
return 0;
}

void leerArchivoPresnetacion(){
FILE *archivo;
Presentacion aux;
archivo = fopen(ARCHIVO_PRESENTACIONES, "rb");

if(archivo != NULL){
    while(fread(&aux, sizeof(Presentacion), 1, archivo) == 1){
        if(aux.activo == 1){
            mostrarUnaPresentacion(aux);
        }
    }
    fclose(archivo);
}else
{
    printf("No hay presentaciones cargadas aun en el archivo. \n");
}
}

int darDeBajaPresentacion(int id){
FILE *archivo;
Presentacion aux;
int encontrado = 0;
archivo = fopen(ARCHIVO_PRESENTACIONES, "r+b");

if(archivo != NULL){
    while(encontrado == 0 && fread(&aux, sizeof(Presentacion), 1, archivo)== 1){
        if(aux.id == id && aux.activo == 1){
            aux.activo = 0;
            fseek(archivo, -(long)sizeof(Presentacion), SEEK_CUR);
            fwrite(&aux, sizeof(Presentacion),1, archivo);
            encontrado = 1;
        }
    }
    fclose(archivo);
}
return encontrado;
}

int modificarPresentacion(Presentacion presentacionModificada){
FILE *archivo;
Presentacion aux;
Artista art;
Escenario escen;
int encontrado = 0;

if(presentacionModificada.inicio.esValido == 0 || presentacionModificada.duracion.esValido == 0){
    return -1;
}

art = buscarArtistaPorId(presentacionModificada.idArtista);
if(art.activo == 0){
    return -2;
}
escen = buscarEscenarioPorId(presentacionModificada.idEscenario);
if(escen.activo == 0){
    return -3;
}

if(verificarSuperposicion(presentacionModificada) == 1){
    return -4;
}

archivo = fopen(ARCHIVO_PRESENTACIONES, "r+b");
if(archivo != NULL){
    while(encontrado == 0 && fread(&aux, sizeof(Presentacion), 1, archivo)==1){
        if(aux.id == presentacionModificada.id && aux.activo == 1){
            presentacionModificada.activo = 1;
            fseek(archivo, -(long)sizeof(Presentacion), SEEK_CUR        );
            fwrite(&presentacionModificada, sizeof(Presentacion), 1, archivo);
            encontrado = 1;
        }
    }
    fclose(archivo);
}
return encontrado;
}
