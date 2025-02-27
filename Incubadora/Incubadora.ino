// Disipark AtTiny85
// Luis Delgado
// Incubadora de huevos
// 10/2/2025
// Última actualización 18/2/2025

int bombillo = 1;
int bombillo1 = 0; // para redundancia
int termometro = A1;

void setup() {
  pinMode(bombillo, OUTPUT);
  pinMode(bombillo1, OUTPUT);
  pinMode(termometro, INPUT);
}

void loop() {

  // Para un divisor de tensión perfecto se usa 640 como referencia a 37 grados

  int lectura = analogRead(termometro);

  if(lectura < 345){
    digitalWrite(bombillo, LOW);
    digitalWrite(bombillo1, LOW);
  }else if (lectura > 370){
    digitalWrite(bombillo, HIGH);
    digitalWrite(bombillo1, HIGH);
  }
  delay(5000);
}