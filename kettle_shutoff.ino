#include <DHT.h>
#include <Servo.h>

#define DHT_PIN 12
#define DHT_TYPE DHT11
#define SERVO_PIN 13
#define BUZZER_PIN 11

int temperatureThreshold = 40;
int servoPosition = 90;
bool alertTriggered = false;

DHT dht(DHT_PIN, DHT_TYPE);
Servo kettleServo;

void setup() {
  Serial.begin(9600);
  dht.begin();
  kettleServo.attach(SERVO_PIN);
  pinMode(BUZZER_PIN, OUTPUT);
  digitalWrite(BUZZER_PIN, LOW);
  kettleServo.write(0);
}

void loop() {
  float temperature = dht.readTemperature();

  if (isnan(temperature)) {
    Serial.println("Failed to read from DHT sensor!");
    return;
  }

  Serial.print("Temperature: ");
  Serial.print(temperature);
  Serial.println("°C");

  if (temperature >= temperatureThreshold && !alertTriggered) {
    activateBuzzer();
    turnServo();
    alertTriggered = true;
  }
  
  if (temperature < temperatureThreshold) {
    alertTriggered = false;
  }

  delay(1000);
}

void turnServo() {
  Serial.println("Turning servo to stop kettle.");
  kettleServo.write(servoPosition);
  delay(500);
  kettleServo.write(0);
}

void activateBuzzer() {
  Serial.println("Activating buzzer.");
  digitalWrite(BUZZER_PIN, HIGH);
  delay(700);
  digitalWrite(BUZZER_PIN, LOW);
}
