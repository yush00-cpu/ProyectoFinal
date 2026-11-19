#ifndef TIPOSSEGUROS_H_INCLUDED
#define TIPOSSEGUROS_H_INCLUDED

typedef struct{
int minutos;
int horas;
int esValido; // 1 = valido || 0 = invalido.
}Horario;

typedef struct{
int minutos;
int horas;
int esValido; // 1 = valido || 0 0 invalido.
}Duracion;


/**
* @brief Crea y valida un horario dentro del reloj de 24hs (00:00 a 23:59)
* @param horas Horas de inicio (0 a 23)
* @param minutos Minutos de inicio (0 a 59).
* @return Horario con esValido en 1 si es correcto, 0 si esta fuera de rango.
*/

Horario crearUnHorario(int hora, int minutos);

/**
* @brief Crea y valida una Duracion positiva (mayor a 0 minutos en total).
* @param horas Cantidad de Horas (>= 0).
* @param minutos Cantidad de Minutos (0 a 59).
* @return Duracion con esValidos en 1 si es correcto, o 0 si no.
*/

Duracion crearDuracion(int hora, int minuto);

#endif
