void nano(){
  Serial3.write(1);
  while(Serial3.available() < 4);
  front = Serial3.read();
  int temp = Serial3.read();
  if(temp != 0){
    side = temp;
  }
  colour2 = Serial3.read();
  above = Serial3.read();
}

void nano2(){
  Serial2.write(1);
  while(Serial2.available() < 3);
  time = Serial2.read();
  ultra1 = Serial2.read();
  ultra2 = Serial2.read();
}



