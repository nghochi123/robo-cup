void cmpsRT(int deg){
  cmpsinit();
  while(actualangle < deg){
    cmpsdeg();
    on(0,90,-90);    
  }
}

void cmpsinit(){
    Wire.begin();
    delay(1000);
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
}

