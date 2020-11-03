#include <Wire.h>
//green variables
int colour1, colour2;
int left, right;
#define COLOUR_ADDR     0x01
#define COLOUR_REG      0x42

//compass degree variables
int initialangle = 0;
int actualangle = 0;
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

//ultra variables
int obs = 100;
int distance = 1000;
#include <NewPing.h>
int front = 0;
int side = 0;

//line tracking variables
unsigned long curTime, prevTime;
bool foundline;

#define TRIGGER_PIN  22  // Arduino pin tied to trigger pin on the ultrasonic sensor.
#define ECHO_PIN     23  // Arduino pin tied to echo pin on the ultrasonic sensor.
#define MAX_DISTANCE 200 // Maximum distance we want to ping for (in centimeters). Maximum sensor distance is rated at 400-500cm.

NewPing sonar(TRIGGER_PIN, ECHO_PIN, MAX_DISTANCE); // NewPing setup of pins and maximum distance.

//2nd nano receive variables
int time = 0;
int ultra1 = 0;
int ultra2 = 0;

void setup()
{
  Wire.begin();
  Serial.begin(9600); //check all; 9600 for PC display, 115200 for communication
  Serial3.begin(115200);
  pinMode(30, OUTPUT);
  pinMode(31, OUTPUT);
  pinMode(8, OUTPUT);
  while (millis() < 6000) { //Callibration at the start
    light[0] = analogRead(A0);
    light[1] = analogRead(A1);
    light[2] = analogRead(A2);
    light[3] = analogRead(A3);
    light[4] = analogRead(A5); //A4 is spoilt
    for(int i=0; i<5; i++){
      if(light[i] > white[i]){
        white[i] = light[i];
      }
      else{
        if(light[i] < black[i]){
          black[i] = light[i];
        }
      }
    }
  }
  for(int i=0; i<5; i++){
    thresh[i] = (black[i] + white[i])/2; //Callibrated values go to thresh array
    thresh2[i] = (black[i] + 0.2*(white[i] - black[i]));
  }
}

