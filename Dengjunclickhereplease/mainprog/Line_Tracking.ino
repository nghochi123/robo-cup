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
    if(light [0] < thresh2[0] && light[1] < thresh2[1] && light[2] < thresh2[2]){ // left 2 black && right 2 not black
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
      on(10, 0, 0);
      on(100, straight, straight);
      on(10, 0, 0);
      prevTime = millis();
      on(400, -170, 150); //Makes sure that it doesnt stop turning too quickly and continues turning eg. on a curve
      on(10, 0, 0);
      light[2] = analogRead(LDR_2);
      while((light[2] > thresh2[2]) && (millis() - prevTime < 1000)){ //Turn till middle is black
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
      on(10, 0, 0);
      on(100, straight, straight); //Same as above
      on(10, 0, 0);
      prevTime = millis();
      on(400, 150, -170); //Same as above
      light[2] = analogRead(LDR_2);
      on(10, 0, 0);
      while(light[2] > thresh2[2] && (millis() - prevTime < 1000)){
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
