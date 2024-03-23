#include <AccelStepper.h>

// Define the stepper motor connections
#define STEP_PIN 2
#define DIR_PIN 3

// Create a new instance of the AccelStepper class
AccelStepper stepper(AccelStepper::DRIVER, STEP_PIN, DIR_PIN);

void setup() {
  // Set the maximum speed and acceleration
  stepper.setMaxSpeed(1000);  // Adjust the speed as needed
  stepper.setAcceleration(500); // Adjust the acceleration as needed
 // stepper.setEnablePin(4); // Enable pin for TMC2209 (if needed, otherwise connect to GND)
 // stepper.enableOutputs(); // Enable the outputs
  
  // Set the motor direction to clockwise
  stepper.setSpeed(500); // Set initial speed
}

void loop() {
  // Rotate one full rotation clockwise
  while (stepper.currentPosition() < 200 * 16) { // 200 steps per full rotation (assuming 16 microsteps)
    stepper.runSpeed();
  }
  delay(1000); // Add a delay for stability
  
  // Set the motor direction to anticlockwise
  stepper.setSpeed(-500); // Set negative speed for anticlockwise rotation
  
  // Rotate one full rotation anticlockwise
  while (stepper.currentPosition() > 0) {
    stepper.runSpeed();
  }
  delay(1000); // Add a delay for stability
}
