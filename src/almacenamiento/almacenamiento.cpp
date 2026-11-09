#include <Arduino.h>
#include "almacenamiento.h"

// Capacidad maxima de registros
const int CAPACIDAD_MAXIMA = 100;

// Arreglo de mediciones
Medicion registros[CAPACIDAD_MAXIMA];

// Cantidad actual de registros
int cantidad = 0;


// Inicializar almacenamiento
void InicializarAlmacenamiento() {

    cantidad = 0;

    Serial.println("Inicializando almacenamiento...");
    Serial.println("Almacenamiento simulado listo.");

}


// Guardar una medicion
void AlmacenarDatos(const Medicion &medicion) {

    if (cantidad < CAPACIDAD_MAXIMA) {

        // Todavia hay espacio disponible
        registros[cantidad] = medicion;

        cantidad++;

    } else {

        // Eliminar el registro mas antiguo
        for (int i = 0; i < CAPACIDAD_MAXIMA - 1; i++) {

            registros[i] = registros[i + 1];

        }

        // Guardar la nueva medicion al final
        registros[CAPACIDAD_MAXIMA - 1] = medicion;

        Serial.println("Almacenamiento lleno.");
        Serial.println("Registro mas antiguo eliminado.");

    }

    Serial.println("Medicion almacenada correctamente.");

}


// Consultar cantidad de registros
int CantidadRegistros() {

    return cantidad;

}


// Mostrar todos los registros
void MostrarRegistros() {

    Serial.println("=== HISTORIAL DE MEDICIONES ===");

    for (int i = 0; i < cantidad; i++) {

        Serial.print("Registro ");
        Serial.println(i + 1);

        Serial.print("Dispositivo: ");
        Serial.println(registros[i].id_dispositivo);

        Serial.print("Temperatura: ");
        Serial.println(registros[i].temperatura);

        Serial.print("Humedad: ");
        Serial.println(registros[i].humedad);

        Serial.print("Fecha: ");
        Serial.println(registros[i].fecha_hora);

        Serial.println("----------------------");

    }

}
