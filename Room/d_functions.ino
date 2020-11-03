//---------------MOTORS---------------//

void on(int wait,int lpwr,int rpwr){
  if(rpwr < 0){
      digitalWrite(RMB,LOW); //RMB High is forward left
      digitalWrite(RMA,HIGH);
      rpwr = abs(rpwr);
    }
  else{
      digitalWrite(RMB,HIGH); //RMB High is forward left
      digitalWrite(RMA,LOW);    
  }
  if(lpwr < 0){
      digitalWrite(LMB,LOW);
      digitalWrite(LMA,HIGH);
      lpwr = abs(lpwr); 
  }
  else{
      digitalWrite(LMB,HIGH);
      digitalWrite(LMA,LOW);
  }
  analogWrite(RMPWM,rpwr);
  analogWrite(LMPWM,lpwr);

  if (wait>0){
    delay(wait);
  }
}

//---------------CLAW---------------//

void claw(int wait, int pwm){ // positive is up
  if(pwm<0){
    digitalWrite(CMB,HIGH);  //CMB High is down
    digitalWrite(CMA,LOW);
    pwm = abs(pwm);
  }
  
  else{
    digitalWrite(CMB,LOW);
    digitalWrite(CMA,HIGH);
  }
  
  analogWrite(CMPWM,pwm);
  
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


//TURN ANGLE//
void cmpsturn(int dir, int deg){ //1 is right 0 is left for dir, use for last room or maybe 90 degree turns
  cmpsinit();
  if(dir == 0){
    while(actualangle > 360-deg || actualangle < 15){ //degree go clockwise so when turn left 360-90, less than 15 in case slight turn other directn.
      cmpsdeg();
      on(0,-100,100);    
    }
  }
  else if(dir == 1){
    while(actualangle < deg || actualangle > 345){ //same as above
      cmpsdeg();
      on(0,100,-100); 
    }
  }
  on(0,0,0);
  cmpsinit();
  cmpsdeg();
}


// Turn corner//
void cmpsturncorner(int dir, int deg){ //1 is right 0 is left for dir, use for last room or maybe 90 degree turns
  cmpsinit();
  if(dir == 0){
    while(actualangle > 360-deg || actualangle < 15){ //degree go clockwise so when turn left 360-90, less than 15 in case slight turn other directn.
      cmpsdeg();
      on(0,-20,100);    
    }
  }
  else if(dir == 1){
    while(actualangle < deg || actualangle > 345){ //same as above
      cmpsdeg();
      on(0,100,-100); 
    }
  }
  on(0,0,0);
  cmpsinit();
  cmpsdeg();
}

void entercorner(){
  nano();
  if(side > 25){
    on(1000,0,0);
    if(side > 25){ //confirm that wall is not on right
      cmpsturn(1,90); // turns to face the not wall
    }
  }
}


/*
____________
 -->        | ultra detect no wall on right. if wall not on right turn to face right then continue
|           | with room sweep
|           |
|           |
|___________|
____________
 |          | ultra detect wall on right. continue room sweep.
||          |
|V          |
|           |
|___________|
*/

