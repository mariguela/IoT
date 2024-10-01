const int sensorPin = 2; // Pino GPIO 2 conectado ao OUT do sensor

void setup() {
  Serial.begin(115200); // Inicializa a comunicação serial
  pinMode(sensorPin, INPUT); // Define o pino do sensor como entrada
}

void loop() {
   int sensorValue = digitalRead(sensorPin); // Lê o estado do sensor

   if (sensorValue == HIGH) {
      Serial.println("Movimento detectado!"); // Imprime se houver movimento
    } else {
      Serial.println("Sem movimento..."); // Imprime se não houver movimento
  }

   delay(500); // Aguarda 500 milissegundos antes da próxima leitura
}
