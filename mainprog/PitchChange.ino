void rampchk(){
  rampinit();
  delay(500);
  actualdeg();
  if(nowramp < -5){ //at bottom of ramp going up
    on(1000,80,80);
    on(0,0,0);
    delay(500);
    while(abs(nowramp) < 3){ //at top of ramp
      rampinit();
      delay(500);
      actualdeg();
      linetrack(90);  
    }
    linetrack(90);
    delay(1000);
    while(abs(nowramp)<3){ // going out of ramp
      rampinit();
      delay(500);
      actualdeg();
      linetrack(40);
    }
  }
}
void rampinit(){ //initialise ramp saving natural pitch
    Wire.begin();
    delay(1000);
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
}

