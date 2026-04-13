const int potPin = A0;
const int ledPin = 10;

int potValue = 0;
int brightness = 0;

void setup() {
    pinMode(ledPin, OUTPUT);
}

void loop() {
    potValue = analogRead(potPin);
    brightness = map(potValue, 0, 1023, 0, 255);
    analogWrite(ledPin, brightness);
    delay(10);
}