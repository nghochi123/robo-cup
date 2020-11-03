void linetrack(int straight){ //linetrack program, straight is speed moving straight, basically for ramp
  light[0] = analogRead(LDR_0);
  light[1] = analogRead(LDR_1);
  light[2] = analogRead(LDR_2);
  light[3] = analogRead(LDR_3);
  light[4] = analogRead(LDR_4);
  /*if(light[0] > thresh[0] && light[1] > thresh[1] && light[2] > thresh[2] && light[3] > thresh[3] && light[4] > thresh[4]){
    curTime = millis();
    if(curTime - prevTime > 1000){
      foundline = false;
      on(10, 0, 0);
      curTime = millis();
      prevTime = millis();
      while(curTime - prevTime <= 1000 && foundline == false){
        on(0, -30, 100);
        light[0] = analogRead(A0);
        if(light[0] < thresh[0]){
          foundline = true;
        }
        curTime = millis();
      }
      on(50, 0, 0);
      if(foundline == true){
        on(300, 0, 100);
        on(600, 100, 0);
        curTime = millis();
        prevTime = millis();
      }
      else{
        on(1000, 30, -100);
        on(50, 0, 0);
        curTime = millis();
        prevTime = millis();
        while(curTime - prevTime <= 1000 && foundline == false){
          on(0, 100, -30);
          light[4] = analogRead(A5);
          if(light[4] < thresh[4]){
            foundline = true;
          }
          curTime = millis();
        }
        on(50, 0, 0);
        if(foundline == true){
          on(500, 100, -30);
          on(1000, -30, 100);
          curTime = millis();
          prevTime = millis();
        }
        if(foundline == false){
          on(1000, -100, 30);
          curTime = millis();
          prevTime = millis();
        }
      }
    }
  }
  else{
    prevTime = millis();
  }*/
  if(light[0] < thresh[0] && light[4] > thresh[4] && light[3] > thresh[3]){
    if(light[0] < thresh2[0] && light[1] < thresh2[1] && light[2] < thresh2[2]){ // left 2 black && right 2 not black
      /*on(10, 0, 0);
      cmpsturn(0, 45);
      on(10, 0, 0);
      light[2] = analogRead(A2);
      while(light[2] > thresh2[2]){
        on(0, straight, straight);
        light[2] = analogRead(A2);
      }
      on(10, 0, 0);
      on(100, -straight, -straight);
      on(10, 0, 0);*/
      while(light[0] < thresh2[0]){
        on(0, straight, straight);
        light[0] = analogRead(LDR_0);
      }
      on(100, straight, straight);
      on(10, 0, 0);
      prevTime = millis();
      on(400, -170, 150); //Makes sure that it doesnt stop turning too quickly and continues turning eg. on a curve
      on(10, 0, 0);
      light[2] = analogRead(LDR_2);
      while((light[2] > thresh2[2]) && (millis() - prevTime < 1300)){ //Turn till middle is black
        on(0, -170, 150);
        light[2] = analogRead(LDR_2);
      }
      on(10, 0, 0);
    }
    else{ //Only left most is black, so just do a sharper turn instead of a 90-degree turn
      on(20, -200, 150);
    }
  }
  else if(light[4] < thresh [4] && light[0] > thresh[0] && light[1] > thresh[1]){
    if(light[4] < thresh2[4] && light[3] < thresh2[3] && light[2] < thresh2[2]){ //right two black and middle left black
      /*on(10, 0, 0);
      cmpsturn(1, 45);
      on(10, 0, 0);
      light[2] = analogRead(A2);
      while(light[2] > thresh2[2]){
        on(0, straight, straight);
        light[2] = analogRead(A2);
      }
      on(10, 0, 0);
      on(100, -straight, -straight);
      on(10, 0, 0);*/
      while(light[4] < thresh2[4]){
        on(0, straight, straight);
        light[4] = analogRead(LDR_4);
      }
      on(100, straight, straight); //Same as above
      on(10, 0, 0);
      prevTime = millis();
      on(400, 150, -170); //Same as above
      light[2] = analogRead(LDR_2);
      on(10, 0, 0);
      while(light[2] > thresh2[2] && (millis() - prevTime < 1300)){
        on(0, 150, -170);
        light[2] = analogRead(LDR_2);
      }
      on(10, 0, 0);
    }
    else{
      on(20, 150, -200);
    }
  }
  if(light[1] < thresh[1]){
    if(light[3] < thresh[3]){ //Middle two black, go straight
      on(0, straight, straight);
    }
    else{ //Middle left black
      on(0, -140, 120);
    }
  }
  else if(light[3] < thresh[3]){ //Middle right black
    on(0, 120, -140);
  }
  else{ //All white, go straight
    on(0, straight, straight);
  }
}

void green() {
  Wire.beginTransmission(COLOUR_ADDR);
  Wire.write(COLOUR_REG);
  Wire.endTransmission();
  Wire.requestFrom(COLOUR_ADDR, 1);
  nano();
  colour1 = Wire.read();
  left = colour1;
  right = colour2;
  if (left == 3 || left == 4) { //basically the retarded green program for mindstorms but in C. Right green 1 Left green 3/4
    on(100, 0, 0);
    Wire.beginTransmission(COLOUR_ADDR);
    Wire.write(COLOUR_REG);
    Wire.endTransmission();
    Wire.requestFrom(COLOUR_ADDR, 1);
    nano();
    colour1 = Wire.read();
    left = colour1;
    right = colour2;
    on(100, -100, -100);
    on(100, 0, 0);
    on(500, -150, 150);
    on(100, 0, 0);
    light[0] = analogRead(LDR_0);
    light[1] = analogRead(LDR_1);
    light[2] = analogRead(LDR_2);
    light[3] = analogRead(LDR_3);
    light[4] = analogRead(LDR_4);
    if (light[2] < thresh[2]){
      tublk(1);
    }
    else{
      on(500, 150, -150);
      on(100, 0, 0);
      on(100, 100, 100);
      on(100, 0, 0);
      if ((light[0] < thresh2[0] || light[4] < thresh2[0])){
        on(200, 100, 100);
      }
      else if ((left == 3 || left == 3) && (right == 3 || right == 4)) {
        cmpsturn(1, 135); // 180 turn
        light[2] = analogRead(LDR_2);
        while(light[2] > thresh2[2]){
          on(0, 150, -170);
          light[2] = analogRead(LDR_2);
        }
      }
      else if (left == 3 || left == 4){
        tublk(0);
      }
    }
  }
  else if (right == 3 || right == 4) {
    on(100, 0, 0);
    Wire.beginTransmission(COLOUR_ADDR);
    Wire.write(COLOUR_REG);
    Wire.endTransmission();
    Wire.requestFrom(COLOUR_ADDR, 1);
    nano();
    colour1 = Wire.read();
    left = colour1;
    right = colour2;
    on(100, -100, -100);
    on(100, 0, 0);
    on(500, 150, -150);
    on(100, 0, 0);
    light[0] = analogRead(LDR_0);
    light[1] = analogRead(LDR_1);
    light[2] = analogRead(LDR_2);
    light[3] = analogRead(LDR_3);
    light[4] = analogRead(LDR_4);
    if (light[2] < thresh[2]){
      tublk(0);
    }
    else{
      on(500, -150, 150);
      on(100, 0, 0);
      on(100, 100, 100);
      on(100, 0, 0);
      if ((light[0] < thresh2[0] || light[4] < thresh2[0])){
        on(200, 100, 100);
      }
      else if ((left == 3 || left == 4) && (right == 3 || right == 4)) {
        cmpsturn(1, 135); // 180 turn
        light[2] = analogRead(LDR_2);
        while(light[2] > thresh2[2]){
          on(0, 150, -170);
          light[2] = analogRead(LDR_2);
        }
      }
      else if (right == 3 || right == 4){
        tublk(1);
      }
    }
  }
  left = 0;
  right = 0;
}

void obstacle(){
  if(front < 9 && front > 1){ //if the front shit detect an obstacle
    on(100, 0, 0);
    nano();
    //nano2();
    if(front < 10 && front > 1){ // check whether actually detect or not
      //on(50,-150,-150); // move back to give space to turn
      while(side > 10){ //turn until side ultra detects obstacle to prepare for obstacle tracing
        nano(); //read ultra constantly
        on(0, -130, 150);
      }
      on(200, -130, 150);
      on(1000,0,0);
      light[3] = analogRead(LDR_3);
      light[4] = analogRead(LDR_4);
      tmpcount = 0;
      while((light[3] > thresh2[3]) && (light[4] > thresh2[4])){ //obstacle track until condition in while loop fufilled
        //nano();
        if(tmpcount%5 == 0){
          on(100, 0, 120);
        }
        else{
          on(100, 255, -30);
        }
        light[3] = analogRead(LDR_3);
        light[4] = analogRead(LDR_4);
        tmpcount += 1;
      }
      on(100, 0, 0);
      light[2] = analogRead(LDR_2);
      while(light[2] > thresh2[2]){
        on(0, 100, -100);
        light[2] = analogRead(LDR_2);
      }
    }
  }
}

void rampchk(){
  actualdeg();
  if(nowramp < -23){ //at bottom of ramp going up
    claw(0,60);
    on(500,150,150);
    on(1000,0,0);
    linetrack(150);
    delay(1000);
    while(nowramp < -23){ //going towards top of ramp
      claw(0,60);
      actualdeg();

      linetrack(150);  
    }
    on(1000,0,0);// at top of ramp, stopping
    actualdeg();
    while(abs(nowramp) < 10){ //while it is still at the top of the ramp
      claw(0,-60);
      actualdeg();
      linetrack(70);
    }
    on(1000,0,0);
    actualdeg();
    while(nowramp > 23){ // going out of ramp
      claw(0,60);
      actualdeg();
      on(0,10,10);
    }
    claw(0,60);
    delay(1000);
    on(500,0,0);
  }   
}

void rampinit(){ //initialise ramp saving natural pitch
    Wire.begin();
    Wire.beginTransmission(CMPS11_ADDRESS);  //starts communication with CMPS11
    Wire.write(4);                     //Sends the register we wish to start reading from
    Wire.endTransmission();
    
    Wire.requestFrom(CMPS11_ADDRESS, 4);       
    
    while(Wire.available() < 1);        // Wait for all bytes to come back
    pitch = Wire.read();
    rampint = pitch,DEC;
}

void actualdeg(){ //calculating actual pitch based on offset
    Wire.beginTransmission(CMPS11_ADDRESS);  //starts communication with CMPS11
    Wire.write(4);                     //Sends the register we wish to start reading from
    Wire.endTransmission();
    
    Wire.requestFrom(CMPS11_ADDRESS, 4);       
    
    while(Wire.available() < 1);        // Wait for all bytes to come back
    pitch = Wire.read();
    actualramp = pitch,DEC;
    nowramp = actualramp - rampint;      
}

void tublk(int dirx){ //0 is left 1 is right; is without move forward
  if(dirx == 0){
    //on(200, 100, 100);
    light[0] = analogRead(LDR_0);
    while(light[0] > thresh2[0]){
      on(0, 100, 100);
      light[0] = analogRead(LDR_0);
    }
    while(light[0] < thresh[0]){
      on(0, 100, 100);
      light[0] = analogRead(LDR_0);
    }
    //on(25, 100, 100);
    on(10, 0, 0);
    on(700, -170, 150);
    on(10, 0, 0);
    light[2] = analogRead(LDR_2);
    while(light[2] > thresh2[2]){ //Turn till middle is black
      on(0, -150, 150);
      light[2] = analogRead(LDR_2);
    }
    on(10, 0, 0);
  }
  else if(dirx == 1){
    //on(200, 100, 100);
    light[4] = analogRead(LDR_4);
    while(light[4] > thresh2[4]){
      on(0, 100, 100);
      light[4] = analogRead(LDR_4);
    }
    while(light[4] < thresh[4]){
      on(0, 100, 100);
      light[4] = analogRead(LDR_4);
    }
    //on(25, 100, 100);
    on(10, 0, 0);
    on(700, 150, -170);
    on(10, 0, 0);
    light[2] = analogRead(LDR_2);
    while(light[2] > thresh2[2]){
      on(0, 150, -150);
      light[2] = analogRead(LDR_2);
    }
    on(10, 0, 0);
  }
  on(200, 100, 100);
}
