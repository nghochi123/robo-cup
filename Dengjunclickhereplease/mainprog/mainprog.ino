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
unsigned long time;

//line tracking variables
unsigned long curTime, prevTime;
bool foundline;

void setup()
{
  Wire.begin();
  Serial.begin(9600); //check all; 9600 for PC display, 115200 for communication
  Serial3.begin(115200);
  pinMode(30, OUTPUT);
  pinMode(31, OUTPUT);
  pinMode(8, OUTPUT);
  while (millis() < 6000) { //Callibration at the start
    light[0] = analogRead(LDR_0);
    light[1] = analogRead(LDR_1);
    light[2] = analogRead(LDR_2);
    light[3] = analogRead(LDR_3);
    light[4] = analogRead(LDR_4); //A4 is spoilt
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
    thresh2[i] = (black[i] + 0.3*(white[i] - black[i]));
  }
    rampinit();
}

void loop(){  
  tape();
  linetrack(90);
  claw(60);
  green();
  rampchk();
}
