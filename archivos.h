
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

/**
*@brief Realiza la baja logica de un Artista cambiando su estado Activo a 0.
*@param  Id identificador de un Artista a dar de baja.
*@return 1 si se dio de baja de forma correcta || 0 si no se encontro activo.
*/

int darDeBajaArtista(int id);

/**
*@brief Realiza la baja logica de un escenario cambiando su estado activo a 0.
*@param Id identificador de un Escenario a dar de baja.
*@return 1 si se dio de baja de forma correcta || 0 si no se encontro activo.
*/
int darDebajaEscenario(int id);


/**
*@brief Buscar un artista activo por su ID.
*@param ID identificador del Artista a buscar.
*@return Estructura Artista encontrada y si no existe o esta inactivo retorna Activo = 0.
*/

Artista buscarArtistaPorId(int id);

/**
*@brief Buscar un escenario activo por su ID.
*@param ID identificador de un Escenario a buscar.
*@return Estructura Escenario encontrada y si no existe o esta inactivo retorna Activo = 0.
*/

Escenario buscarEscenarioPorId(int id);

/**
*@brief Buscar una presentacion activa por su ID.
*@param ID identificador de una presentacion a buscar.
*@return Estructura Presentacion encontrada y si no existe o esta incativa retorta activo = 0.
*/
Presentacion buscarPresentacionPorId(int id);

/**
*@brief Sobrescribe los datos de un artista activo existente en el archivo.
*@param artistaModificado Estructura Artista con el ID a buscar y los nuevos datos.
*@return 1 si se modifico correctamente || 0 si no se encontro activo.
*/
int modificarArtista(Artista artistaModificado);


/**
*@brief Sobrescribe los datos de un escenario activo existente en el archivo.
*@param escenarioModificado Estructura Escenario con el ID a buscar y los nuevos datos.
*@return 1 si se modifica correctamente || 0 si no se encontro activo.
*/
int modificarEscenario(Escenario escenarioModificado);


#define ARCHIVO_PRESENTACIONES "presentaciones.dat"

/**
*@brief Calcula el proximo ID autoincremetal disponible para la proxima presentacion.
*@return Un entero con el nuevo ID para la presentacion (empezando desde 1).
*/

int obtenerSiguienteIdPresentacion();


/**
*@brief Verifica si hay una una presentacion pisa el horario de otra activa en el mismo escenario.
*@param Presentacion Estructura Presentacion a verificar.
*@return 1 si hay una superposicion || 0 si el horario esta habilitado.
*/
int verificarSuperposicion(Presentacion presentacion);


/**
*@brief Valida y guarda una presentacion al final del archivo binario.
*@param presentacion Estructura Presentacion
*@return 1 si se guardo || -1 si hay un horario o duracion invalida || -2 artista inexistente || -4 superposicion || 0 error de archivo.
*/
int guardarPresentacion(Presentacion presentacion);


/**
*@brief Lee archivo binario y muestra por pantalla los shows activos.
*/
void leerArchivoPresnetacion();

/**
*@brief realiza la baja logica de una presentacion cambiando su estado activo a 0.
*@param El ID unico  identificador de la presentacion.
*@return 1 si se dio de baja correctamente || 0 si no se encontro la presentacion activa.
*/
int darDeBajaPresentacion(int id);


/**
*@brief Valida y sobreescribe los datos de una presentacion activa que exista
*@param presentacionModificada Estructura Presentacion con el ID A buscar y los nuevos datos.
*@return 1 si se modifico correctamente || -1 si hay un horario o duracion invalida || -2 artista inexistente || -4 superposicion || 0 error de archivo.
*/


int modificarPresentacion(Presentacion presentacionModificada);

#endif
