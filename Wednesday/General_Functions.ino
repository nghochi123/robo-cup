//MOVEMENT//
void on(int wait,int lpwr,int rpwr){ //36/37:left 38/39:claw 40/41:right
  /*lpwr = min(max(lpwr,-150),150);
  rpwr = min(max(rpwr,-150),150);*/
  if(lpwr > 0){
      digitalWrite(36,LOW); 
      digitalWrite(37,HIGH);
    }
  else{
      digitalWrite(36,HIGH);
      digitalWrite(37,LOW);
      lpwr = abs(lpwr);    
    }
  if(rpwr > 0){
      digitalWrite(40,LOW);
      digitalWrite(41,HIGH); 
    }
  else{
      digitalWrite(40,HIGH);
      digitalWrite(41,LOW);
      rpwr = abs(rpwr);
    }
  analogWrite(5,lpwr);
  analogWrite(7,rpwr);
  if(wait > 0){
    delay(wait);
  }
}

//CLAW//
void claw(int wait, int pwm){ // positive is up
  if(pwm<0){
    digitalWrite(39,HIGH);  //CMB High is down
    digitalWrite(38,LOW);
    pwm = abs(pwm);
  }
  
  else{
    digitalWrite(39,LOW);
    digitalWrite(38,HIGH);
  }
  
  analogWrite(6,pwm);
  
  if(wait > 0){
    delay(wait);
  }
}

//---------------SERVOS DUMP ALIVE--------------//

void alive(){   // dumpR 70, dumpL 110, left dead
  serdumpR.write(70);
  delay(2000);
  serdumpR.write(180);
}

//SEROVO DUMP BOTH//

void dump(){
  serdumpR.write(70);
  delay(2000);
  serdumpL.write(110);
  delay(2000);
  serdumpR.write(180);
  serdumpL.write(0);
}



//COMPASS//
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

int cmpsinita(){
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
    return initialangle;
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


//TURN ANGLE//
void cmpsturn(int dir, int deg){ //1 is right 0 is left for dir, use for last room or maybe 90 degree turns
  cmpsinit();
  if(dir == 0){
    while(actualangle > 360-deg || actualangle < 15){ //degree go clockwise so when turn left 360-90, less than 15 in case slight turn other directn.
      cmpsdeg();
      on(0,-150,150);    
    }
  }
  else if(dir == 1){
    while(actualangle < deg || actualangle > 345){ //same as above
      cmpsdeg();
      on(0,150,-150); 
    }
  }
  on(0,0,0);
  cmpsinit();
  cmpsdeg();
}



//Interrupt functions//
void tape(){
  if(light[1] > white [1]+10 || light[2] > white[2]+10 || light[3] > white[3]+10){
    on(1000,0,0);
    if(light[1] > white [1]+10 || light[2] > white[2]+10 || light[3] > white[3]+10){
      on(1000,0,0);
      room();
    }
  }
}

void ltreset(){
  if(digitalRead(49) == 1){
    on(1000,0,0);
    while(digitalRead(49) == 0){
      on(0,0,0);  
    }
    on(1000,0,0);
  }
}

void lrreset(){
  if(digitalRead(49) == 1){
    on(1000,0,0);
    while(digitalRead(49) == 0){
      on(0,0,0);
    }
    on(1000,0,0);
    //include last room program in here//
  }
}

