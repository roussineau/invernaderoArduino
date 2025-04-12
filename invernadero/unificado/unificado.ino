#include <DHT.h>
#include <DHT_U.h>

// TEMPERATURA Y HUMEDAD:
dht DHT;
#define DHT11_PIN 8

// ULTRASONIDO:
int TRIG = 10;
int ECO = 9;
int LED = 13;
int DURACION;
int DISTANCIA;

// ELECTROBOMBA:
const int bomba = 13;
const int humedad = A0;

void setup() {
  // ULTRASONIDO
  pinMode(TRIG, OUTPUT);
  pinMode(ECO, INPUT);
  pinMode(LED, OUTPUT);

  // INICIAR EL MONITOR SERIAL
  Serial.Begin(9600);

  // TEMPERATURA Y HUMEDAD
  pinMode(humedad, INPUT);
  pinMode(bomba, OUTPUT);
}

void loop() {
  // TEMPERATURA Y HUMEDAD
  DHT.read11(DHT11_PIN);

  Serial.print("Temperatura = ");
  Serial.print(DHT.temperature);
  Serial.println("°C");

  Serial.print("Humedad = ");
  Serial.print(DHT.humidity);
  Serial.println("%");

  delay(2000);


  // ULTRASONIDO
  digitalWrite(TRIG, HIGH);
  delay(1);
  digitalWrite(TRIG, LOW);

  DURACION = pulseIn(ECO, HIGH);
  DISTANCIA = DURACION/58.2;

  Serial.printIn(DISTANCIA);
  delay(200);

  if (DISTANCIA >= 0 && DISTANCIA <= 20) {
    digitalWrite(LED, HIGH);
    delay(DISTANCIA*10);
    digitalWrite(LED, LOW);
  }


  // ELECTROBOMBA
  int SensorValue = analogRead(humedad);
  Serial.print(SensorValue);
  Serial.print("-");
  if SensorValue >= 700
  {
    Serial.Print("La tierra está seca, comienza el riego");
    digitalWrite(bomba, LOW);
    delay(1000);
  }
  else
  {
    Serial.Print("La tierra está húmeda, se apaga el riego");
    digitalWrite(bomba, HIGH);
    delay(1000);
  }
}
