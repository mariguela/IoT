#include <WiFi.h>
#include <PubSubClient.h>

const int sensorPin = 2; // Pino GPIO 2 conectado ao OUT do sensor
const int ledPin = 5;    // Pino GPIO 5 conectado ao LED

const char* ssid = "REDEWIFI";
const char* password = "SENHAWIFI";
const char* mqttServer = "18.228.117.52";
const int port = 1883;
const char* mqttUser = "grupo01";       // Adicione seu usuário MQTT
const char* mqttPassword = "grupo01";    // Adicione sua senha MQTT

char clientId[50];
WiFiClient espClient;
PubSubClient client(espClient);

bool lastSensorState = LOW; // Para detectar mudanças no estado do sensor

void setup() {
  Serial.begin(115200);
  delay(10);
  
  Serial.println();
  Serial.print("Conectando-se a ");
  Serial.println(ssid);

  wifiConnect();

  Serial.println("");
  Serial.println("WiFi conectado");
  Serial.println("Endereço IP: ");
  Serial.println(WiFi.localIP());
  Serial.print("MAC Address: ");
  Serial.println(WiFi.macAddress());

  client.setServer(mqttServer, port);
  client.setCallback(callback);

  pinMode(ledPin, OUTPUT);
  pinMode(sensorPin, INPUT); // Define o pino do sensor como entrada
}

void wifiConnect() {
  WiFi.mode(WIFI_STA);
  WiFi.begin(ssid, password);
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }
}

void mqttReconnect() {
  while (!client.connected()) {
    Serial.print("Tentando conectar ao MQTT...");
    long r = random(1000);
    sprintf(clientId, "clientId-%ld", r);
    if (client.connect(clientId, mqttUser, mqttPassword)) { // Inclui usuário e senha
      Serial.print("Conectado com ID: ");
      Serial.println(clientId);
      client.subscribe("teste/topico");
    } else {
      Serial.print("Falha, rc=");
      Serial.print(client.state());
      Serial.println(" Tentando novamente em 5 segundos");
      delay(5000);
    }
  }
}

void callback(char* topic, byte* message, unsigned int length) {
  Serial.print("Mensagem recebida no tópico: ");
  Serial.print(topic);
  Serial.print(". Mensagem: ");
  String stMessage;
  
  for (int i = 0; i < length; i++) {
    Serial.print((char)message[i]);
    stMessage += (char)message[i];
  }
  Serial.println();

  if (String(topic) == "IFSP/led") {
    Serial.print("Saída alterada para ");
    if(stMessage == "on"){
      Serial.println("ON");
      digitalWrite(ledPin, HIGH);
    }
    else if(stMessage == "off"){
      Serial.println("OFF");
      digitalWrite(ledPin, LOW);
    }
  }
}

void loop() {
  if (!client.connected()) {
    mqttReconnect();
  }
  client.loop();

  int sensorValue = digitalRead(sensorPin); // Lê o estado do sensor

  // Verifica se houve uma mudança no estado do sensor
  if (sensorValue != lastSensorState) {
    lastSensorState = sensorValue;
    
    if (sensorValue == HIGH) {
      Serial.println("Movimento detectado!");
      digitalWrite(ledPin, HIGH); // Liga o LED quando detectar movimento
      client.publish("sensor/movimento", "1"); // Publica "1" no tópico
    } else {
      Serial.println("Sem movimento...");
      digitalWrite(ledPin, LOW); // Desliga o LED quando não detectar movimento
      client.publish("sensor/movimento", "0"); // Publica "0" no tópico
    }
  }

  delay(500); 
}
