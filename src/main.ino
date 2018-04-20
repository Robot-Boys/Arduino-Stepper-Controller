#include <Arduino.h>
#include <Stepper.h>

const int stepperEnablePinA = 2;
const int stepperEnablePinB = 3;

const int stepsPerRevolution = 200; // change this to fit the number of steps per revolution
unsigned int stepperSpeed = 100;
// for your motor

// initialize the stepper library on pins 8 through 11:
Stepper myStepper(stepsPerRevolution, 4, 5, 6, 7);

void setup()
{
    pinMode(stepperEnablePinA, OUTPUT);
    pinMode(stepperEnablePinB, OUTPUT);

    // set the speed at 60 rpm:
    myStepper.setSpeed(stepperSpeed);
    // initialize the serial port:
    Serial.begin(9600);
}

void loop()
{
    // step one revolution  in one direction:

    Serial.println("clockwise");

    enableStepper();
    myStepper.step(stepsPerRevolution);
    disableStepper();

    delay(500);

    enableStepper();
    myStepper.step(-stepsPerRevolution);
    disableStepper();

    delay(500);
}

void enableStepper()
{
    digitalWrite(stepperEnablePinA, HIGH);
    digitalWrite(stepperEnablePinB, HIGH);
}

void disableStepper()
{
    digitalWrite(stepperEnablePinA, LOW);
    digitalWrite(stepperEnablePinB, LOW);
}
