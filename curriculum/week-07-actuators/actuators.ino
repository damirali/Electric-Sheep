#include <Servo.h>

const int POT_PIN   = A0;
const int SERVO_PIN = 6;

Servo myServo;

void setup() {
    myServo.attach(SERVO_PIN);
    Serial.begin(9600);
}

void loop() {
    int raw    = analogRead(POT_PIN);
    int angle  = map(raw, 0, 1023, 0, 180);
    myServo.write(angle);

    Serial.print("Raw: ");
    Serial.print(raw);
    Serial.print("  Angle: ");
    Serial.println(angle);

    delay(15);
}