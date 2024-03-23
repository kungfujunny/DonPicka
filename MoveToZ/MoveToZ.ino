#include <AccelStepper.h>
#define STEPS 200 // steps per rev for nema 17
#define dir1 8 // Motor coil pin 1
#define pul1 3 // Motor coil pin 2
#define dir2 4
#define pul2 5
#define dir3 6
#define pul3 7
#define homePositionC 0 // Home position on the rail
#define homePositionA 0 // Home position for the arm
#define railLength 100000

  AccelStepper stepper1(1, pul1, dir1);
  //AccelStepper stepper2(1, pul2, dir2);
 // AccelStepper stepper3(1, pul3, dir3);

void setup() {

  stepper1.setMaxSpeed(1000);
  stepper1.setAcceleration(1000);
//  stepper2.setMaxSpeed(200);
//  stepper2.setAcceleration(100);
//  stepper3.setMaxSpeed(200);
//  stepper3.setAcceleration(100);
  
}

// void moveToPosition(int targetZ) {

//int stepsToMove = (targetZ - stepper.currentPosition()) * STEPS / railLength;
  //stepper.step(stepsToMove);

//}

//void returnHome() {
 // moveToPosition(homePositionC);
//}


void loop() {

    // Move to position 0
  stepper1.move(1000);
  // stepper1.setSpeed(1000);
  stepper1.runToPosition();
 // stepper1.runToNewPosition(-1000);
  delay(1000);

  // Move to position 20000
  stepper1.move(-1000);
  // stepper1.setSpeed(-1000);
  stepper1.runToPosition();
 // stepper1.runToNewPosition(1000);
  delay(1000);

  // Move back to position 100
  //stepper1.moveTo(100);
  //stepper1.runToPosition();
 // delay(1000);

//   returnHome();
}
