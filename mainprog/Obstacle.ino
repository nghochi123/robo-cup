void obstacle(){
  if(front < 15 && front > 2){
    on(100,-150,-150);
    on(0,0,0);
    while(side > 15){
      nano();
      on(0,-130,150);
    }
    on(1000, 0, 0);
    //move forward while turning left depending on distance from obstacle
    cmpsinit();
    while(actualangle < 180 || actualangle > 345){ //replace this with something else
      nano();
      cmpsdeg();
      if (side < 15 && side > 5){
        on(0, 150, -130);
      }
      else{
        on(0,150,150);
      }
    }
    //stop when light sensor detect black
    //turn left then move back
  }
}

