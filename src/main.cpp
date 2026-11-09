#include <Arduino.h>
#include <sensor/sensor.h>
#include <medicion.h>
#include <reloj/reloj.h>
#include <pantalla/pantalla.h>

// Identificacion del dispositivo
const int ID_DISPOSITIVO = 1; // Cambiar a un valor unico para cada dispositivo

void setup() {
	Serial.begin(115200);
  	InicializarSensor();
}

void loop() {

	Medicion medicion;

	// Asignar el ID del dispositivo
	medicion.id_dispositivo = ID_DISPOSITIVO;

	// Leer datos del sensor
  	LeerDatosSensor(medicion);

	// Obtener fecha y hora
	ObtenerFechaHora(medicion);

	// Mostrar resultados
	MostrarPantalla(medicion);

	// Esperar 5 segundos antes de la siguiente medicion
    delay(5000);
}

