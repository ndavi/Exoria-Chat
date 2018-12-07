
#include <Conceptinetics.h>
#include <Stepper.h>
#include <Arduino.h>


#define DMX_SLAVE_CHANNELS   4
#define DMX_START_ADRESS     1
#define DMX                  true

const int brakeMotorA = 9;
const int directionMotorA = 12;
const int speedMotorA = 3;

const int brakeMotorB = 8;
const int directionMotorB = 13;
const int speedMotorB = 11;

const int speedMotorC = 4;
const int speedMotorD = 10;



DMX_Slave dmx_slave ( DMX_SLAVE_CHANNELS );



void setupMotors() {
    pinMode(directionMotorA, OUTPUT); //Initiates Motor A Channel A-B pin
    pinMode(brakeMotorA, OUTPUT); //Initiates Brake A Channel A-B pin

    pinMode(directionMotorB, OUTPUT); //Initiates Motor B Channel A-B pin
    pinMode(brakeMotorB, OUTPUT); //Initiates Brake B Channel A-B pin
}

void setup() {
  setupMotors();  
    dmx_slave.enable();
    dmx_slave.setStartAddress(DMX_START_ADRESS);

 // Serial.begin(9600);
}

void loop() 
{
  digitalWrite(brakeMotorA, LOW);   //Disengage the Brake for Channel A
  digitalWrite(brakeMotorB, LOW);   //Disengage the Brake for Channel B
  //Motor A forward @ full speed
  digitalWrite(directionMotorA, HIGH); //Establishes forward direction of Channel A
  
  analogWrite(speedMotorA, dmx_slave.getChannelValue (1));   //Spins the motor on Channel A at full speed

  //Motor B forward @ full speed
  digitalWrite(directionMotorB, HIGH); //Establishes forward direction of Channel A
  analogWrite(speedMotorB, dmx_slave.getChannelValue (2));
  analogWrite(speedMotorC, dmx_slave.getChannelValue (3)); 
  analogWrite(speedMotorD, dmx_slave.getChannelValue (4));    //Spins the motor on Channel A at full speed

}