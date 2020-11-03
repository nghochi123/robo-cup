void cmpsinit(){
  anglecorrect();
  originaloffset=angle16;
}
void readcmps(){
  Wire.beginTransmission(CMPS11_ADDRESS);  
  Wire.write(2);                     
  Wire.endTransmission(); 
  Wire.requestFrom(CMPS11_ADDRESS, 2);       
  while(Wire.available() < 2);           
  high_byte = Wire.read();
  low_byte = Wire.read();
 
  angle16 = high_byte;                 // Calculate 16 bit angle
  angle16 <<= 8;
  angle16 += low_byte;
  angle16 /= 10;
  angle16-=compassoffset;
  if (angle16<0){
    angle16+=360;
  }
}
void anglecorrect (){
  Wire.beginTransmission(CMPS11_ADDRESS);  
  Wire.write(2);                     
  Wire.endTransmission(); 
  Wire.requestFrom(CMPS11_ADDRESS, 2);       
  while(Wire.available() < 2);           
  high_byte = Wire.read();
  low_byte = Wire.read();
 
  angle16 = high_byte;                 // Calculate 16 bit angle
  angle16 <<= 8;
  angle16 += low_byte;
  angle16 /= 10;
  angle16-=compassoffset;
  if (angle16<0){
    angle16+=360;
  }
 
 /*if(((robotdir>=70)&&(robotdir<=110))||((robotangle>=250)&&(robotdir<=290))){
    error = angle16*anglek;
    FLout += error;
    BLout -= error;
    FRout += error;
    BRout -= error;
  }*/
  if (angle16 > 180) {
    error = (360-angle16)*anglek; //convert angle to degrees from north
    FLout += error;
    BLout += error;
    FRout -= error;
    BRout -= error;
  } 
  
  else {
    error = angle16*anglek;
    FLout -= error;
    BLout -= error;
    FRout += error;
    BRout += error;
  }
  if (FLout > 255) FLout = 255;
  if (FLout <-255) FLout = -255;
  if (FRout > 255) FRout = 255;
  if (FRout <-255) FRout = -255;
  if (BLout > 255) BLout = 255;
  if (BLout <-255) BLout = -255;
  if (BRout > 255) BRout = 255;
  if (BRout <-255) BRout = -255;

  
}
 

