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

//---------Detect Obstacle-------//

void detectedright(){
  on(150,-150,-150);
  on(0,0,0);
  claw(1500, 150);
  on(300,150,150);
  cmpsturn(0,85);
  on(1000,-150,-150);
  on(500,150,150);
  cmpsturn(1,85);
  on(1200,150,150);
  cmpsturn(0,85);
  on(1200,-150,-150);
  cmpsturn(1,85);
}
void detectedleft(){
  on(150,-150,-150);
  on(0,0,0);
  claw(1500, 150);
  on(200,150,150);
  cmpsturn(0,85);
  on(1000,-150,-150);
  on(700,150,150);
  cmpsturn(1,85);
  on(1500,150,150);
  cmpsturn(0,85);
  on(1800,-150,-150);
  cmpsturn(1,85); 
}

void detectobs() {  
    if(ultra1 < 8 || ultra2 <8){
      if( abs(ultra1 - ultra2) >15 && abs(ultra1 - ultra2) < 150){
          if( ultra1 > ultra2){
            detectedright();
          }
          else{
            detectedleft();
          }
      }
    }
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

// Turn corner//
void cmpsturncorner(int dir, int deg){ //1 is right 0 is left for dir, use for last room or maybe 90 degree turns
  cmpsinit();
  if(dir == 0){
    while(actualangle > 360-deg || actualangle < 15){ //degree go clockwise so when turn left 360-90, less than 15 in case slight turn other directn.
      cmpsdeg();
      on(0,-20,150);    
    }
  }
  else if(dir == 1){
    while(actualangle < deg || actualangle > 345){ //same as above
      cmpsdeg();
      on(0,70,-150); 
    }
  }
  on(0,0,0);
  cmpsinit();
  cmpsdeg();
}



//Straight and collect//
void edge() {
  sersweep.write(110);
  
  edgetimer = millis();
  while ( millis() - edgetimer <= 5000){ // run along edge for 3 secs or touched
    touch = digitalRead(Touch45);
    if (touch == 1){
      Serial.println(touch);
      break;
    }
    else{
      claw(0,-100);
      delay(300);
      on(0,150,100);
      nano();
      detectobs();
      if (side > 30){
        on(0,100,110);
      }
    }      
  }    
}


void touched(){
  on(50,-150,-150);
  cmpsturncorner(0,30);
  touchtimer = millis();
  on(1000,150,150);
  on(50,-150,-150);
  cmpsturncorner(0,30);
}

// Corner 1 /
/*

void corner(int a){
  if (touch == 1){
    touched();
  }
  else
  {
    on(220,-100,-100);
    on(0,0,0);
    claw(1500,100);
    on(200,-100,-100);
    cmpsturncorner(0, a);
    on(200,150,150);
    on(200,-150,-150);
    on(1000,-150,-150);

  }
}
*/

// Corner 2 //

void corner(int a){
  if (touch == 1){
    touched();
  }
  else
  {
    on(220,-100,-100);
    on(0,0,0);
    claw(1000,100);
    cmpsturn(0,170);
    on(1000,-150,-150);
    on(400,100,100);
    cmpsturncorner(1,a);


  }
}
  
void dumptouched(){
  on(100,-150,-150);
  cmpsturncorner(0,40);
  on(300,150,150);
  cmpsturn(0,70);
  on(2000,-150,-150);
  alive();
  on(100,150,150);
  cmpsturn(1,70);
  
  touch = 0;
  touchtimer = millis();
  while ( millis() - touchtimer <= 1500){
    on(0,150,150);
  }

}

void dumpcorner(){
  if (touch == 1){
    dumptouched();
  }
  else
  {
    on(230,-100,-100);
    on(0,0,0);
    claw(1500,150);
    on(200,-100,-100);
    cmpsturncorner(0, 85);
    on(200,150,150);
    on(200,-150,-150);
    on(1000,-150,-150);
}
}


//Interrupt functions//
void tape(){
  if(light[1] > white [1]+10 || light[2] > white[2]+10 || light[3] > white[3]+10){
    on(1000,0,0);
    if(light[1] > white [1]+10 || light[2] > white[2]+10 || light[3] > white[3]+10){
      on(10000,0,0);
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

