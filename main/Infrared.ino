float readfrontangle() {
  Wire.beginTransmission(0x02); //frontangle
  Wire.write(8);
  Wire.endTransmission();
  Wire.requestFrom(0x02,2);
  while (Wire.available() < 1);
  return Wire.read();
}

int readfrontstrength() {
  Wire.beginTransmission(0x02); //frontstrength
  Wire.write(9);
  Wire.endTransmission();
  Wire.requestFrom(0x02,1); 
  while (Wire.available() < 1);
  return Wire.read();
}


int irstrength(int index){
  Wire.beginTransmission(0x02); //frontstrength
  Wire.write(index);
  Wire.endTransmission();
  Wire.requestFrom(0x02,1); 
  while (Wire.available() < 1);
  return Wire.read();
}

void processir(){
  
  
  if (frontstrength>backangle){
    maxstrength=0;
    for (int i=0;i<7;i++){
    irVals[i]=(irstrength(indexir[i]));
  }
    for (int g=0;g<7;g++){
      if (irVals[g]==frontstrength) irVals[g]=0;
      if (irVals[g]>maxstrength){
            maxstrength=irVals[g];
            IRchannel=g+1;
        }
      }
      
      }
      irpercenta=(maxstrength/(frontstrength+maxstrength));
    irpercentb=(frontstrength/(frontstrength+maxstrength));
    IRchannel*=irpercenta;
    ballangle=(frontangle*irpercentb)+IRchannel;
    ballangle-=4;
    IRmultiplier=(frontstrength/145)+1;  
  }
  
    

void track(){
  if (frontstrength>backstrength) {
    ballangle=ballangle*30*IRmultiplier;
    if (ballangle<0) {
     ballangle+=360;
    }
    ballangle-=5;
     calc(speed, ballangle);
  }
  else {   
    /*backangle=backangle*30+60;     

   
    if (backangle>=180){
      backangle-=backstrength*0.6;
    }
    else {
      backangle+=backstrength*0.6;
      
    }
   calc(speed, backangle);
  }*/
  calc(0,0);
  }
}
 
