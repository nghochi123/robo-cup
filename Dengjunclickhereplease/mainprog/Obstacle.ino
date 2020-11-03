void obstacle(){
  if(front < 9 && front > 1){ //if the front shit detect an obstacle
    on(0,0,0);
    delay(1000);
    nano();
    if(front < 10 && front > 1){ // check whether actually detect or not
      on(100,-150,-150); // move back to give space to turn
      while(side > 10){ //turn until side ultra detects obstacle to prepare for obstacle tracing
        nano(); //read ultra constantly
        on(0, -130, 150);
      }
      on(1000,0,0);
      while(0 == 0){ //obstacle track until condition in while loop fufilled
        nano();
        if(side > 16){ //proportional tracking
          side = 16;
        }
        int p = 12*(side - 6);
        on(0, 80+p, 80-p);
      }
    }
  }
}
