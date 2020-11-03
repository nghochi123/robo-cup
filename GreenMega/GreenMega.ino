#include <Wire.h>
int colour1, colour2;
#define COLOUR_ADDR     0x01
#define COLOUR_REG      0x42
int left, right;
int initialangle = 0;
int actualangle = 0;
#define CMPS11_ADDRESS 0x60  // Address of CMPS11 shifted right one bit for arduino wire library
#define ANGLE_8  1           // Register to read 8bit angle from

unsigned char high_byte, low_byte;
unsigned int angle16;

void setup(){
  Wire.begin();
  Serial.begin(9600);
  Serial3.begin(115200);
  pinMode(30, OUTPUT);
  pinMode(31, OUTPUT);
  pinMode(8, OUTPUT);
}
void loop(){
  delay(10);
  Wire.beginTransmission(COLOUR_ADDR);
  Wire.write(COLOUR_REG);
  Wire.endTransmission();
  Wire.requestFrom(COLOUR_ADDR, 1);
  colour1 = Wire.read();
  left = colour1;
  Serial3.write(1);
  if(Serial3.available()){
    colour2 = Serial3.read();
    right = colour2;
    Serial.print(left);
    Serial.print(" ");
    Serial.println(right); 
    if(left == 3 || left == 4){ //basically the retarded green program for mindstorms but in C. Right green 1 Left green 3/4
      on(0,0,0);
      delay(300);
      on(15,60,60);
      on(0,0,0);
      delay(300);
      right = Serial3.read();
      if(right == 1){
        on(1000,100,-100); // 180 turn
      }
      else{
        on(500,60,60); // turn left
        on(1500, 100, -100);        
      }
    }
    else if(right == 1){
      on(0,0,0);
      delay(300);
      on(15,60,60);
      on(0,0,0);
      delay(300);
      left = Wire.read();
      if(left == 3 || left == 4){
        on(1000,100,-100); //180 turn
      }
      else{
      on(500,60,60); // turn right
      on(1500, -100, 100);
      }
    }
    else{
      on(0, 45, 45); // no green present; replace this with line track program
    }  
  }
}
