void regspeed(){
   if ((ultraVals[1]<=50)||(ultraVals[3]<=50)){
      speed=slowspeed;

      }
    else{
      speed=maxspeed;
    }
  
  //Serial.println(speed);
}

void bounceback(){    
  float sum=0;
  int x=45;
  int y[4];
  int counter=0;
  bool chk=true;
  for (int i=0;i<4;i++){
    if ((ultraVals[i]<x)&&(ultraVals[i]>=10)){
      y[counter]=i;
      counter++;
      //Serial.print(i);
      //Serial.print(" ");
    }    
  }
  if (counter==0){
    calc(0,0);
    anglek=maxanglek;

  }
  
  else {
    
    for (int a=0;a<counter;a++){     
      
      sum+=y[a];
      
    }

    /*Serial.print(sum);
    Serial.print(" ");
    Serial.print(counter);
    Serial.println(" ");
    sum/=(counter);*/

    if (counter==2){
      if(ultraVals[2]<45) {
        if (ultraVals[1]<45) sum=1.5;
        else if (ultraVals[3]<50) sum=2.5;
      }
      else if (ultraVals[1]<45) {
        if(ultraVals[0]<45) sum=0.5;
        else if (ultraVals[3]<45) sum=2;
      }
      else if (ultraVals[3]<45) { //sense right and back
        sum=3.5;
      }
    }
    else if (counter==3) {
      if (ultraVals[2]<45) {
        if(ultraVals[1]<45) {
          if(ultraVals[3]<45) sum=2; //0,1,2; assume 0
          else if(ultraVals[0]<45) sum=3;  //0,1,3; assume 1
        }
      }
      else if (ultraVals[1]<45) sum=0; //1,2,3 assume 3
    }
    while(chk) {
      readNano();
      int b,counter2=0;
      for(b=0; b<counter; b++) {
        if(ultraVals[y[b]]>=45) {
          counter2++;
        }
      }
      if(counter2==1) {
        chk=false;
        continue;
      }
      calc(speed,sum*90);
      anglecorrect();
      
      //Serial.println(sum*90);
      motorout();
    }
    //Serial.println("done");
    
    
    
  }
  

}

void centralise(){
  int x;int y; int ultraside;int ultraback;
  if (frontstrength>=110){
    if(170-(ultraVals[1]+ultraVals[3])<=3){

      while ((abs(ultraVals[1]-85)>25)||(abs(ultraVals[3]-85)>25)){
         readNano();
         int x=abs(ultraVals[1]-85);
          int y=abs(ultraVals[3]-85);
         if (y>x){
           int ultraside=ultraVals[1]-85;
           int ultraback=ultraVals[0];
         }
         else{
           int ultraside=ultraVals[3]-85;
           int ultraback=ultraVals[0];
         }
         
         float test =((atan(ultraside/ultraback))*180/3.14592654);  
         calc(speed,test);
         motorout();
       
    }
    
  }
  }
}

  

