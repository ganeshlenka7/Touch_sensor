int touchPin = 2;     // Touch sensor OUT pin
int ledPin = 13;      // Onboard LED
int ledState = LOW;   // Track LED state
int lastTouch = HIGH; // Track last touch (TTP223 gives LOW when touched in "active-low" mode)

void setup() {
  pinMode(touchPin, INPUT);
  pinMode(ledPin, OUTPUT);
  Serial.begin(9600);
  Serial.println("Touch Sensor LED Toggle Ready...");
}

void loop() {
  int touchValue = digitalRead(touchPin);

  // Detect a new touch (button press style)
  if (touchValue == LOW && lastTouch == HIGH) {
    ledState = !ledState; // Toggle LED state
    digitalWrite(ledPin, ledState);

    if (ledState == HIGH) {
      Serial.println("LED ON");
    } else {
      Serial.println("LED OFF");
    }

    delay(300); // Debounce delay
  }

  lastTouch = touchValue;
}
