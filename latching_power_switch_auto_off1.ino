const int buttonPin = 3;       // Button input
const int pirPin = 2;          // PIR motion sensor input
const int ledPin = 4;          // Main LED output
const int keepAlivePin = 5;    // Control transistor (used as normal output in simulation)
const int offIndicatorPin = 6; // Shutdown indicator LED

bool ledState = false;
unsigned long lastMotionTime = 0;
const unsigned long timeout = 5000;
bool lastButtonState = HIGH;

void setup() {
  pinMode(buttonPin, INPUT_PULLUP);
  pinMode(pirPin, INPUT);
  pinMode(ledPin, OUTPUT);
  pinMode(keepAlivePin, OUTPUT);
  pinMode(offIndicatorPin, OUTPUT);

  digitalWrite(ledPin, HIGH);          // LED off initially
  digitalWrite(keepAlivePin, HIGH);
  digitalWrite(offIndicatorPin, LOW);  // Shutdown indicator off
  Serial.begin(9600);
}

void loop() {
  bool currentButtonState = digitalRead(buttonPin);

  if (lastButtonState == HIGH && currentButtonState == LOW) {
    delay(50);
    if (digitalRead(buttonPin) == LOW) {
      if (!ledState) {
        ledState = true;
        digitalWrite(keepAlivePin, LOW);
        digitalWrite(ledPin, LOW);
        digitalWrite(offIndicatorPin, LOW);
        lastMotionTime = millis();
        Serial.println("✅ System ON");
      }
    }
  }
  lastButtonState = currentButtonState;

  if (digitalRead(pirPin) == HIGH) {
    ledState = true;
    digitalWrite(ledPin, LOW);
    digitalWrite(offIndicatorPin, LOW);
    lastMotionTime = millis();
    Serial.println("🔄 Motion detected");
  }

  if (ledState && (millis() - lastMotionTime > timeout)) {
    ledState = false;
    digitalWrite(ledPin, HIGH);
    digitalWrite(keepAlivePin, HIGH);
    digitalWrite(offIndicatorPin, HIGH);
    Serial.println("🛑 Auto shutdown triggered (simulation indicator only)");
  }
}