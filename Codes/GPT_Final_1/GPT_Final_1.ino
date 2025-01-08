// Libraries for ultrasonic sensor
#include <NewPing.h>
#include <AFMotor.h>
#define Max_Speed 200
#define Max_Offset 20 
#define Max_Dis 500
#define Dis_Thres 20
#define TRIGGER_PIN A2
#define ECHO_PIN A3
AF_DCMotor Motor1(1);
AF_DCMotor Motor2(2);

// Ultrasonic sensor pins


// IR sensor pins
#define IR_LEFT_PIN A0
#define IR_RIGHT_PIN A5

// Motor control pins
#define MOTOR_A_EN 5
#define MOTOR_B_EN 6
#define MOTOR_A_IN1 7
#define MOTOR_A_IN2 8
#define MOTOR_B_IN3 9
#define MOTOR_B_IN4 10

// IR sensor threshold values
#define IR_THRESHOLD 500

// Ultrasonic sensor variables
NewPing sonar(TRIGGER_PIN, ECHO_PIN);
int obstacleDistance = 15; // Distance in centimeters to stop the robot when an obstacle is detected

void setup() {
  // Initialize motor control pins as outputs
  /*pinMode(MOTOR_A_EN, OUTPUT);
  pinMode(MOTOR_B_EN, OUTPUT);
  pinMode(MOTOR_A_IN1, OUTPUT);
  pinMode(MOTOR_A_IN2, OUTPUT);
  pinMode(MOTOR_B_IN3, OUTPUT);
  pinMode(MOTOR_B_IN4, OUTPUT);
  
  // Set motor enable pins to HIGH to enable the motors
  digitalWrite(MOTOR_A_EN, HIGH);
  digitalWrite(MOTOR_B_EN, HIGH);*/
  
  // Initialize serial communication
  Serial.begin(9600);
}

void loop() {
  int leftSensorValue = analogRead(IR_LEFT_PIN);
  int rightSensorValue = analogRead(IR_RIGHT_PIN);
  
  // Line following logic
  if (leftSensorValue > IR_THRESHOLD && rightSensorValue > IR_THRESHOLD) {
    // Both sensors see the line, move forward
    moveForward();
  } else if (leftSensorValue > IR_THRESHOLD) {
    // Only left sensor sees the line, turn right
    turnRight();
  } else if (rightSensorValue > IR_THRESHOLD) {
    // Only right sensor sees the line, turn left
    turnLeft();
  } else {
    // Both sensors do not see the line, stop
    stopMotors();
  }
  
  // Obstacle detection
  int distance = sonar.ping_cm();
  if (distance > 0 && distance <= obstacleDistance) {
    // Obstacle detected within the specified distance, stop
    stopMotors();
  }
  
  // Print sensor values and obstacle distance
  Serial.print("Left sensor: ");
  Serial.print(leftSensorValue);
  Serial.print(" | Right sensor: ");
  Serial.print(rightSensorValue);
  Serial.print(" | Obstacle distance: ");
  Serial.print(distance);
  Serial.println(" cm");
  
  delay(100); // Adjust delay as needed
}

// Function to move the robot forward
void moveForward() {
  for (int Speed=0;Speed<=Max_Speed;Speed++)
  {
    Motor1.setSpeed(Speed);
    Motor2.setSpeed(Speed);
    Motor1.run(FORWARD);
    Motor2.run(FORWARD);  
  }
}

// Function to turn the robot left
void turnLeft() {
  Motor1.setSpeed(255);
  Motor2.setSpeed(0);
  Motor1.run(FORWARD);
  Motor2.run(RELEASE);
  delay(220);
}

// Function to turn the robot right
void turnRight() {
  Motor1.setSpeed(0);
  Motor2.setSpeed(255);
  Motor1.run(RELEASE);
  Motor2.run(FORWARD);
  delay(220);
}

// Function to stop the motors
void stopMotors() {
  Motor1.setSpeed(0);
  Motor2.setSpeed(0);
  Motor1.run(RELEASE);
  Motor2.run(RELEASE);
}
