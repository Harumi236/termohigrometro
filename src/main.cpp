#include <Arduino.h>
#include <sensor/sensor.h>



void setup() {
	Serial.begin(115200);
  	InicializarSensor();
}

void loop() {

  	float temperatura = LeerTemperatura();
  	float humedad = LeerHumedad();

	Serial.print("Temperatura: ");
 	Serial.print(temperatura);
  	Serial.println(" °C");

  	Serial.print("Humedad: ");
  	Serial.print(humedad);
  	Serial.println(" %");

	delay(5000); // Espera 5 segundos antes de la siguiente lectura
}

