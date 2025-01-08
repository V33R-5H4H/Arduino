#include <AFMotor.h>
#include <NewPing.h>
#include <Servo.h>

// Ultrasonic sensor pins
#define TRIGGER_PIN A4
#define ECHO_PIN A5

// Servo motor pin
#define SERVO_PIN 10

// Distance threshold for obstacle detection
#define DISTANCE_THRESHOLD 20

AF_DCMotor motor1(1); // Motor 1 object
AF_DCMotor motor2(3); // Motor 2 object

Servo servo; // Servo motor object

NewPing sonar(TRIGGER_PIN, ECHO_PIN);

void setup() {
  // Attach servo motor
  servo.attach(SERVO_PIN);
  servo.write(90); // Set the servo motor to the center position
}

void loop() {
  // Check left and right for obstacles
  bool obstacleLeft = checkObstacle(-45, -15);
  bool obstacleRight = checkObstacle(15, 45);

  if (obstacleLeft && obstacleRight) {
    // Obstacles on both sides, stop all motors
    stopMotors();
  } else if (obstacleLeft) {
    // Obstacle on the left, turn right
    turnRight();
  } else if (obstacleRight) {
    // Obstacle on the right, turn left
    turnLeft();
  } else {
    // No obstacles, move forward
    moveForward();
  }
}

bool checkObstacle(int startAngle, int endAngle) {
  bool obstacleDetected = false;

  // Rotate the servo motor and check for obstacles
  for (int angle = startAngle; angle <= endAngle; angle += 5) {
    servo.write(angle);
    delay(100);

    int distance = sonar.ping_cm();
    if (distance==0)
    {
      distance=250;
    }
    
    if (distance <= DISTANCE_THRESHOLD) {
      obstacleDetected = true;
      break;
    }
  }

  // Reset the servo motor to the center position
  servo.write(90);

  return obstacleDetected;
}

void moveForward() {
  // Set motor speed and direction for forward motion
  motor1.setSpeed(255);
  motor1.run(FORWARD);
  motor2.setSpeed(255);
  motor2.run(FORWARD);
}

void stopMotors() {
  // Stop all motors
  motor1.setSpeed(0);
  motor1.run(RELEASE);
  motor2.setSpeed(0);
  motor2.run(RELEASE);
}

void turnRight() {
  // Set motor speed and direction for right turn
  motor1.setSpeed(255);
  motor1.run(FORWARD);
  motor2.setSpeed(255);
  motor2.run(BACKWARD);
}

void turnLeft() {
  // Set motor speed and direction for left turn
  motor1.setSpeed(255);
  motor1.run(BACKWARD);
  motor2.setSpeed(255);
  motor2.run(FORWARD);
}
