void loop() {
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
 /* dist1 = sonar1.ping_cm();
  dist3 = sonar3.ping_cm();
  Serial.print("1 ");
  Serial.print(dist1);
  Serial.print(" 3 ");
  Serial.println(dist3);
  if ( dist1 < 10 || dist3 <10){
    Serial.print("what");
    if ( abs(dist1 - dist3) >10){
      Serial.println(" Obstacle ");
    }
  }
  */
  servocheck();
  conduct();
  }
