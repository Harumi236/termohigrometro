#include <Arduino.h>
#include "sensor.h"

// Pseudocodigo con datos hardcodeados para simular la lectura del sensor de temperatura y humedad
// Remplazar con la implementacion real del sensor en el futuro

// Inicializacion del sensor
void InicializarSensor() {

    Serial.println("Inicializando sensor...");

    Serial.println("Sensor simulado listo.");

}

// Lectura de temperatura
float LeerTemperatura() {

    // Valor simulado
    float temperatura = 19.5;

    return temperatura;

}

// Lectura de humedad
float LeerHumedad() {

    // Valor simulado
    float humedad = 52.3;

    return humedad;

}
