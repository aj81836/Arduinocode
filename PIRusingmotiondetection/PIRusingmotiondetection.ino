// Pin Definitions
const int pirPin = 2;     // PIR sensor input pin
const int buzzerPin = 8;  // Buzzer output pin
const int ledPin = 13;    // LED indicator pin (optional)

void setup() {
  pinMode(pirPin, INPUT);        // PIR sensor as input
  pinMode(buzzerPin, OUTPUT);    // Buzzer as output
  pinMode(ledPin, OUTPUT);       // LED as output (optional)
  
  Serial.begin(9600);            // Initialize serial communication
  Serial.println("PIR Sensor Alarm System Initialized");
}

void loop() {
  int motionState = digitalRead(pirPin); // Read PIR sensor output

  if (motionState == HIGH) { // Motion detected
    digitalWrite(buzzerPin, HIGH); // Activate buzzer
    digitalWrite(ledPin, HIGH);    // Turn on LED (optional)
    Serial.println("Motion Detected!");
    delay(200); // Small delay to stabilize the reading
  } else {
    digitalWrite(buzzerPin, LOW); // Deactivate buzzer
    digitalWrite(ledPin, LOW);    // Turn off LED (optional)
    delay(200); // Small delay to stabilize the reading
  }
}
