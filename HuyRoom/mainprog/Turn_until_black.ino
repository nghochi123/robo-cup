void tublk(int dirx){ //0 is left 1 is right; is without move forward
  on(200, 100, 100);
  if(dirx == 0){
    light[0] = analogRead(LDR_0);
    while(light[0] > thresh2[0]){
      on(0, 100, 100);
      light[0] = analogRead(LDR_0);
    }
    while(light[0] < thresh[0]){
      on(0, 100, 100);
      light[0] = analogRead(LDR_0);
    }
    on(25, 100, 100);
    on(10, 0, 0);
    on(600, -170, 150);
    on(10, 0, 0);
    light[2] = analogRead(LDR_2);
    while(light[2] > thresh2[2]){ //Turn till middle is black
      on(0, -150, 150);
      light[2] = analogRead(LDR_2);
    }
    on(10, 0, 0);
  }
  else if(dirx == 1){
    light[4] = analogRead(LDR_4);
    while(light[4] > thresh2[4]){
      on(0, 100, 100);
      light[4] = analogRead(LDR_4);
    }
    while(light[4] < thresh[4]){
      on(0, 100, 100);
      light[4] = analogRead(LDR_4);
    }
    on(25, 100, 100);
    on(10, 0, 0);
    on(600, 150, -170);
    on(10, 0, 0);
    light[2] = analogRead(LDR_2);
    while(light[2] > thresh2[2]){
      on(0, 150, -150);
      light[2] = analogRead(LDR_2);
    }
    on(10, 0, 0);
  }
  on(300, 100, 100);
}
