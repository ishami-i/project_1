// Smart Parking System

const int buttonPin = 6;
const int pingPin   = 7;
const int redLed    = 8;
const int greenLed  = 9;
const int buzzer    = 10;

const float thresholdMeters = 2.0;   // car counts as present closer than this (meters)

bool spotTaken = false;              // stored state, flips on each button press
bool lastButtonState = HIGH;         // HIGH = not pressed (INPUT_PULLUP)
unsigned long lastToggleTime = 0;

void checkButton() {
  bool state = digitalRead(buttonPin);

  // Button just went from released to pressed
  if (lastButtonState == HIGH && state == LOW) {
    if (millis() - lastToggleTime > 200) {   // debounce
      spotTaken = !spotTaken;
      lastToggleTime = millis();
    }
  }
  lastButtonState = state;
}

void setup() {
  pinMode(buttonPin, INPUT_PULLUP);
  pinMode(redLed, OUTPUT);
  pinMode(greenLed, OUTPUT);
  pinMode(buzzer, OUTPUT);
  Serial.begin(9600);
}

void loop() {
  long duration;
  float meters;

  // Trigger the PING))) sensor
  pinMode(pingPin, OUTPUT);
  digitalWrite(pingPin, LOW);
  delayMicroseconds(2);
  digitalWrite(pingPin, HIGH);
  delayMicroseconds(5);
  digitalWrite(pingPin, LOW);

  // Read the echo (30 ms timeout so it never blocks)
  pinMode(pingPin, INPUT);
  duration = pulseIn(pingPin, HIGH, 30000);

  if (duration == 0) {
    meters = 99.0;                              // no echo = nothing nearby
  } else {
    meters = (duration / 29.0 / 2.0) / 100.0;   // microseconds -> cm -> meters
  }

  checkButton();
  bool carNear = (meters < thresholdMeters);
  
  // Track buzzer state for the Serial Monitor printout
  bool buzzerActive = false;

  if (carNear && spotTaken) {
    // Car arrives, spot taken: red + buzzer ON
    digitalWrite(redLed, HIGH);
    digitalWrite(greenLed, LOW);
    tone(buzzer, 1000);
    buzzerActive = true;     // Record that the buzzer is sounding
  } else if (carNear && !spotTaken) {
    // Car arrives, spot free: green + buzzer OFF
    digitalWrite(redLed, LOW);
    digitalWrite(greenLed, HIGH);
    noTone(buzzer);
    buzzerActive = false;    // Record that the buzzer is silent
  } else {
    // No car: everything off
    digitalWrite(redLed, LOW);
    digitalWrite(greenLed, LOW);
    noTone(buzzer);
    buzzerActive = false;    // Record that the buzzer is silent
  }

  // Original Serial print with the added Buzzer status column
  Serial.print("Distance: ");
  Serial.print(meters, 2);
  Serial.print(" m | Spot: ");
  Serial.print(spotTaken ? "TAKEN" : "FREE");
  Serial.print(" | Buzzer: ");
  Serial.println(buzzerActive ? "ON" : "OFF");

  // Wait 100 ms but keep checking the button so quick presses aren't missed
  for (int i = 0; i < 20; i++) {
    checkButton();
    delay(5);
  }
}
