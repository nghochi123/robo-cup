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


//---------------VARIABLES---------------//
unsigned long previousser = 0; // for check function
unsigned long currentser = 0;  // for check function
const int intervalser = 800; // for check function
int counterser = 0; // for check function

unsigned long conductser = 0; // for conductivity function

// Ultra
int timer = 0;

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
  NewPing(4, 3, MAX_DISTANCE), // Each sensor's trigger pin, echo pin, and max distance to ping.
  NewPing(6, 7, MAX_DISTANCE),
};
