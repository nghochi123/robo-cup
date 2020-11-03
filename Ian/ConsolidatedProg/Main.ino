void loop(){
  tape();
  obstacle();
  linetrack(80);
  claw(0,60);
  green();
  rampchk();
  //include last room program in tape();//
  ltreset();
  /*Serial.print(front);
  Serial.print(" ");
  Serial.println(side);*/
}

