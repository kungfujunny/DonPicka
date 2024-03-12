#include <Stepper.h>
#define STEPS 200 // steps per rev for nema 17
#define motor1Pin1 2 // Motor coil pin 1
#define motor1Pin2 3 // Motor coil pin 2
#define motor2Pin1 4
#define motor2Pin2 5
#define motor3Pin1 6
#define motor3Pin2 7
#define homePositionC 0 // Home position on the rail
#define homePositionA 0 // Home position for the arm
#define railLength 100000

void setup() {
  Stepper stepper(STEPS, motorPin1, motorPin2);

  stepper.setSpeed(100); // Set the speed of the stepper motor
  
}

void moveToPosition(int targetZ) {

  int stepsToMove = (targetZ - stepper.currentPosition()) * STEPS / railLength;
  stepper.step(stepsToMove);

}

void returnHome() {
  moveToPosition(homePositionC);
}

void moveToX{



}



}

void loop() {

  int targetZ = 100; // Example target x-coordinate
  moveToPosition(targetZ);
  delay(1000); // Delay for stability or do other operations

  returnHome();
}
