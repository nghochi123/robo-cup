//colour sensor
#include <Wire.h>
int colour;
#define COLOUR_ADDR     0x01
#define COLOUR_REG      0x42

//ultrasonic sensor
#include <NewPing.h>
#define SONAR_NUM     3 // Number of sensors.
#define MAX_DISTANCE 200 // Maximum distance (in cm) to ping.
#define PING_INTERVAL 30 // Milliseconds between sensor pings (29ms is about the min to avoid cross-sensor echo).

unsigned long pingTimer[SONAR_NUM]; // Holds the times when the next ping should happen for each sensor.
unsigned int cm[SONAR_NUM];         // Where the ping distances are stored.
uint8_t currentSensor = 0;          // Keeps track of which sensor is active.
int frontult = 0;
int sideult = 0;
int outVals[4]={0,0,0,0};

NewPing sonar[SONAR_NUM] = {     // Sensor object array.
  NewPing(6, 5, MAX_DISTANCE), // Each sensor's trigger pin, echo pin, and max distance to ping.
  NewPing(10, 9, MAX_DISTANCE),
  NewPing(3, 4, MAX_DISTANCE),
};


void setup() {
  Wire.begin();
  Serial.begin(115200);
   pingTimer[0] = millis() + 75;           // First ping starts at 75ms, gives time for the Arduino to chill before starting.
  for (uint8_t i = 1; i < SONAR_NUM; i++) // Set the starting time for each sensor.
    pingTimer[i] = pingTimer[i - 1] + PING_INTERVAL;
}
// 0 black 3,4 green anything else is white

void loop() {
  delay(10);
  Wire.beginTransmission(COLOUR_ADDR);
  Wire.write(COLOUR_REG);
  Wire.endTransmission();
  Wire.requestFrom(COLOUR_ADDR, 1);
  colour = Wire.read();
  ultra();
  outVals[2] = colour;
    if(Serial.available()){ 
    int hkfxzlk = Serial.read();
    Serial.write(outVals[0]);
    Serial.write(outVals[1]);
    Serial.write(outVals[2]);
    Serial.write(outVals[3]);
  }
}
