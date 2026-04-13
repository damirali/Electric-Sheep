const int LED = 13;
int dotLength = 200;

void dot() {
    digitalWrite(LED, HIGH); delay(dotLength);
    digitalWrite(LED, LOW);  delay(dotLength);
}

void dash() {
    digitalWrite(LED, HIGH); delay(dotLength * 3);
    digitalWrite(LED, LOW);  delay(dotLength);
}

void letterGap() { delay(dotLength * 2); }
void wordGap()   { delay(dotLength * 4); }

void flashLetter(char c) {
    switch (c) {
        case 'a': dot(); dash(); break;
        case 'b': dash(); dot(); dot(); dot(); break;
        case 'c': dash(); dot(); dash(); dot(); break;
        case 'd': dash(); dot(); dot(); break;
        case 'e': dot(); break;
        case 'f': dot(); dot(); dash(); dot(); break;
        case 'g': dash(); dash(); dot(); break;
        case 'h': dot(); dot(); dot(); dot(); break;
        case 'i': dot(); dot(); break;
        case 'j': dot(); dash(); dash(); dash(); break;
        case 'k': dash(); dot(); dash(); break;
        case 'l': dot(); dash(); dot(); dot(); break;
        case 'm': dash(); dash(); break;
        case 'n': dash(); dot(); break;
        case 'o': dash(); dash(); dash(); break;
        case 'p': dot(); dash(); dash(); dot(); break;
        case 'q': dash(); dash(); dot(); dash(); break;
        case 'r': dot(); dash(); dot(); break;
        case 's': dot(); dot(); dot(); break;
        case 't': dash(); break;
        case 'u': dot(); dot(); dash(); break;
        case 'v': dot(); dot(); dot(); dash(); break;
        case 'w': dot(); dash(); dash(); break;
        case 'x': dash(); dot(); dot(); dash(); break;
        case 'y': dash(); dot(); dash(); dash(); break;
        case 'z': dash(); dash(); dot(); dot(); break;
        case ' ': wordGap(); break;
    }
}

void flashWord(String word) {
    word.toLowerCase();
    for (int i = 0; i < word.length(); i++) {
        flashLetter(word[i]);
        if (word[i] != ' ') letterGap();
    }
} 

void setup() {
    pinMode(LED, OUTPUT);
    Serial.begin(9600);
    Serial.println("Type a word and press Enter:");
}

void loop() {
    if (Serial.available()) {
        String input = Serial.readStringUntil('\n');
        input.trim();
        Serial.print("Flashing: ");
        Serial.println(input);
        flashWord(input);
        delay(1000);
        Serial.println("Type another word:");
    }
}