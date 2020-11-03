int obs = 100;
int distance = 1000;
#include <NewPing.h>

#define TRIGGER_PIN  50  // Arduino pin tied to trigger pin on the ultrasonic sensor.
#define ECHO_PIN     51  // Arduino pin tied to echo pin on the ultrasonic sensor.
#define MAX_DISTANCE 200 // Maximum distance we want to ping for (in centimeters). Maximum sensor distance is rated at 400-500cm.

NewPing sonar(TRIGGER_PIN, ECHO_PIN, MAX_DISTANCE); // NewPing setup of pins and maximum distance.

void setup() {
  // put your setup code here, to run once:
  Serial.begin(115200);
  Serial3.begin(115200);
}

void loop() {
   Serial3.write(1);
  // put your main code here, to run repeatedly:
  if(Serial3.available()){
    obs = Serial3.read();
  }
  if(obs == 1){
    //on(500,-60,-60);
    //turn left until ultra senses less than 20
    while(sonar.ping_cm() > 30){
      int distance = sonar.ping_cm();
      Serial.println(sonar.ping_cm());
      on(0,60,-45);      
    }
    delay(1000);
    //move forward while turning right depending on distance from obstacle
    while(0 == 0){
      int distance = 0.8*sonar.ping_cm();
      on(0,50+distance,50-distance);
    }
    //stop when light sensor detect black
    //turn left then move back
  }
  else{
    on(0,60,60);
  }
  }



