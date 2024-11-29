// Define pins
int pirPin = 2;     // PIR sensor output pin
int ledPin = 13;    // LED pin

void setup() {
  pinMode(pirPin, INPUT);  // Set PIR sensor pin as input
  pinMode(ledPin, OUTPUT); // Set LED pin as output

  // Initialize serial communication (optional for debugging)
  Serial.begin(9600);
  Serial.println("PIR Sensor Motion Detection Initialized");
}

void loop() {
  int motionDetected = digitalRead(pirPin); // Read the PIR sensor
  
  if (motionDetected == HIGH) { // Motion detected
    Serial.println("Motion Detected!");
    digitalWrite(ledPin, HIGH);  // Turn on the LED
    delay(100);                 // Keep the LED on for 0.5 seconds
  } else {
    digitalWrite(ledPin, LOW);   // Turn off the LED
  }

  delay(100); // Small delay to avoid rapid changes
}
