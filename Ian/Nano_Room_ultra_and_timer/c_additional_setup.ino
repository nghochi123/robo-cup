


void ultratomega(){
  ultra();
  timer = millis()/1000;
  outVals[0] = timer;
  if(Serial.available()){
    int mega = Serial.read();
    if (mega == 1){
    Serial.write(outVals[1]);
    Serial.write(outVals[2]);
    }
    if(mega == 2){
    Serial.write(outVals[0]);
    }
}
}


/*void timetomega(){
  timer = millis()/1000;
  outVals[0] = timer;
  if(Serial.available()){
    int mega = Serial.read();
    if (mega == 0){
    Serial.write(outVals[0]);
  }
  }
}
*/

void ultra() {
  for (uint8_t i = 0; i < SONAR_NUM; i++) { // Loop through all the sensors.
    if (millis() >= pingTimer[i]) {         // Is it this sensor's time to ping?
      pingTimer[i] += PING_INTERVAL * SONAR_NUM;  // Set next time this sensor will be pinged.
      if (i == 0 && currentSensor == SONAR_NUM - 1) oneSensorCycle(); // Sensor ping cycle complete, do something with the results.
      sonar[currentSensor].timer_stop();          // Make sure previous timer is canceled before starting a new ping (insurance).
      currentSensor = i;                          // Sensor being accessed.
      cm[currentSensor] = 0;                      // Make distance zero in case there's no ping echo for this sensor.
      sonar[currentSensor].ping_timer(echoCheck); // Do the ping (processing continues, interrupt will call echoCheck to look for echo).
    }
  }
  // Other code that *DOESN'T* analyze ping results can go here.
}

void echoCheck() { // If ping received, set the sensor distance to array.
  if (sonar[currentSensor].check_timer())
    cm[currentSensor] = sonar[currentSensor].ping_result / US_ROUNDTRIP_CM;
}

void oneSensorCycle() { // Sensor ping cycle complete, do something with the results.
  // The following code would be replaced with your code that does something with the ping results.
  outVals[1] = cm[0];
  outVals[2] = cm[1]; 
}  

