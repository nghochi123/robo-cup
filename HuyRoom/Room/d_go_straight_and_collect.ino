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
      ultra();
      detectobs();
      if (ultra4 > 30){
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



  
