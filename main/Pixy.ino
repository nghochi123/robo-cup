void centregoal(){
  
  static int i = 0;
  int j;
  uint16_t blocks;
  char buf[32]; 
  
  blocks = pixy.getBlocks();
  if (blocks){
    goalwidth=0;
    goalfound=millis();
    for (int i=0;i<blocks;i++){
      if (pixy.blocks[i].width>=goalwidth){
        goalwidth=pixy.blocks[i].width;
        goalindex=i;
      }
    }
    goalx=pixy.blocks[goalindex].x;
    
      goalerror=goalx-160;
      goaloffset=goalerror;
      compassoffset-=goaloffset*0.5 ;
        }
  else {
    if ((millis()-goalfound)>100) {
      compassoffset=originaloffset;
    }  
  }
}

