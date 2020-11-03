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
      serswitch.write(120);
    }
    
  }

  else{
    serswitch.write(60);
  }
  Serial.println(digitalRead(Cond));
}

