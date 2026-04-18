const int TRIG = 9;
const int ECHO = 10;
const int ALARM = 13;
const int THRESHOLD = 20; // centimetres

long getDistance() {
    digitalWrite(TRIG, LOW);
    delayMicroseconds(2);
    digitalWrite(TRIG, HIGH);
    delayMicroseconds(10);
    digitalWrite(TRIG, LOW);

    long duration = pulseIn(ECHO, HIGH);
    return duration / 58;
}

void setup() {
    pinMode(TRIG,  OUTPUT);
    pinMode(ECHO,  INPUT);
    pinMode(ALARM, OUTPUT);
    Serial.begin(9600);
}

void loop() {
    long distance = getDistance();

    Serial.print("Distance: ");
    Serial.print(distance);
    Serial.println(" cm");

    if (distance < THRESHOLD) {
        digitalWrite(ALARM, HIGH);
    } else {
        digitalWrite(ALARM, LOW);
    }

    delay(100);
}