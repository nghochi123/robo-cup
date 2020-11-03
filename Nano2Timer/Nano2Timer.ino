int time = 0;

//ultrasonic sensor
#include <NewPing.h>
#define SONAR_NUM     2 // Number of sensors.
#define MAX_DISTANCE 200 // Maximum distance (in cm) to ping.
#define PING_INTERVAL 30 // Milliseconds between sensor pings (29ms is about the min to avoid cross-sensor echo).
unsigned long pingTimer[SONAR_NUM]; // Holds the times when the next ping should happen for each sensor.
unsigned int cm[SONAR_NUM];         // Where the ping distances are stored.
uint8_t currentSensor = 0;          // Keeps track of which sensor is active.
int outVals[3]={0,0,0};

NewPing sonar[SONAR_NUM] = {     // Sensor object array.
  NewPing(3, 4, MAX_DISTANCE), // Each sensor's trigger pin, echo pin, and max distance to ping.
  NewPing(7, 6, MAX_DISTANCE),
};


void sendtomega(){
  time = millis()/1000;
  outVals[0] = time;
  ultra();
  if(Serial.available()){
    int hello = Serial.read();
    Serial.write(outVals[0]);
    Serial.write(outVals[1]);
    Serial.write(outVals[2]);
  }
}

