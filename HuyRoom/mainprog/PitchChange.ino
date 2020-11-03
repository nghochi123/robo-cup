void rampchk(){
  actualdeg();
  if(nowramp < -23){ //at bottom of ramp going up
    claw(60);
    on(500,150,150);
    on(1000,0,0);
    linetrack(150);
    delay(1000);
    while(nowramp < -23){ //going towards top of ramp
      claw(60);
      actualdeg();
      Serial.println(nowramp);
      linetrack(150);  
    }
    on(1000,0,0);// at top of ramp, stopping
    actualdeg();
    while(abs(nowramp) < 10){ //while it is still at the top of the ramp
      claw(-60);
      actualdeg();
      Serial.println(nowramp);
      linetrack(70);
    }
    on(1000,0,0);
    actualdeg();
    while(nowramp > 23){ // going out of ramp
      claw(60);
      actualdeg();
      Serial.println(nowramp);
      on(0,10,10);
    }
    claw(60);
    delay(1000);
    on(500,0,0);
  }   
}
void rampinit(){ //initialise ramp saving natural pitch
    Wire.begin();
    Wire.beginTransmission(CMPS11_ADDRESS);  //starts communication with CMPS11
    Wire.write(4);                     //Sends the register we wish to start reading from
    Wire.endTransmission();
    
    Wire.requestFrom(CMPS11_ADDRESS, 4);       
    
    while(Wire.available() < 1);        // Wait for all bytes to come back
    pitch = Wire.read();
    rampint = pitch,DEC;
}

void actualdeg(){ //calculating actual pitch based on offset
    Wire.beginTransmission(CMPS11_ADDRESS);  //starts communication with CMPS11
    Wire.write(4);                     //Sends the register we wish to start reading from
    Wire.endTransmission();
    
    Wire.requestFrom(CMPS11_ADDRESS, 4);       
    
    while(Wire.available() < 1);        // Wait for all bytes to come back
    pitch = Wire.read();
    actualramp = pitch,DEC;
    nowramp = actualramp - rampint;      
    Serial.println(nowramp);
}

