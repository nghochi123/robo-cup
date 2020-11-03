void tublk(int dirx){ //0 is left 1 is right; is without move forward
  on(400, 100, 100);
  on(10, 0, 0);
  if(dirx == 0){
    on(500, -150, 150);
    on(10, 0, 0);
    light[2] = analogRead(LDR_2);
    while(light[2] > thresh2[2]){ //Turn till middle is black
      on(0, -150, 150);
      light[2] = analogRead(LDR_2);
    }
    on(10, 0, 0);
  }
  else if(dirx == 1){
    on(500, 150, -150);
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
