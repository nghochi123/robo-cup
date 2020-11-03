//---------------PINS---------------//
#define SerCL  9 // Servo Check Left
#define SerCR  11 // Servo Check Right
#define SerS 10 // Servo Switch

#define Cond 12 // conduct

//---------------SERVO---------------//
#include <Servo.h>
Servo sercheckL;
Servo sercheckR;
Servo serswitch;

//Ultra

#define Trig1 4// Left Ultra
#define Echo1 3

#define Trig3 6 // Right Ultra
#define Echo3 7

#define MAX_DISTANCE 400

#include <NewPing.h>

NewPing sonar1(Trig1,Echo1,MAX_DISTANCE);
NewPing sonar3(Trig3,Echo3,MAX_DISTANCE);

int distance1;
int distance3;

//---------------VARIABLES---------------//
unsigned long previousser = 0; // for check function
unsigned long currentser = 0;  // for check function
const int intervalser = 800; // for check function
int counterser = 0; // for check function

unsigned long conductser = 0; // for conductivity function

