#include <Arduino.h>
#include <sensor/sensor.h>
#include <medicion.h>
#include <reloj/reloj.h>

// Identificacion del dispositivo
const int ID_DISPOSITIVO = 1; // Cambiar a un valor unico para cada dispositivo

void setup() {
	Serial.begin(115200);
  	InicializarSensor();
}

void loop() {

	Medicion medicion;

	medicion.id_dispositivo = ID_DISPOSITIVO;

  	LeerDatosSensor(medicion);

	ObtenerFechaHora(medicion);


	// Mostrar resultados
    Serial.println("----------------------");

    Serial.print("Dispositivo: ");
    Serial.println(medicion.id_dispositivo);

    Serial.print("Temperatura: ");
    Serial.print(medicion.temperatura);
    Serial.println(" °C");

    Serial.print("Humedad: ");
    Serial.print(medicion.humedad);
    Serial.println(" %");

	Serial.print("Fecha y hora: ");
    Serial.println(medicion.fecha_hora);

    delay(5000);
}

