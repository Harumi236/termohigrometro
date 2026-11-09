#ifndef MEDICION_H
#define MEDICION_H

#include <Arduino.h>

// Estructura para almacenar los datos de medición
struct Medicion {

    int id_dispositivo;

    float temperatura;
    float humedad;

    String fecha_hora;

};

#endif