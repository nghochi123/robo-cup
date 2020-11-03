//----------------CHECK---------------//
void servocheck(){
  currentser = millis();
  if ( currentser - previousser >= intervalser){
    if (counterser % 2 ==0){
      sercheckR.write(180);
      sercheckL.write(0);
    }
    else{
      sercheckR.write(0);
      sercheckL.write(180);
    }
    counterser +=1;
    previousser = currentser;
  }
  
}

//---------------CONDUCTIVITY---------------//
void conduct(){
  if (digitalRead(Cond) == 1){
    conductser = millis();
    while (millis() - conductser <= 600){
      servocheck();
      serswitch.write(110);
    }
    
  }

  else{
    serswitch.write(70);
  }
  ;
}

//-------ULTRA------//

void echoCheck() { // If ping received, set the sensor distance to array.
  if (sonar[currentSensor].check_timer())
    cm[currentSensor] = sonar[currentSensor].ping_result / US_ROUNDTRIP_CM;
}

void oneSensorCycle() { // Sensor ping cycle complete, do something with the results.
  // The following code would be replaced with your code that does something with the ping results.
    ultra[0] = cm[0];
    ultra[1] = cm[1];
  if ( Serial.available()){
    int mega = Serial.read();
    if (mega == 10){
      Serial.write(ultra[0]);
      Serial.write(ultra[1]); 

    }
  }
}
