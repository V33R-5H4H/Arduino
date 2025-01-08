#include <NewPing.h>
#include <Servo.h>

// Ultrasonic sensor pins
#define TRIGGER_PIN 9
#define ECHO_PIN 10
#define MAX_DISTANCE 200 // Maximum distance to detect obstacles in centimeters

// Servo motor pin
#define SERVO_PIN 5

// Motor controller pins
#define MOTOR_A_SPEED_PIN 3
#define MOTOR_A_DIRECTION_PIN 4
#define MOTOR_B_SPEED_PIN 6
#define MOTOR_B_DIRECTION_PIN 7

// Servo motor settings
#define SERVO_MIN_ANGLE 45 // Minimum angle for the servo motor
#define SERVO_MAX_ANGLE 135 // Maximum angle for the servo motor

Servo servo; // Create servo object
NewPing sonar(TRIGGER_PIN, ECHO_PIN, MAX_DISTANCE); // Create NewPing object for the ultrasonic sensor

void setup() {
  // Initialize servo and motor pins
  servo.attach(SERVO_PIN);
  pinMode(MOTOR_A_SPEED_PIN, OUTPUT);
  pinMode(MOTOR_A_DIRECTION_PIN, OUTPUT);
  pinMode(MOTOR_B_SPEED_PIN, OUTPUT);
  pinMode(MOTOR_B_DIRECTION_PIN, OUTPUT);
  
  // Start with the servo in the middle position
  servo.write((SERVO_MAX_ANGLE + SERVO_MIN_ANGLE) / 2);
  delay(500);
}

void loop() {
  // Scan the surroundings using the ultrasonic sensor
  int distance = sonar.ping_cm();
  
  // Check if an obstacle is within the avoidance range
  if (distance > 0 && distance < 30) {
    // Obstacle detected, perform avoidance maneuver
    
    // Stop both motors
    analogWrite(MOTOR_A_SPEED_PIN, 0);
    analogWrite(MOTOR_B_SPEED_PIN, 0);
    
    // Move the servo motor to the leftmost position
    servo.write(SERVO_MIN_ANGLE);
    delay(500);
    
    // Reverse the robot
    digitalWrite(MOTOR_A_DIRECTION_PIN, HIGH);
    digitalWrite(MOTOR_B_DIRECTION_PIN, HIGH);
    analogWrite(MOTOR_A_SPEED_PIN, 150);
    analogWrite(MOTOR_B_SPEED_PIN, 150);
    delay(1000);
    
    // Turn right
    digitalWrite(MOTOR_A_DIRECTION_PIN, LOW);
    digitalWrite(MOTOR_B_DIRECTION_PIN, HIGH);
    analogWrite(MOTOR_A_SPEED_PIN, 150);
    analogWrite(MOTOR_B_SPEED_PIN, 150);
    delay(1000);
    
    // Move the servo motor back to the middle position
    servo.write((SERVO_MAX_ANGLE + SERVO_MIN_ANGLE) / 2);
    delay(500);
    
    // Resume forward motion
    digitalWrite(MOTOR_A_DIRECTION_PIN, HIGH);
    digitalWrite(MOTOR_B_DIRECTION_PIN, HIGH);
    analogWrite(MOTOR_A_SPEED_PIN, 150);
    analogWrite(MOTOR_B_SPEED_PIN, 150);
  }
  
  // If no obstacle is detected, continue moving forward
  else {
    digitalWrite(MOTOR_A_DIRECTION_PIN, HIGH);
    digitalWrite(MOTOR_B_DIRECTION_PIN, HIGH);
    analogWrite(MOTOR_A_SPEED_PIN, 150);
    analogWrite(MOTOR_B_SPEED_PIN, 150);
  }
}
