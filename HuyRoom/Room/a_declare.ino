//---------------PINS--------------//
#define LMA  36 // left motor inA
#define LMB  37 // left motor inB
#define LMPWM 5 // left motor PWM

#define RMA  40 // right motor inA
#define RMB 41 // right motor inB
#define RMPWM  7 // right motor PWM

#define CMA 38 // claw motor inA
#define CMB 39 // claw motor inB
#define CMPWM  6 // claw motor PWM

#define SerDL 3 // Servo Dump Left
#define SerDR 4 // Servo Dump Right

#define Touch45  27 // touch sensor

#define Serswp 2

#define Trigside 10//Side
#define Echoside 9

#define Trig2 5 // Mid Ultra
#define Echo2 6

#define Trigup 3 // Up Ultra
#define Echoup 4
#define MAX_DISTANCE 400

//Ultra

#include <NewPing.h>

NewPing sonar2(Trig2,Echo2,MAX_DISTANCE);
NewPing sonarside(Trigside,Echoside,MAX_DISTANCE);

int distance2 ;
int distanceside ;



//---------------SERVO PIN---------------//
#include <Servo.h>

Servo serdumpL;
Servo serdumpR;
Servo sersweep;

//---------------go straight---------------//
unsigned long edgetimer = 0;
int touch;

unsigned long touchtimer = 0;

// turn //
#include <Wire.h>
float actualangle = 0;
float initialangle = 0;
float initialangle1 = 0;
#define CMPS11_ADDRESS 0x60 
unsigned char high_byte, low_byte, angle8;
unsigned int angle16;

// Obstacle
int ultra1;
int ultra2;
int ultra3;
int ultra4;
