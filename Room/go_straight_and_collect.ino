void edge() {
  edgetimer = millis();
  while ( millis() - edgetimer <= 3000){ // run along edge for 3 secs or touched
    touch = digitalRead(Touch45);
    if (touch == 1){
      break;
    }
    else{
      on(0,95,100);
    }
    
  }
    
}

void touched(){
  cmpsturn(0,45);
  touch = 0;
  touchedtimer = millis();
  while ( millis() - touchedtimer <= 2000){
    touch = digitalRead(Touch45);
    if (touch == 1){
      cmpsturn(0,45);
      break;
    }
    else{
      on(1000,70,70);
    }
  }

}

void corner(){
  claw(0,-50);
  if (touch == 1){
    touched();
  }
  else
  {
    on(2200,-80,-80);
    on(0,0,0);
    claw(1500,100);
    cmpsturn(0,75);

  }
}

void dumpcorner(){
  if (touch == 1){
  dumptouched();
  }
  else
  {
    on(200,-100,-100);
    on(200,0,0);
    claw(1500, 100);
  }
}

void dumptouched(){
  cmpsturn(0,45);
  on(500,1000,1000);
  cmpsturn(0,90);
  on(500,1000,1000);
  on(10,0,0);
  alive();
  
  on(100,100,100);
  cmpsturn(1,90);
  
  touch = 0;
  touchedtimer = millis();
  while ( millis() - touchedtimer <= 1000){
   touch = digitalRead(Touch45);
    if (touch == 1){
      cmpsturn(0,45);
      break;
    }
    else{
      on(1000,70,70);
    }
  }

}

  
