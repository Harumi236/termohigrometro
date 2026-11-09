#include <Arduino.h>
#include "sensor.h"

// Pseudocodigo con datos hardcodeados para simular la lectura del sensor de temperatura y humedad
// Remplazar con la implementacion real del sensor en el futuro

// Inicializacion del sensor
void InicializarSensor() {

    Serial.println("Inicializando sensor...");

    Serial.println("Sensor simulado listo.");

}

// Leer temperatura y humedad del sensor
void LeerDatosSensor(Medicion &medicion) {
    medicion.temperatura = 912.0; // LeerTemperatura();
    medicion.humedad = 12.0; // LeerHumedad();
}
