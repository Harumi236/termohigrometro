#include <Arduino.h>
#include <sensor/sensor.h>
#include <medicion.h>
#include <reloj/reloj.h>
#include <pantalla/pantalla.h>
#include <almacenamiento/almacenamiento.h>

// Identificacion del dispositivo
const int ID_DISPOSITIVO = 1; // Cambiar a un valor unico para cada dispositivo

// Intervalos de funcionamiento
const unsigned long INTERVALO_MEDICION = 15000;
const unsigned long INTERVALO_REGISTRO = 900000;

// Temporizadores
unsigned long ultima_medicion = 0;
unsigned long ultimo_registro = 0;

// Ultima medicion realizada
Medicion medicion_actual;

bool hay_medicion = false;

void setup() {

    Serial.begin(115200);

    InicializarSensor();
    InicializarReloj();
    InicializarPantalla();
    InicializarAlmacenamiento();

    // Primera medicion inmediata
    RealizarMedicion();

	// Registrar temporizadores para la primera medicion y registro
    unsigned long ahora = millis();
    ultima_medicion = ahora;
    ultimo_registro = ahora;

}

// Realiza una medicion, la almacena en actual y la muestra en pantalla
void RealizarMedicion() {
	medicion_actual.id_dispositivo = ID_DISPOSITIVO;
	LeerDatosSensor(medicion_actual);
	ObtenerFechaHora(medicion_actual);
	MostrarPantalla(medicion_actual);

	hay_medicion = true;

	// FUTURO:
    // Evaluar si existe un pico ambiental.
    // Si existe, generar una alerta.
}

void loop() {

	unsigned long ahora = millis();

	// 1. Medicion y actualizacion de pantalla
    if (ahora - ultima_medicion >= INTERVALO_MEDICION) {

        ultima_medicion = ahora;

        RealizarMedicion();

    }

	// 2. Almacenamiento y transmision periodica
    if (ahora - ultimo_registro >= INTERVALO_REGISTRO) {

        ultimo_registro = ahora;

        if (hay_medicion) {

            AlmacenarDatos(medicion_actual);

            Serial.println("Registro periodico realizado.");

            // FUTURO:
            // EnviarDatos(medicion_actual);

        }

    }

}

