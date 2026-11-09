#include <Arduino.h>
#include <tareas/tareas.h>

void setup() {

    Serial.begin(115200);

    InicializarTareas();

}

void loop() {

    // Actualizar mediciones cada 15 segundos
    GestionarMediciones();

    // Almacenar mediciones cada 15 minutos
    GestionarAlmacenamiento();

    // Evaluar condiciones ambientales
    GestionarAlertas();

    // Gestionar comunicacion con la central
    GestionarTransmision();

}


