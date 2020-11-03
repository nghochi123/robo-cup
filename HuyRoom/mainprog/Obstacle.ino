void obstacle(){
  if(front < 9 && front > 1){ //if the front shit detect an obstacle
    on(0,0,0);
    delay(1000);
    nano();
    if(front < 10 && front > 1){ // check whether actually detect or not
      on(50,-150,-150); // move back to give space to turn
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
        if(tmpcount%4 == 0){
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
