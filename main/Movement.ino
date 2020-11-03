void angular_drive(float angle, int spd, float angVel) {
  if(angle>=270) angle -= 360;
  float radAng = (90+angle)*3.141592654/180;    //convert angle to vector coordinates
  //cout <<sin(radAng)<<"\t"<<cos(radAng)<<endl;
  float x_co = sin(radAng);
  float y_co = cos(radAng);
  
  FLout = -(-0.707*x_co+0.707*y_co + angVel);  //resolve wheel vectors
  FRout = 0.707*x_co+0.707*y_co + angVel;
  BLout = -(-0.707*x_co-0.707*y_co + angVel);
  BRout = 0.707*x_co-0.707*y_co + angVel;
  
  float factor = spd/max(max(abs(FLout),abs(FRout)),max(abs(BLout),abs(BRout)));  //scale all to speed
  FLout = round(factor * FLout);
  FRout = round(factor * FRout);
  BLout = round(factor * BLout);
  BRout = round(factor * BRout);
}

void calc(int spd, float dir) {
  robotdir=dir;
  float radang=3.14592654*45/180, raddir=3.141592654*dir/180;
  a = cos(radang-raddir);
  b = cos(radang+raddir);
  
  if (abs(a) > abs(b)) {  //scale to speed
    b *= spd/a;
    a = spd;
  } else {
    a *= spd/b;
    b = spd;
  }
  
  if (dir >= 90 && dir < 270) { //backwards movment
    a = -a;
    b = -b;
  }
  FLout = a; FRout=b; BLout=b; BRout=a;
}

void motorout() { 
  
  
  analogWrite(FLPWM, abs(FLout));
  if (FLout > 0) digitalWrite(FLDIG, LOW);
  else digitalWrite(FLDIG, HIGH);

  analogWrite(FRPWM  , abs(FRout));
  if (BLout > 0) digitalWrite(FRDIG, LOW);
  else digitalWrite(FRDIG, HIGH); 
  
  analogWrite(BLPWM, abs(BLout));
  if (FRout > 0) digitalWrite(BLDIG, HIGH);
  else digitalWrite(BLDIG, LOW);//BL HAS REVERSE DIRECTIONS 
  
  analogWrite(BRPWM, abs(BRout));
  if (BRout > 0) digitalWrite(BRDIG, LOW);
  else digitalWrite(BRDIG, HIGH);
  
}
void returnright(){
  float test;
  ultraback=(ultraVals[0]-ultradist[0]);
  ultraright=(ultraVals[3]-ultradist[3]);
  /*Serial.print("right ");
  Serial.print(ultraright);
  Serial.print(' ');
  Serial.print(ultraback);
  Serial.print(" ");*/
  if (abs(ultraright)<10 && abs(ultraback)<10) {
    calc(0,0);
  }
  else {
    test = ((atan(ultraback/ultraright))*180/3.14592654);
    if (ultraright<0 && ultraback>0) test+=360;
    else if (ultraright<0) test += 270;  
    else test += 90;  
    calc(speed,test);
    
  }
}
  
void returngoal(){
  float test;
  ultraback=ultraVals[0]-ultradist[0];
  ultraleft=ultraVals[1]-ultradist[1];
  if (abs(ultraleft)<5 && abs(ultraback)<5 ) {
    calc(0,0);
    motorout();
  }
  else{
    float test =((atan(ultraleft/ultraback))*180/3.14592654);  
    if (ultraleft<0 && ultraback>0) test+=180;
    else if (ultraleft<0) test +=0;  
    else test += 180;
    calc(correctspeed,test);
    anglecorrect();
    motorout();
  }
}

