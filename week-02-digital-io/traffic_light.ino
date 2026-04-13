const int RED = 2;
const int YELLOW = 3;
const int GREEN = 4;
const int BUTTON = 5;

void setup() {
    pinMode(RED, OUTPUT);
    pinMode(YELLOW, OUTPUT);
    pinMode(GREEN, OUTPUT);
    pinMode(BUTTON, INPUT);

    digitalWrite(RED, HIGH); // idle state: red on
}

void loop() {
    if (digitalRead(BUTTON) == LOW) {
        delay(50);
        if (digitalRead(BUTTON) == LOW) {
            while (digitalRead(BUTTON) == LOW); // wait for release

            // Red
            digitalWrite(RED, HIGH);
            digitalWrite(YELLOW, LOW);
            digitalWrite(GREEN, LOW);
            delay(5000);

            // Red + Yellow (prepare to go)
            digitalWrite(RED, HIGH);
            digitalWrite(YELLOW, HIGH);
            digitalWrite(GREEN, LOW);
            delay(2000);

            // Green
            digitalWrite(RED, LOW);
            digitalWrite(YELLOW, LOW);
            digitalWrite(GREEN, HIGH);
            delay(5000);

            // Yellow (prepare to stop)
            digitalWrite(RED, LOW);
            digitalWrite(YELLOW, HIGH);
            digitalWrite(GREEN, LOW);
            delay(2000);

            // Back to Red
            digitalWrite(RED, HIGH);
            digitalWrite(YELLOW, LOW);
            digitalWrite(GREEN, LOW);
        }
    }
}