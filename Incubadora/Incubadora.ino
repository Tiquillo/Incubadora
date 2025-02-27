// Disipark AtTiny85
// Luis Delgado
// Incubadora de huevos
// 10/2/2025
// Última actualización 27/2/2025

int bombillo = 1;     // En la placa digispark, es el pin 2
int bombillo1 = 0;    // para redundancia. En la placa digispark, es el pin 1
int termometro = A1;  // En la placa digispark, es el pin 3.

void setup() {
  pinMode(bombillo, OUTPUT);
  pinMode(bombillo1, OUTPUT);
  pinMode(termometro, INPUT);
}

// Calcula la temperatura
float Temperatura(int lectura) {
  return -0.08 * lectura + 65.6;
}

// Apagar bombillo
void TemperaturaAdecuada () {
  digitalWrite(bombillo, LOW);
  digitalWrite(bombillo1, LOW);
}

// Activar bombillo
void TemperaturaBaja () {
  digitalWrite(bombillo, HIGH);
  digitalWrite(bombillo1, HIGH);
}

// Función para revisar la temperatura
void ControlarTemperatura(lectura) {
  if (Temperatura(lectura) < 37.0) { // Para incubadora general
  //if (Temperatura(lectura) < 36.0) { // Para incubadora de don Bolívar
    TemperaturaBaja();

  } else if (Temperatura(lectura) > 38.0) { // Para incubadora general
    TemperaturaAdecuada();
  }
}

void loop() {

  int lectura = analogRead(termometro);

  //if(lectura < 345){    // Apagar el bombillo si la temperatura supera los 38 grados
  //  digitalWrite(bombillo, LOW);
  //  digitalWrite(bombillo1, LOW);
  //}else if (lectura > 358){ // Encender el bombillo si la temperatura baja de 37 grados
  //  digitalWrite(bombillo, HIGH);
  //  digitalWrite(bombillo1, HIGH);
  //}

  ControlarTemperatura(lectura);

  delay(3000);    // Una pausa para evitar que el bombillo se encienda y se apague tan frecuentemente
}