// ENTRADAS Y SALIDAS:
const int bomba = 13; // SALIDA
const int humedad = A0; // ENTRADA (sensor de humedad)

void setup() {

  // Iniciamos el monitor serial a una transferencia de 9600 bits por segundo:
  Serial.begin(9600);

  // Declaramos entradas y salidas:
  pinMode(humedad, INPUT);
  pinMode(bomba, OUTPUT);

}

void loop() {

  // Leemos el valor de humedad:
  int SensorValue = analogRead(humedad);
  Serial.print(SensorValue); // Imprimimos el valor
  Serial.print("-");

  /*
  Un suelo ligeramente húmedo daría un valor de humedad menor a 700,
  mientras que un suelo seco daría un valor entre 800 y 1023. Se estableció
  el 700 pero se puede variar dependiendo de las necesidades de la planta.
  
  Para ver por qué ocurre esto, leer páginas 3 y 4 del PDF de Programación de Arduino.

  Por esta razón:
  */
  if SensorValue >= 700
  {
    Serial.Print("La tierra está seca, comienza el riego");
    digitalWrite(bomba, LOW); // Bomba ON
    delay(1000); // Tiempo de riego: 1 segundo
  }
  else
  {
    Serial.Print("La tierra está húmeda, se apaga el riego");
    digitalWrite(bomba, HIGH);
    delay(1000); // Tiempo  de riego: 1 segundo
  }
    
}
