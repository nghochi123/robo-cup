#include <Wire.h>
#include <SPI.h>
#include <Pixy.h>

Pixy pixy;

//compass variables
const int CMPS11_ADDRESS = 0x60;
int high_byte, low_byte, angle16, error,targetang, compassoffset=0,originaloffset=0,goaloffset=0;

//i2c variables
int ultraVals[4] ,ldr[9],goal[9],irVals[7];
int ultradist[4]={18,85,0,85}; 

//int lightThresh[9]={434, 474, 427, 377, 302, 322, 193, 242, 117, }; //legit
int lightThresh[9]={461, 444, 418, 372, 329, 332, 260, 299, 249,}; //test
int goalThresh[9]={235, 234, 186, 195, 189, 177, 148, 136, 115,}; 
int indexir[7]={5,6,7,1,2,3,4};

int goalwidth, goalx, goalindex,goalfound,goalerror;


const float sidedist=121;
const float backdist=39;
float ultraleft,ultraright,ultraback;

int indexa,indexb;
float maxstrength,frontstrength,IRchannel,IRmultiplier;
float irpercenta,irpercentb;

int anglek=2;
const int maxanglek=3;
float ballangle, backangle, robotangle,robotdir;
int frontangle;
float backstrength;
int lastDetect, firstLightDeg;

const int FLPWM = 2; const int FLDIG = 33;
const int FRPWM = 3; const int FRDIG = 35;
const int BLPWM = 4; const int BLDIG = 37;
const int BRPWM = 5; const int BRDIG = 39;

float a, b;
float FLout, FRout, BRout, BLout;
float s;
int speed = 150;
const int maxspeed= 250;
const int slowspeed=160;
const int correctspeed=200;
const float k = 250;

void setup () {
  
  pinMode (FLPWM, OUTPUT);
  pinMode (FLDIG, OUTPUT);
  pinMode (FRPWM, OUTPUT);
  pinMode (FRDIG, OUTPUT);
  pinMode (BLPWM, OUTPUT);
  pinMode (BLDIG, OUTPUT);
  pinMode (BRPWM, OUTPUT);
  pinMode (BRDIG, OUTPUT);
  Serial.begin(9600);
  Serial2.begin(115200);
  Wire.begin(); 
  FLout = 0; FRout=0; BLout=0; BRout=0;
  calc(0,0);
  //motorout();
  delay(1000);
  cmpsinit();
  pixy.init();

}

void loop (){
  compassoffset=originaloffset;
  anglek=2;
  frontangle = readfrontangle();
  frontstrength = readfrontstrength();
  readNano(); //reads backangle, backstrength, ultraArr[4];
   processir();
  track();
  centregoal();
  anglecorrect();
  motorout(); 
 

  /*
  
  Serial.println(compassoffset);
  Serial.print(FLout);
  Serial.print(" ");
  Serial.print(FRout);
  Serial.print(" ");
  Serial.print(BLout);
  Serial.print(" ");
  Serial.println(BRout);*/
}
 
  /*readcmps();
  b int angular = 360-angle16;
  if (angular>360) angular-=360;
  angular_drive(angular,150,0);
  motorout();
 
  */

  /*processir();
  Serial.print(frontangle);
  Serial.print(" ");
  Serial.print(frontstrength);
  Serial.print(" ");
  
  Serial.println(" ");
  //Serial.println(ballangle);
  track();
*/
 
 /* if ((checkLight())!=0){
    bounceback();
  }*/

  
  /*processir();
  
 
  track();
  

 
  anglecorrect();
  regspeed();
  motorout();
  if ((frontstrength<16)&&(backstrength<16)){
    if (ultraVals[1]>ultraVals[3]){
      returnright();
      motorout();
      //Serial.println("returnright");
    }
    else{
      returnleft();
      motorout();
      //Serial.println("returnleft");
    }*/
  

