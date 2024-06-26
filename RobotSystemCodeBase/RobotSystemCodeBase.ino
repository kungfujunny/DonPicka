#include <Servo.h>
#include <AccelStepper.h>

Servo servo1;
Servo servo2;
Servo servo3;

#define dir1 4 // Motor 1 direction, pin 2 doesnt work on MEGA
#define pul1 3 // Motor 1 pulse 
#define dir2 6 
#define pul2 7

AccelStepper stepper1(1, pul1, dir1);
AccelStepper stepper2(1, pul2, dir2);

int homeX = 0;
int homeY = 0;
int homeZ = 0;

void setup() {

  servo1.attach(8);//left
  servo2.attach(9);
  servo3.attach(10);//second joint

  
  stepper1.setMaxSpeed(10000);
  stepper1.setAcceleration(1000);
  stepper2.setMaxSpeed(10000);
  stepper2.setAcceleration(103000);

  Serial.begin(9600);
  
}

//400 steps equals 1 cm
void loop() {
  
  int alpha = 0;
  servo1.write(alpha);
  int angleServo3 = 2*alpha;
  servo3.write(angleServo3);
  int angle2 = 180-alpha;
  servo2.write(angle2);

  //
  int xPosition, yPosition, zPosition;
  bool positionUpdate = getPositions(xPosition, yPosition, zPosition);
  if(!positionUpdate) return;

  stepper1.move(-xPosition*400);
  stepper1.runToPosition();
  
  int hyp = sqrt(sq(yPosition)+sq(zPosition));
  //Serial.println(yPosition);
  
  if(hyp>=17 && hyp <=40){
    int deltaLength = hyp-17;
    int targetAngle = map(deltaLength,0,23,0,90);
    
    if(yPosition<=0){
      int angle = atan(abs(yPosition)/zPosition)*180/3.14;
      int target = map(angle,0,90,0,16);
      int movement=4000;
      int iteration = target;
  
          for(int i=0;i<=iteration;i++){
            stepper2.move(-movement);
            stepper2.runToPosition();
            }
            for(int angleServo = 0; angleServo<=targetAngle;angleServo++){
              servo1.write(angleServo);
              int angleServo3 = 2*angleServo;
              servo3.write(angleServo3);
              int angle2 = 180-angleServo;
              servo2.write(angle2);
              delay(15);
              }
              delay(5000);
              
            for(int angleServo = targetAngle; angleServo>=0;angleServo--){
              servo1.write(angleServo);
              int angleServo3 = 2*angleServo;
              servo3.write(angleServo3);
              int angle2 = 180-angleServo;
              servo2.write(angle2);
              delay(15);
              }
              
            for(int i=0;i<=iteration;i++){
                stepper2.move(movement);
                stepper2.runToPosition();
                //delay(2000);
                }
                }
     else{
                    int angle = atan(abs(yPosition)/zPosition)*180/3.14;
                    int target = map(angle,0,90,0,16);
                    int movement=4000;
                    int iteration = target;
                    for(int i=0;i<=iteration;i++){
                      stepper2.move(movement);
                      stepper2.runToPosition();
                      }
                      
                    for(int angleServo = 0; angleServo<=targetAngle;angleServo++){
                      servo1.write(angleServo);
                      int angleServo3 = 2*angleServo;
                      servo3.write(angleServo3);
                      int angle2 = 180-angleServo;
                      servo2.write(angle2);
                      delay(15);
                    }
                    
                    delay(5000);
      
                    for(int angleServo = targetAngle; angleServo>=0;angleServo--){
                      servo1.write(angleServo);
                      int angleServo3 = 2*angleServo;
                      servo3.write(angleServo3);
                      int angle2 = 180-angleServo;
                      servo2.write(angle2);
                      delay(15);
                    }
                    
                      for(int i=0;i<=iteration;i++){
                          stepper2.move(-movement);
                          stepper2.runToPosition();
                          //delay(2000);
                      }
                }
  }

    else{
      Serial.println("Coordinate out of Scope");
    }
  
  stepper1.move(xPosition*400);
  stepper1.runToPosition();
 


}
bool getPositions(int &xPos, int &yPos, int &zPos) {
  Serial.println("Enter X, Y, Z positions separated by commas, 'sethome', or 'home'");
  while (Serial.available() == 0) {}

  String input = Serial.readStringUntil('\n');
  if(input == "sethome"){
     homeX = xPos;
     homeY = yPos;
     homeZ = zPos;
     Serial.println("Home position set.");
     return false;
  }
  else if(input == "home"){
    xPos = homeX;
    yPos = homeY;
    zPos = homeZ;
    Serial.println("Moving to home position.");
     return true;
  }
  int commaIndex1 = input.indexOf(',');
  int commaIndex2 = input.lastIndexOf(',');

  if (commaIndex1 == -1 || commaIndex2 == -1 || commaIndex1 == commaIndex2) {
    Serial.println("Invalid input. Please use the format X,Y,Z");
    return false;
  }

  String xStr = input.substring(0, commaIndex1);
  String yStr = input.substring(commaIndex1 + 1, commaIndex2);
  String zStr = input.substring(commaIndex2 + 1);

  xPos = xStr.toInt();
  yPos = yStr.toInt();
  zPos = zStr.toInt();

  Serial.print("Moving to position (X,Y,Z): ");
  Serial.print(xPos);
  Serial.print(",");
  Serial.print(yPos);
  Serial.print(",");
  Serial.println(zPos);
  return true;
}
