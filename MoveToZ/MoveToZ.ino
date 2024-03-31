#include <Servo.h> //Arduino servo motor library
#include <AccelStepper.h>

#define dir1 4 // Motor 1 direction, pin 2 doesnt work on MEGA
#define pul1 3 // Motor 1 pulse 
#define dir2 6 
#define pul2 7

//configure the servo motors
Servo servo1;
Servo servo2;
AccelStepper stepper1(1, pul1, dir1);
AccelStepper stepper2(1, pul2, dir2);

bool xLocationStatus = false;
bool yLocationStatus = false;
bool zLocationStatus = false;

const float pi = 3.1415926;
const float L1 = 13; // Length between the first motor and the second motor (in cm)
const float L2 = 11; // Length between the second motor and the end of arm (in cm)
float x = -3; 
float y = 5; 
float z = 6;   
float q1; // Angle of the first motor (in radian)
float q1_deg; // Angle of the first motor (in degree)
float q2; // Angle of the second motor (in radian)
float q2_deg; // Angle of the second motor (in degree)
float q; // Sum of in radian (q1+q2), it called theta
float q_deg; // Sum of in degree (q1_deg + q2_deg)
float x_sq ; // X square
float y_sq ; // // Y square
float L1_sq ; // L1 square
float L2_sq ; // L2 square
const int btn1 = 6;
const int btn2 = 7;
int btn1value = LOW; // For forward kinematics
int btn2value = LOW; // For inverse kinematics


void setup() {
  
servo1.attach(8);
servo2.attach(9);

stepper1.setMaxSpeed(500000);
stepper1.setAcceleration(100000);
stepper2.setMaxSpeed(500000);
stepper2.setAcceleration(100000);


Serial.begin(9600); 

  Serial.print("Theta1: ");
  Serial.print(q1_deg); 
  Serial.print(" degrees, Theta2: ");
  Serial.print(q2_deg); // 
  Serial.println(" degrees");
  Serial.print("Theta: ");
  Serial.print(q_deg); // 
  Serial.println(" degrees");
  delay(1000);

}

void loop() {
  
  q = atan2(y,x);
  
  x_sq = pow(x,2); 
  y_sq = pow(y,2); 
  L1_sq = pow(L1,2); 
  L2_sq = pow(L2,2); 
  
  q1 = acos((x_sq + y_sq - (L1_sq + L2_sq))/(2*L1*L2)); 
  q2 = q - q1 ; 
  
  q1_deg = q1*180/pi ; // convert the angle from radian to degree
  q2_deg = q2*180/pi; // convert the angle from radian to degree
  q_deg = q*180/pi; 
  //servo1.write(120-q1_deg); 
  //servo2.write(80-q2_deg); 
  servo1.write(120); 
  servo2.write(80); 



  moveJ1(z);
  moveJ2(x);
  J2Home(x); 


}

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
