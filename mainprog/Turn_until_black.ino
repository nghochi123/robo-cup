void tublk(int dirx){ //0 is left 1 is right; is without move forward
  if(dirx == 0){
    on(500, -140, 120);
    light[2] = analogRead(A2);
    while(light[2] > thresh2[2]){ //Turn till middle is black
      on(0, -140, 120);
      light[2] = analogRead(A2);
    }
    while(light[2] < thresh[2]){
      on(0, 120, 120);
      light[2] = analogRead(A2);
    }
    on(200, 90, 90);
    on(10, 0, 0);
    light[2] = analogRead(A2);
    while(light[2] > thresh2[2]){
      on(0, -150, 120);
      light[2] = analogRead(A2);
    }
    on(200, 90, 90);
  }
  else if(dirx == 1){
    on(500, 120, -140);
    light[2] = analogRead(A2);
    while(light[2] > thresh2[2]){
      on(0, 120, -140);
      light[2] = analogRead(A2);
    }
    on(10, 0, 0);
    while(light[2] < thresh[2]){
      on(0, 120, 120);
      light[2] = analogRead(A2);
    }
    on(200, 120, 120);
    on(10, 0, 0);
    light[2] = analogRead(A2);
    while(light[2] > thresh2[2]){
      on(0, 120, -150);
      light[2] = analogRead(A2);
    }
  }
  on(200, 90, 90);
}

