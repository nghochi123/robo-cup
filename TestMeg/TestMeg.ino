int obs = 100;
int distance = 1000;
#include <NewPing.h>

#define TRIGGER_PIN  22  // Arduino pin tied to trigger pin on the ultrasonic sensor.
#define ECHO_PIN     23  // Arduino pin tied to echo pin on the ultrasonic sensor.
#define MAX_DISTANCE 200 // Maximum distance we want to ping for (in centimeters). Maximum sensor distance is rated at 400-500cm.

NewPing sonar(TRIGGER_PIN, ECHO_PIN, MAX_DISTANCE); // NewPing setup of pins and maximum distance.

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  Serial3.begin(115200);
}

void loop() {
  Serial.println(distance);
  Serial3.write(1);
  // put your main code here, to run repeatedly:
  if(Serial3.available()){
    obs = Serial3.read();
  }
  if(obs == 4){
    on(100,-60,-60);
    //turn left until ultra senses less than 20
    while(sonar.ping_cm() > 20){
      int distance = sonar.ping_cm();
      on(0,-45,65);      
    }
    on(750, -45, 65);
    on(1000, 0, 0);
    //move forward while turning left depending on distance from obstacle
    while(0 == 0){
      int dist = sonar.ping_cm();
      Serial.println(dist);
      if (abs(dist) > 12 || dist == 0){
        on(0, 80, -65);   
      }
      else { 
        on(0,60,60);
      }
    }
    
    //stop when light sensor detect black
    //turn left then move back
  }
  else{
    on(0,60,60);
  }
}



