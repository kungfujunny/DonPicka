
#include <Servo.h> //Arduino servo motor library
#include <AccelStepper.h>

#define dir1 4 // Motor 1 direction, pin 2 doesnt work on MEGA
#define pul1 3 // Motor 1 pulse 
#define dir2 6 
#define pul2 7

//configure the servo motors

AccelStepper stepper1(1, pul1, dir1);
AccelStepper stepper2(1, pul2, dir2);

void setup() {

stepper1.setMaxSpeed(5000);
stepper1.setAcceleration(1000);
stepper2.setMaxSpeed(5000);
stepper2.setAcceleration(1000);
}

void loop() {
  int movement=5000;
  stepper1.move(movement);
  stepper1.runToPosition();
  delay(1000);
  stepper1.move(-movement);
  stepper1.runToPosition();
  delay(1000);

}
/*
void moveJ2(float x){
int a = 100;
int pos = 0;

if (x=0){

pos = 0; 
stepper2.move(pos);
stepper2.runToPosition();

}

else if(x<0){
pos = -200*a;
stepper2.move(pos);
stepper2.runToPosition();

}

else {
pos = 200*a;
stepper2.move(pos);
stepper2.runToPosition();

}

return;

}

void moveJ1(float z){

int a = 100; 
int z_conv = z*200*a;

stepper1.move(z_conv);
stepper1.runToPosition();

return; 

}

void J2Home(float x){
int pos = 0; 
int a = 100; 

  if (x=0){
    pos = 0; 
    stepper2.move(pos);
    stepper2.runToPosition();

  }

  else if(x<0){
    pos = 200*a;
    stepper2.move(pos);
    stepper2.runToPosition();

  }

  else {
    pos = -200*a;
    stepper2.move(pos);
    stepper2.runToPosition();

  }

  return;

}
*/
