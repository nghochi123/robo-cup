//---------------PINS---------------//
#define SerCL  9 // Servo Check Left
#define SerCR  11 // Servo Check Right
#define SerS 10 // Servo Switch

#define Cond 8 // conduct

//---------------SERVO---------------//
#include <Servo.h>
Servo sercheckL;
Servo sercheckR;
Servo serswitch;

//---------------VARIABLES---------------//
unsigned long previousser = 0; // for check function
unsigned long currentser = 0;  // for check function
const int intervalser = 800; // for check function
int counterser = 0; // for check function

unsigned long conductser = 0; // for conductivity function

