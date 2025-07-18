const int pirPin = 2;      
const int ldrPin = A0;     
const int ledPin = 4;

bool ledState = false;
unsigned long ledOnTime = 0;
const unsigned long ledDuration = 5000; // شغل الليد لمدة 5 ثوانٍ

void setup() {
  pinMode(pirPin, INPUT);
  pinMode(ledPin, OUTPUT);
  Serial.begin(9600);
}

void loop() {
  int motion = digitalRead(pirPin);
  int light = analogRead(ldrPin);

  Serial.print("Motion: ");
  Serial.print(motion);
  Serial.print(" | Light: ");
  Serial.print(light);
  Serial.print(" | LED: ");
  Serial.println(ledState ? "ON" : "OFF");

  // إذا ما كان الليد شغال، نتحقق من الضوء
  if (!ledState && motion == HIGH && light <= 900) {
    digitalWrite(ledPin, HIGH);
    ledState = true;
    ledOnTime = millis();  // نسجل وقت تشغيل الليد
  }

  // إذا الليد شغال، ننتظر مدة ثم نطفيه
  if (ledState && millis() - ledOnTime >= ledDuration) {
    digitalWrite(ledPin, LOW);
    ledState = false;
  }

  delay(100);
}

