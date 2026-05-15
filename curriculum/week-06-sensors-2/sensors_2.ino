#include <DHT.h>

const int LDR_PIN   = A0;
const int DHT_PIN   = 7;
const int BUZZER    = 8;

const int LDR_THRESHOLD = 300; // below this = dark
const int DHT_TYPE      = DHT11;

DHT dht(DHT_PIN, DHT_TYPE);

void setup() {
    pinMode(BUZZER, OUTPUT);
    pinMode(LED,    OUTPUT);
    Serial.begin(9600);
    dht.begin();
    Serial.println("Environmental monitor ready.");
}

void loop() {
    // light reading
    int lightLevel = analogRead(LDR_PIN);
    int brightness = map(lightLevel, 0, 1023, 0, 255);

    if (lightLevel < LDR_THRESHOLD) {
        tone(BUZZER, 1000);
    } else {
        noTone(BUZZER);
    }

    // dht11 reading
    float humidity    = dht.readHumidity();
    float temperature = dht.readTemperature();

    if (isnan(humidity) || isnan(temperature)) {
        Serial.println("DHT11 read failed. Check wiring.");
    } else {
        Serial.print("Light: ");
        Serial.print(lightLevel);
        Serial.print(" / 1023  |  Temp: ");
        Serial.print(temperature);
        Serial.print(" C  |  Humidity: ");
        Serial.print(humidity);
        Serial.println(" %");
    }

    delay(1000);
}