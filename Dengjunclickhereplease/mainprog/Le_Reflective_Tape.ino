void tape(){
  if(light[1] > white [1]+10 || light[2] > white[2]+10 || light[3] > white[3]+10){
    on(1000,0,0);
    if(light[1] > white [1]+10 || light[2] > white[2]+10 || light[3] > white[3]+10){
      on(10000,0,0);
    }
  }
}

