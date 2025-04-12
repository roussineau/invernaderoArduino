
/*
  Este sensor permite medir el nivel de un tanque de agua.
  Vamos a usar valores estandarizados, y cuando tengamos el proyecto
  funcionando podremos jugar con los valores para calibrar la distancia.
*/

/*
  Establecemos los pines del sensor.
  Primero, hay que establecer el PIN trigger como el PIN 10.
    El trigger manda un pulso de ultrasonido, y el echo se encarga de recibirlo.
  Por lo tanto, tenemos el tiempo que tarda en recibirlo y la velocidad, que es la del sonido.

  Como tenemos que ir hasta el objeto y volver, lo estamos
  calculando dos veces, así que hay que dividir por 2.

  Opcionalmente, podemos establecer un pin como un indicador de funcionamiento.
  En este caso, vamos a usar el PIN 13 para este fin.
*/

int TRIG = 10;
int ECO = 9;
int LED = 13;
int DURACION;
int DISTANCIA;

void setup() {
  pinMode(TRIG, OUTPUT); // El pin TRIG va a mandar un pulso.
  pinMode(ECO, INPUT); // El pin ECO va a recibirlo.
  pinMode(LED, OUTPUT); // El pin LED va a ser solo una señalización.
  Serial.Begin(9600); // Inicio el monitor serial a una transferencia de 9600 bits por segundo.
}

void loop() {
  digitalWrite(TRIG, HIGH); // Enviar un impulso alto de 1 milisegundo.
  delay(1);
  digitalWrite(TRIG, LOW);

  DURACION = pulseIn(ECO, HIGH); // Tiempo que se tarda en recibir el pulso.
  DISTANCIA = DURACION/58.2; // Fórmula para convertir el tiempo de referencia en centímetros.
  // Para más detalles, ver página 7 del PDF.

  Serial.printIn(DISTANCIA); // Se envía el valor a la CPU para obtener el dato.
  delay(200); // Demora entre dato y dato.

  if (DISTANCIA >= 0 && DISTANCIA <= 20) {
    digitalWrite(LED, HIGH); // Este será el indicador del detector de obstáculos
    delay(DISTANCIA*10); // Demora proporcional a la distancia.
    digitalWrite(LED, LOW);
  }
}
