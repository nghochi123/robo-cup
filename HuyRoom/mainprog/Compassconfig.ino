void cmpsturn(int dir, int deg){ //1 is right 0 is left for dir, use for last room or maybe 90 degree turns
  cmpsinit();
  if(dir == 0){
    while(actualangle > 360-deg || actualangle < 15){ //degree go clockwise so when turn left 360-90, less than 15 in case slight turn other directn.
      cmpsdeg();
      on(0, -170, 150);    
    }
  }
  else if(dir == 1){
    while(actualangle < deg || actualangle > 345){ //same as above
      cmpsdeg();
      on(0, 150, -170); 
    }
  }
  on(0,0,0);
  cmpsinit();//reinitialise compass
  cmpsdeg();
}

void cmpsinit(){
    Wire.beginTransmission(CMPS11_ADDRESS);  //starts communication with CMPS11
    Wire.write(2);                     //Sends the register we wish to start reading from
    Wire.endTransmission();
    
    Wire.requestFrom(CMPS11_ADDRESS, 2);       
    
    while(Wire.available() < 2);        // Wait for all bytes to come back
    high_byte = Wire.read();
    low_byte = Wire.read();
    
    angle16 = high_byte;                 // Calculate 16 bit angle
    angle16 <<= 8;
    angle16 += low_byte;
    initialangle = angle16/10;  
}

void cmpsdeg(){
    Wire.beginTransmission(CMPS11_ADDRESS);  //starts communication with CMPS11
    Wire.write(2);                     //Sends the register we wish to start reading from
    Wire.endTransmission();
    
    Wire.requestFrom(CMPS11_ADDRESS, 2);       
    
    while(Wire.available() < 2);        // Wait for all bytes to come back
   
    high_byte = Wire.read();
    low_byte = Wire.read();
    
    angle16 = high_byte;                 // Calculate 16 bit angle
    angle16 <<= 8;
    angle16 += low_byte;
    actualangle = angle16/10 - initialangle;
    if(actualangle<0){
      actualangle += 360;
    }
    Serial.println(actualangle);
}

