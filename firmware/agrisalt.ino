/*
 AgriSalt starter firmware — not calibrated or field validated.
 Moisture analog output: A0; EC module analog output: A1.
 Green LED: D3, Yellow: D4, Red: D5; use a 220–330 ohm resistor per LED.
 Verify the exact EC module's output voltage/range before connecting.
 Thresholds below are raw ADC placeholders, NOT universal soil EC limits.
*/
const byte MOISTURE_PIN = A0;
const byte EC_PIN = A1;
const byte GREEN_LED = 3, YELLOW_LED = 4, RED_LED = 5;

// DEMO PLACEHOLDERS only. Replace after calibration and validation.
const int EC_CAUTION_RAW = 350;
const int EC_ALERT_RAW = 650;
unsigned long lastSample = 0;

void setup() {
  pinMode(GREEN_LED, OUTPUT);
  pinMode(YELLOW_LED, OUTPUT);
  pinMode(RED_LED, OUTPUT);
  Serial.begin(9600);
  allLedsOff();
  Serial.println(F("AgriSalt starter: raw ADC only; calibrate before interpreting."));
}

void loop() {
  if (millis() - lastSample < 1000) return;
  lastSample = millis();
  int moistureRaw = analogRead(MOISTURE_PIN);
  int ecRaw = analogRead(EC_PIN);
  Serial.print(F("moisture_raw=")); Serial.print(moistureRaw);
  Serial.print(F(", ec_raw=")); Serial.println(ecRaw);

  // Confirm the direction and meaning of EC output for your exact module.
  if (ecRaw < EC_CAUTION_RAW) showGreen();
  else if (ecRaw < EC_ALERT_RAW) showYellow();
  else showRed();
}
void allLedsOff() {
  digitalWrite(GREEN_LED, LOW); digitalWrite(YELLOW_LED, LOW); digitalWrite(RED_LED, LOW);
}
void showGreen() { allLedsOff(); digitalWrite(GREEN_LED, HIGH); }
void showYellow() { allLedsOff(); digitalWrite(YELLOW_LED, HIGH); }
void showRed() { allLedsOff(); digitalWrite(RED_LED, HIGH); }
