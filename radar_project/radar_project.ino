#include <Servo.h>

// Define the pins for the ultrasonic sensor
#define TRIG_PIN 9
#define ECHO_PIN 10

// Create a Servo object
Servo servo;

// Variables for the ultrasonic sensor
long duration;
int distance;

// Servo angle
int angle = 0;

void setup() {
  // Initialize the servo motor
  servo.attach(11); // Servo control pin connected to pin 11

  // Set the ultrasonic sensor pins
  pinMode(TRIG_PIN, OUTPUT);
  pinMode(ECHO_PIN, INPUT);

  // Begin serial communication
  Serial.begin(9600);
}

void loop() {
  for (angle = 0; angle <= 180; angle += 2) { // Sweep from 0 to 180 degrees
    scan();
  }
  for (angle = 180; angle >= 0; angle -= 2) { // Sweep back from 180 to 0 degrees
    scan();
  }
}

void scan() {
  servo.write(angle);       // Move the servo to the specified angle
  delay(30);                // Wait for the servo to reach the position

  // Trigger the ultrasonic pulse
  digitalWrite(TRIG_PIN, LOW);
  delayMicroseconds(2);
  digitalWrite(TRIG_PIN, HIGH);
  delayMicroseconds(10);
  digitalWrite(TRIG_PIN, LOW);

  // Read the echo response
  duration = pulseIn(ECHO_PIN, HIGH);

  // Calculate distance (in cm)
  distance = duration * 0.034 / 2;

  // Display angle and distance
  Serial.print("Angle: ");
  Serial.print(angle);
  Serial.print("°, Distance: ");
  if (distance > 0 && distance <= 400) {
    Serial.print(distance);
    Serial.println(" cm");
  } else {
    Serial.println("Out of range");
  }

  delay(50); // Delay to stabilize sensor readings
}
