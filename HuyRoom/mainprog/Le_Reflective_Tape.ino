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
  }
}

void lrreset(){
  if(digitalRead(49) == 1){
    on(1000,0,0);
    while(digitalRead(49) == 0){
      on(0,0,0);
    }
  }
}

