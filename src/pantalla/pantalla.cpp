#include <Arduino.h>
#include "pantalla.h"

void InicializarPantalla() {

    Serial.println("Inicializando pantalla...");

    Serial.println("Pantalla simulada lista.");

}

// Remplazar con la implementacion real de la pantalla en el futuro
void MostrarPantalla(const Medicion &medicion) {

    Serial.println("========================");
    Serial.println("    TERMOHIGROMETRO");
    Serial.println("========================");

    Serial.print("Dispositivo: ");
    Serial.println(medicion.id_dispositivo);

    Serial.print("Temperatura: ");
    Serial.print(medicion.temperatura);
    Serial.println(" C");

    Serial.print("Humedad: ");
    Serial.print(medicion.humedad);
    Serial.println(" %");

    Serial.print("Fecha: ");
    Serial.println(medicion.fecha_hora);

    Serial.println("========================");

}
