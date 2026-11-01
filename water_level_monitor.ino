// ============================================================
// Arduino-Based Smart Water Level Monitoring System
// Board: Arduino UNO
// Sensor: HC-SR04 Ultrasonic Sensor
// Indicators: 4 LEDs + Active Buzzer
// ============================================================

// HC-SR04
const int TRIG_PIN = 7;
const int ECHO_PIN = 6;

// LEDs
const int LED1 = 2;  // 10%
const int LED2 = 3;  // 40%
const int LED3 = 4;  // 80%
const int LED4 = 5;  // 100% (red LED)

// Active buzzer
const int BUZZER_PIN = 8;

// Calibration distances (cm)
const float EMPTY_DISTANCE = 11.4;  // 0%
const float FULL_DISTANCE  = 5.88;  // 100%

const unsigned long READ_INTERVAL_MS = 1000;
unsigned long lastReadTime = 0;

float getDistanceCm() {
  digitalWrite(TRIG_PIN, LOW);
  delayMicroseconds(2);

  digitalWrite(TRIG_PIN, HIGH);
  delayMicroseconds(10);
  digitalWrite(TRIG_PIN, LOW);

  // Timeout avoids waiting indefinitely for an echo.
  unsigned long duration = pulseIn(ECHO_PIN, HIGH, 30000);

  // No echo: use the calibrated empty-tank distance.
  if (duration == 0) {
    return EMPTY_DISTANCE;
  }

  return (duration * 0.0343f) / 2.0f;
}

int calculateWaterLevelPercent(float distanceCm) {
  float percentage =
    ((EMPTY_DISTANCE - distanceCm) /
     (EMPTY_DISTANCE - FULL_DISTANCE)) * 100.0f;

  percentage = constrain(percentage, 0.0f, 100.0f);
  return (int)(percentage + 0.5f); // Rounded to nearest integer
}

void updateIndicators(int waterLevel) {
  digitalWrite(LED1, waterLevel >= 10 ? HIGH : LOW);
  digitalWrite(LED2, waterLevel >= 40 ? HIGH : LOW);
  digitalWrite(LED3, waterLevel >= 80 ? HIGH : LOW);

  if (waterLevel >= 100) {
    digitalWrite(LED4, HIGH);
    digitalWrite(BUZZER_PIN, HIGH);  // Continuous alarm
  } else {
    digitalWrite(LED4, LOW);
    digitalWrite(BUZZER_PIN, LOW);
  }
}

void setup() {
  Serial.begin(9600);

  pinMode(TRIG_PIN, OUTPUT);
  pinMode(ECHO_PIN, INPUT);

  pinMode(LED1, OUTPUT);
  pinMode(LED2, OUTPUT);
  pinMode(LED3, OUTPUT);
  pinMode(LED4, OUTPUT);

  pinMode(BUZZER_PIN, OUTPUT);

  digitalWrite(TRIG_PIN, LOW);
  digitalWrite(BUZZER_PIN, LOW);

  Serial.println(F("======================================"));
  Serial.println(F(" SMART WATER LEVEL MONITORING SYSTEM"));
  Serial.println(F("======================================"));
  Serial.println(F("Serial Monitor: 9600 baud"));
}

void loop() {
  unsigned long now = millis();

  if (now - lastReadTime >= READ_INTERVAL_MS) {
    lastReadTime = now;

    float distanceCm = getDistanceCm();
    int waterLevel = calculateWaterLevelPercent(distanceCm);

    updateIndicators(waterLevel);

    Serial.print(F("Distance: "));
    Serial.print(distanceCm, 1);
    Serial.print(F(" cm | Water Level: "));
    Serial.print(waterLevel);
    Serial.println(F("%"));
  }
}
