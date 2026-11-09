#include <Arduino.h>
#include "reloj.h"

// Datos simulados hasta tener el hardware

void InicializarReloj() {

    Serial.println("Inicializando reloj...");

    Serial.println("Reloj simulado listo.");

}

void ObtenerFechaHora(Medicion &medicion) {

    // Fecha y hora simuladas
    medicion.fecha_hora = "2026-11-08 23:00:00";

}
