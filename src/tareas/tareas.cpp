#include <Arduino.h>

#include "medicion.h"
#include <configuracion/configuracion.h>

#include "sensor/sensor.h"
#include "reloj/reloj.h"
#include "pantalla/pantalla.h"
#include "almacenamiento/almacenamiento.h"

// Intervalos de funcionamiento
const unsigned long INTERVALO_MEDICION = 15000;
const unsigned long INTERVALO_REGISTRO = 900000;

// Temporizadores independientes
unsigned long ultima_medicion = 0;
unsigned long ultimo_registro = 0;

// Ultima medicion disponible
Medicion medicion_actual;

bool hay_medicion = false;

void RealizarMedicion();

// Inicializacion general de tareas
void InicializarTareas() {

    Serial.println("Inicializando sistema...");

    InicializarSensor();
    InicializarReloj();
    InicializarPantalla();
    InicializarAlmacenamiento();

    unsigned long ahora = millis();

    ultima_medicion = ahora;
    ultimo_registro = ahora;

    // Primera medicion inmediata
    RealizarMedicion();

}


// Obtener y mostrar una medicion
void RealizarMedicion() {

    medicion_actual.id_dispositivo = Configuracion::ID_DISPOSITIVO;

    LeerDatosSensor(medicion_actual);

    ObtenerFechaHora(medicion_actual);

    MostrarPantalla(medicion_actual);

    hay_medicion = true;

}


// Gestionar mediciones cada 15 segundos
void GestionarMediciones() {

    unsigned long ahora = millis();

    if (ahora - ultima_medicion >= Configuracion::INTERVALO_MEDICION) {

        ultima_medicion = ahora;

        RealizarMedicion();

    }

}


// Gestionar almacenamiento cada 15 minutos
void GestionarAlmacenamiento() {

    unsigned long ahora = millis();

    if (ahora - ultimo_registro >= Configuracion::INTERVALO_REGISTRO) {

        ultimo_registro = ahora;

        if (hay_medicion) {

            AlmacenarDatos(medicion_actual);

            Serial.println("Registro periodico realizado.");

        }

    }

}


// Gestionar alertas
void GestionarAlertas() {

    if (!hay_medicion) {
        return;
    }

    // FUTURO:
    // Evaluar temperatura y humedad.
    // Detectar picos o valores fuera de rango.
    // Generar eventos de alerta.

}


// Gestionar transmision
void GestionarTransmision() {

    // FUTURO:
    // Verificar si corresponde transmitir.
    // Comprobar disponibilidad de comunicacion.
    // Enviar medicion a la central.
    // Gestionar confirmacion de recepcion.

}