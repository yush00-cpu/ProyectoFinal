#include "tiposSeguros.h"






Horario crearUnHorario(int horas, int minutos){
Horario h;
h.horas = horas;
h.minutos = minutos;

if(horas >= 0 && horas <= 23 && minutos >= 0 && minutos <= 59){
    h.esValido = 1;
}else
{
    h.esValido = 0;
}
return h;


}



Duracion crearDuracion(int hora, int minuto){
Duracion d;
d.horas = hora;
d.minutos = minuto;

if(hora >= 0 && minuto >= 0 && minuto <= 59 && (hora > 0 || minuto > 0)){
    d.esValido = 1;
}else{
    d.esValido = 0;
}

return d;
}
