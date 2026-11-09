
#include <Arduino.h>

#include "almacenamiento.h"
#include "configuracion/configuracion.h"


// ======================================
// VARIABLES DE ALMACENAMIENTO
// ======================================

// Arreglo de mediciones en memoria RAM
Medicion registros[Configuracion::CAPACIDAD_MAXIMA];

// Cantidad actual de registros
int cantidad = 0;


// ======================================
// INICIALIZAR ALMACENAMIENTO
// ======================================

void InicializarAlmacenamiento() {

    cantidad = 0;

    Serial.println("Inicializando almacenamiento...");

    Serial.print("Capacidad maxima: ");
    Serial.println(Configuracion::CAPACIDAD_MAXIMA);

    Serial.println("Almacenamiento RAM listo.");

}


// ======================================
// ALMACENAR DATOS
// ======================================

void AlmacenarDatos(const Medicion &medicion) {

    if (cantidad < Configuracion::CAPACIDAD_MAXIMA) {

        // Todavia hay espacio disponible
        registros[cantidad] = medicion;

        cantidad++;

    } else {

        // Eliminar el registro mas antiguo
        for (int i = 0; i < Configuracion::CAPACIDAD_MAXIMA - 1; i++) {

            registros[i] = registros[i + 1];

        }

        // Guardar la nueva medicion al final
        registros[Configuracion::CAPACIDAD_MAXIMA - 1] = medicion;

        Serial.println("Almacenamiento lleno.");

        Serial.println("Registro mas antiguo eliminado.");

    }

    Serial.println("Medicion almacenada correctamente.");

}


// ======================================
// CONSULTAR CANTIDAD DE REGISTROS
// ======================================

int CantidadRegistros() {

    return cantidad;

}


// ======================================
// MOSTRAR HISTORIAL
// ======================================

void MostrarRegistros() {

    Serial.println("==============================");

    Serial.println("HISTORIAL DE MEDICIONES");

    Serial.println("==============================");

    for (int i = 0; i < cantidad; i++) {

        Serial.print("Registro: ");
        Serial.println(i + 1);

        Serial.print("Dispositivo: ");
        Serial.println(registros[i].id_dispositivo);

        Serial.print("Temperatura: ");
        Serial.print(registros[i].temperatura);
        Serial.println(" C");

        Serial.print("Humedad: ");
        Serial.print(registros[i].humedad);
        Serial.println(" %");

        Serial.print("Fecha y hora: ");
        Serial.println(registros[i].fecha_hora);

        Serial.println("------------------------------");

    }

    Serial.print("Total de registros: ");
    Serial.println(cantidad);

    Serial.println("==============================");

}
