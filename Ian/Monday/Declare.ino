#include <Wire.h>

#define Touch45  27 // touch sensor

//green variables
int colour1, colour2;
int left, right;
unsigned long greenTime = 0;
bool det;
#define COLOUR_ADDR     0x01
#define COLOUR_REG      0x42

//compass degree variables
int initialangle = 0;
int actualangle = 0;
float initialangle1 = 0;
unsigned char high_byte, low_byte;
unsigned int angle16;
#define CMPS11_ADDRESS 0x60  // Address of CMPS11 shifted right one bit for arduino wire library
#define ANGLE_8  1           // Register to read 8bit angle from

//pitch angle variables
int angleramp = 0;
int actualramp = 0;
int rampint = 0;
int nowramp = 0;
char pitch;

//light sensor variables
int light[5];
int black[5]={1000,1000,1000,1000,1000};
int white[5]={0,0,0,0,0};
int thresh[5], thresh2[5]; //thresh[5] is a lower threshold for 90 degree turns
#define LDR_0   A5
#define LDR_1   A3
#define LDR_2   A2
#define LDR_3   A1
#define LDR_4   A0

//ultra variables
int obs = 100;
int distance = 1000;
#include <NewPing.h>

//nano variables
int front, side, ultra1, ultra2, above;
unsigned long timer;

//line tracking variables
unsigned long curTime, prevTime, tmpcount, obsTime, rampTime;
bool foundline;

//---------------go straight---------------//
unsigned long edgetimer = 0;
int touch;

unsigned long touchtimer = 0;

//---------------SERVO PIN---------------//
#include <Servo.h>
#define SerDL 3 // Servo Dump Left
#define SerDR 4 // Servo Dump Right
#define Serswp 2

Servo serdumpL;
Servo serdumpR;
Servo sersweep;

int dir;
int l180;
int r90;
int l45;
int l90;

int prevtouch;
int obst;
