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
    if(light[0] < thresh[0] && light[1] < thresh2[1] && light[2] < thresh2[2]){ // left 2 black && right 2 not black
      while(light[0] < thresh2[0]){
        on(0, straight, straight);
        light[0] = analogRead(LDR_0);
      }
      on(50, straight, straight);
      on(100, 0, 0);
      light[2] = analogRead(LDR_2);
      /*if(light[2] < thresh2[2]){
        on(100, straight, straight);
      }
      else{*/
      prevTime = millis();
      on(400, -170, 150); //Makes sure that it doesnt stop turning too quickly and continues turning eg. on a curve
      on(10, 0, 0);
      light[2] = analogRead(LDR_2);
      while((light[2] > thresh[2]) && (millis() - prevTime < 1300)){ //Turn till middle is black
        on(0, -170, 150);
        light[2] = analogRead(LDR_2);
      }
      on(10, 0, 0);
      //on(100, -straight, -straight);
    }
    else{ //Only left most is black, so just do a sharper turn instead of a 90-degree turn
      on(20, -200, 120);
    }
  }
  else if(light[4] < thresh [4] && light[0] > thresh[0] && light[1] > thresh[1]){
    if(light[4] < thresh[4] && light[3] < thresh2[3] && light[2] < thresh2[2]){ //right two black and middle left black
      while(light[4] < thresh2[4]){
        on(0, straight, straight);
        light[4] = analogRead(LDR_4);
      }
      on(25, straight, straight); //Same as above
      on(100, 0, 0);
      light[2] = analogRead(LDR_2);
      /*if(light[2] < thresh2[2]){
        on(100, straight, straight);
      }
      else{*/
      prevTime = millis();
      on(400, 150, -170); //Same as above
      light[2] = analogRead(LDR_2);
      on(10, 0, 0);
      while(light[2] > thresh[2] && (millis() - prevTime < 1300)){
        on(0, 150, -170);
        light[2] = analogRead(LDR_2);
      }
      on(10, 0, 0);
      //on(100, -straight, -straight);
    }
    else{
      on(20, 120, -200);
    }
  }
  if(light[1] < thresh[1]){
    if(light[3] < thresh[3]){ //Middle two black, go straight
      on(0, straight, straight);
    }
    else{ //Middle left black
      on(0, -160, 120);
    }
  }
  else if(light[3] < thresh[3]){ //Middle right black
    on(0, 120, -160);
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
    on(50, -80, -80);
    on(100, 0, 0);
    Wire.beginTransmission(COLOUR_ADDR);
    Wire.write(COLOUR_REG);
    Wire.endTransmission();
    Wire.requestFrom(COLOUR_ADDR, 1);
    nano();
    colour1 = Wire.read();
    left = colour1;
    right = colour2;
    //on(75, 100, 100);
    //on(100, 0, 0);
    light[0] = analogRead(LDR_0);
    light[1] = analogRead(LDR_1);
    light[2] = analogRead(LDR_2);
    light[3] = analogRead(LDR_3);
    light[4] = analogRead(LDR_4);
    on(100, 0, 0);
    if (light[0] < thresh[0] || light[4] < thresh[4]){
      on(400, 100, 100);
    }
    else if ((left == 3 || left == 4) && (right == 3 || right == 4)){
      on(1800, 120, -110);
      light[2] = analogRead(LDR_2);
      while(light[2] > thresh2[2] || light[3] > thresh2[3]){
        on(0, 120, -110);
        light[2] = analogRead(LDR_2);
        light[3] = analogRead(LDR_3);
      }
      on(100, -100, -100);
      /*on(200, 80, 80);
      light[2] = analogRead(LDR_2);
      while(light[2] > thresh2[2]){
        on(0, -150, 150);
        light[2] = analogRead(LDR_2);
      }*/
    }
    else if(left == 3 || left == 4){
      //on(75, -100, -100);
      //on(100, 0, 0);
      /*on(100, -100, -100);
      on(100, 0, 0);
      det = false;
      on(400, -150, 150);
      greenTime = millis();
      light[2] = analogRead(A2);
      if(light[2] < thresh2[2]){
        det = true;
      }
      while(millis() - greenTime < 200){
        on(0, -150, 150);
        light[2] = analogRead(A2);
        if(light[2] < thresh2[2]){
          det = true;
        }
      }
      on(100, 0, 0);
      on(600, 150, -150);
      on(100, 0, 0);
      if(det == true){
        tublk(1);
      }
      else{
        tublk(0);
      }*/
      tublk(0);
    }
  }
  else if (right == 3 || right == 4) {
    on(100, 0, 0);
    on(50, -80, -80);
    on(100, 0, 0);
    Wire.beginTransmission(COLOUR_ADDR);
    Wire.write(COLOUR_REG);
    Wire.endTransmission();
    Wire.requestFrom(COLOUR_ADDR, 1);
    nano();
    colour1 = Wire.read();
    left = colour1;
    right = colour2;
    //on(75, 100, 100);
    //on(100, 0, 0);
    light[0] = analogRead(LDR_0);
    light[1] = analogRead(LDR_1);
    light[2] = analogRead(LDR_2);
    light[3] = analogRead(LDR_3);
    light[4] = analogRead(LDR_4);
    on(100, 0, 0);
    if (light[0] < thresh[0] || light[4] < thresh[4]){
      on(400, 100, 100);
    }
    else if ((left == 3 || left == 4) && (right == 3 || right == 4)){
      on(1800, 120, -110);
      light[2] = analogRead(LDR_2);
      while(light[2] > thresh[2] || light[3] > thresh[3]){
        on(0, 120, -110);
        light[2] = analogRead(LDR_2);
        light[3] = analogRead(LDR_3);
      }
      on(100, -100, -100);
      //on(150, 80, 80);
      /*on(200, 80, 80);
      light[2] = analogRead(LDR_2);
      while(light[2] > thresh2[2]){
        on(0, -150, 150);
        light[2] = analogRead(LDR_2);
      }*/
    }
    else if(right == 3 || right == 4){
      //on(75, -100, -100);
      //on(100, 0, 0);
      /*on(100, -100, -100);
      on(100, 0, 0);
      det = false;
      on(400, 150, -150);
      greenTime = millis();
      light[2] = analogRead(A2);
      if(light[2] < thresh2[2]){
        det = true;
      }
      while(millis() - greenTime < 200){
        on(0, 150, -150);
        light[2] = analogRead(A2);
        if(light[2] < thresh2[2]){
          det = true;
        }
      }
      on(100, 0, 0);
      on(600, -150, 150);
      on(100, 0, 0);
      if(det == true){
        tublk(0);
      }
      else{
        tublk(1);
      }*/
      tublk(1);
    }
  }
}


void obstacle(){
  if(front < 9 && front > 1){ //if the front shit detect an obstacle
    on(100, 0, 0);
    nano();
    if(front < 9 && front > 1){
      /*on(100, -100, -100);
      on(100, 0, 0);
      on(1100, -200, 200);
      on(100, 0, 0);
      on(850, 100, 100);
      on(100, 0, 0);
      on(1100, 200, -200);
      on(100, 0, 0);
      on(1900, 100, 100);
      on(100, 0, 0);
      on(1100, 200, -200);
      on(100, 0, 0);
      on(850, 100, 100);
      on(100, 0, 0);
      on(1100, -200, 200);
      on(100, 0, 0);
      light[2] = analogRead(LDR_2);
      while(light[2] > thresh2[2]){
        on(0, -100, -100);
        light[2] = analogRead(LDR_2);
      }
      on(100, -100, -100);
      on(100, 0, 0);
      on(1100, 200, -200);
      on(100, 0, 0);
      on(850, 100, 100);
      on(100, 0, 0);
      on(1100, -200, 200);
      on(100, 0, 0);
      on(1900, 100, 100);
      on(100, 0, 0);
      on(1100, -200, 200);
      on(100, 0, 0);
      on(850, 100, 100);
      on(100, 0, 0);
      on(1100, 200, -200);
      on(100, 0, 0);
      light[2] = analogRead(LDR_2);
      while(light[2] > thresh2[2]){
        on(0, -100, -100);
        light[2] = analogRead(LDR_2);
      }*/
      /*light[3] = analogRead(LDR_3);
      light[4] = analogRead(LDR_4);
      while(light[3] > thresh2[3] || light[4] > thresh2[3]){
        on(0, 100, 100);
        light[3] = analogRead(LDR_3);
        light[4] = analogRead(LDR_4);
      }
      on(200, 100, 100);
      on(100, 0, 0);
      on(600, -150, 150);
      light[2] = analogRead(LDR_2);
      while(light[2] > thresh2[2]){
        on(0, -150, 150);
        light[2] = analogRead(LDR_2);
      }*/
      while(side > 10 || side == 0){
        nano();
        on(0,-130,150);
      }
    /*on(800, 100, 100);
    on(100, 0, 0);
    nano();
    if(side > 12){ //if there is no wall
      on(800, -100, -100);*/
      on(100,0,0);
      light[3] = analogRead(LDR_3);
      light[4] = analogRead(LDR_4);
      tmpcount = 0;
      obsTime = millis();
      while(millis() - obsTime < 2000){
        if(tmpcount%5 == 0){
          on(100, 0, 120);
        }
        else{
          on(100, 255, -30);
        }
        tmpcount += 1;
      }
      //on(1000, 0, 0);
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
    /*else if(side <= 12){ //if there is a wall
      on(800, -100, -100);
      on(800, 130, -150);
      prevTime = millis();
      while(millis() - prevTime < 10000){
        linetrack(80);
        claw(0,60);
        green();
      }
    }*/
  }
}

void rampchk(){
  actualdeg();
  if(nowramp < -15){ //at bottom of ramp going up
    claw(0,60);
    rampTime = millis();
    while(millis() - rampTime < 1000){
      claw(0,60);
      ramptrack(150);
    }
    while(nowramp < -15){ //going towards top of ramp
      claw(0,60);
      actualdeg();
      Serial.println(nowramp);
      ramptrack(150);
    }
    rampTime = millis();
    while(millis() - rampTime < 100){
      claw(0,60);
      linetrack(150);
    }
    on(1000,0,0);// at top of ramp, stopping
    //on(700, -80, -80);
    on(300, -80, -80);
    on(100, 0, 0);
    actualdeg();
    while(abs(nowramp) < 10){ //while it is still at the top of the ramp
      claw(0,60);
      actualdeg();
      Serial.println(nowramp);
      linetrack(60);
      green();
    }
  }
  else if(nowramp > 15){
    while(nowramp > 15){
      on(0, 50, 50);
      green();
      actualdeg();
      claw(0,60);
    }   
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
    Serial.println(nowramp);
}

void tublk(int dirx){ //0 is left 1 is right; is without move forward
  on(325, 100, 100);
  if(dirx == 0){
    /*light[0] = analogRead(LDR_0);
    while(light[0] > thresh2[0]){
      on(0, 100, 100);
      light[0] = analogRead(LDR_0);
    }
    while(light[0] < thresh[0]){
      on(0, 100, 100);
      light[0] = analogRead(LDR_0);
    }*/
    //on(50, 100, 100);
    //on(10, 0, 0);
    on(1000, -170, 150);
    on(10, 0, 0);
    light[2] = analogRead(LDR_2);
    while(light[2] > thresh[2]){ //Turn till middle is black
      on(0, -170, 150);
      light[2] = analogRead(LDR_2);
    }
    on(10, 0, 0);
  }
  else if(dirx == 1){
   /* light[4] = analogRead(LDR_4);
    while(light[4] > thresh2[4]){
      on(0, 100, 100);
      light[4] = analogRead(LDR_4);
    }
    while(light[4] < thresh[4]){
      on(0, 100, 100);
      light[4] = analogRead(LDR_4);
    }*/
    //on(25, 100, 100);
    on(10, 0, 0);
    on(1000, 150, -170);
    on(10, 0, 0);
    light[2] = analogRead(LDR_2);
    while(light[2] > thresh[2]){
      on(0, 150, -170);
      light[2] = analogRead(LDR_2);
    }
    on(10, 0, 0);
  }
  on(200, 80, 80);
  greenTime = millis();
  while(millis() - greenTime < 1000){
    tape();
    linetrack(80);
    claw(0,60);
    rampchk();
  }
}

void ramptrack(int straight){
  if(light[1] < rampthresh[1]){
    if(light[3] < rampthresh[3]){ //Middle two black, go straight
      on(0, straight, straight);
    }
    else{ //Middle left black
      on(0, -100, 100);
    }
  }
  else if(light[3] < rampthresh[3]){ //Middle right black
    on(0, 100, -100);
  }
  else{ //All white, go straight
    on(0, straight, straight);
  }
}

