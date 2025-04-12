#include <DHT.h>
#include <DHT_U.h>

/*
  Para poder trabajar con este sensor denominado DHT 11, tenemos que descargar la librería.
  Para ver cómo hacerlo, leer página 10 del PDF.
*/

dht DHT; // Llamado a la librería
#define DHT11_PIN 8

void setup() {
  Serial.begin(9600);
}

void loop() {
  DHT.read11(DHT11_PIN); // Leemos lo que envía el sensor.

  // Temperatura:
  Serial.print("Temperatura = ");
  Serial.print(DHT.temperature);
  Serial.println("°C");

  // Humedad:
  Serial.print("Humedad = ");
  Serial.print(DHT.humidity);
  Serial.println("%");

  delay(2000); // Tomar los valores cada 2 segundos.
}
