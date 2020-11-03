void block(){
    float multiplier;
    ballangle+=4;
    if (frontstrength>100) multiplier=0.3;
    else if (frontstrength>60) multiplier=0.2 ;
    else multiplier=0;
    if ((4+multiplier>ballangle)&&(ballangle>4-multiplier)){    
    Serial.print(multiplier);
    Serial.print(" ");
    Serial.println(frontstrength);
      calc(0,0);
    }
    else if (ballangle>=4){
      s=(ballangle-4)*k;
      calc(s,90);
     
    }
    else if (ballangle<4){
      s=(4-ballangle)*k;
      calc(s,270);

    }
  
    
}

void ram(){
  if (frontstrength>110){
    unsigned long currtime = millis();
    while(millis()-currtime < 500) {
      if (readfrontangle()!= 4) return;
    }
    calc(250,0);
    motorout();
    delay(400);
    calc(0,0);
    motorout();
    delay(100); 
    calc(250,180);
    motorout();
    delay(500);
  }
}

void goalkeep(){
  int dir=0;
  if (ultraVals[0]>10){
    if (ultraVals[1]<55) dir=135;
    else if (ultraVals[3]<55) dir=225;
    else dir=180;
  }
  else if (ultraVals[1]<55) dir=90;
  else if (ultraVals[3]<55) dir=270;
  while (goalLight()!=0){
    calc(slowspeed,90);
    anglecorrect();
    motorout();
    
    Serial.println("out");
  }
  
 

  
  }

