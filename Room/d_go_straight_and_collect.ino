void edge() {
  sersweep.write(110);
  
  edgetimer = millis();
  while ( millis() - edgetimer <= 5000){ // run along edge for 3 secs or touched
    touch = digitalRead(Touch45);
    if (touch == 1){
      break;
    }
    else{
      on(0,100,70);
    }
    
  }
    
}

void touched(){
  on(50,-100,-100);
  cmpsturncorner(0,40);
  touchtimer = millis();
  on(1000,100,100);
  on(50,-100,-100);
  cmpsturncorner(0,40);
}



void corner(){
  if (touch == 1){
    touched();
  }
  else
  {
    on(230,-100,-100);
    on(0,0,0);
    claw(1500,100);
    on(200,-100,-100);
    cmpsturncorner(0, 75);
    on(200,100,100);
    on(200,-100,-100);
    on(1000,-100,-100);

  }
}

void dumptouched(){
  on(100,-100,-100);
  cmpsturncorner(0,40);
  on(300,100,100);
  cmpsturn(0,70);
  on(2000,-100,-100);
  alive();
  on(100,100,100);
  cmpsturn(1,70);
  
  touch = 0;
  touchtimer = millis();
  while ( millis() - touchtimer <= 1000){
    on(0,100,100);
  }

}

void dumpcorner(){
  if (touch == 1){
    dumptouched();
  }
  else
  {
    on(210,-100,-100);
    on(0,0,0);
    claw(1500,100);
    on(200,-100,-100);
    cmpsturncorner(0, 75);
    on(150,100,100);
    on(150,-100,-100);
    on(1000,-100,-100);
}
}



  
