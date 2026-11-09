#ifndef SENSOR_H
#define SENSOR_H
#include <Arduino.h>
#include <medicion.h>

// Inicializa el sensor
void InicializarSensor();


// Leer temperatura y humedad del sensor
void LeerDatosSensor(Medicion &medicion);

#endif
