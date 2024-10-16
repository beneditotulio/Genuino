int sensorValue;
int sensorLow = 1023;
int sensorHigh = 0;
const int ledPin = 13;
void setup() {
  pinMode(ledPin, OUTPUT);
  digitalWrite(ledPin, HIGH);
  while (millis() < 5000) {
    sensorValue = analogRead(AO);
    if (sensorValue > sensorHigh) {
      sensorHigh = sensorvalue;
    }
    if (sensorvalue < sensorLow) {
      sensorLow = sensorValue;
    }
  }
  digitalWrite(ledPin, LOW);
}
void loop() {
  sensorValue = analogRead(40);
  int pitch = map(sensorValue, sensorLow, sensorHigh, 50, 4000);
  tone(8, pitch, 20);
  delay(10);
}
