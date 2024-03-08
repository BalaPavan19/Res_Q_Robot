#include <Servo.h>

// Define servo pins
const int basePin = 9;
const int shoulderPin = 10;
const int elbowPin = 11;
const int gripperPin = 12;

// Create servo objects
Servo baseServo;
Servo shoulderServo;
Servo elbowServo;
Servo gripperServo;

// Define servo angles for each position
int baseAngle = 90;
int shoulderAngle = 90;
int elbowAngle = 90;
int gripperAngle = 0; // 0 for open, 180 for closed

void setup() {
  // Attach servos to pins
  baseServo.attach(basePin);
  shoulderServo.attach(shoulderPin);
  elbowServo.attach(elbowPin);
  gripperServo.attach(gripperPin);

  // Initialize servos to their initial positions
  baseServo.write(baseAngle);
  shoulderServo.write(shoulderAngle);
  elbowServo.write(elbowAngle);
  gripperServo.write(gripperAngle);
}

void loop() {
  // Move the arm to a specific position
  moveArm(90, 90, 90, 0); // Example position, adjust as needed
  delay(1000); // Wait for the arm to reach the position

  // Open gripper
  moveGripper(180);
  delay(1000); // Wait for the gripper to open

  // Close gripper
  moveGripper(0);
  delay(1000); // Wait for the gripper to close
}

void moveArm(int base, int shoulder, int elbow, int gripper) {
  baseServo.write(base);
  shoulderServo.write(shoulder);
  elbowServo.write(elbow);
  gripperServo.write(gripper);
}

void moveGripper(int angle) {
  gripperServo.write(angle);
}
