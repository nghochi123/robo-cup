//---------Detect Obstacle-------//

void detectedright(){
  on(150,-150,-150);
  on(0,0,0);
  claw(1500, 150);
  on(300,150,150);
  cmpsturn(0,85);
  on(1000,-150,-150);
  on(500,150,150);
  cmpsturn(1,85);
  on(1200,150,150);
  cmpsturn(0,85);
  on(1200,-150,-150);
  cmpsturn(1,85);
}
void detectedleft(){
  on(150,-150,-150);
  on(0,0,0);
  claw(1500, 150);
  on(200,150,150);
  cmpsturn(0,85);
  on(1000,-150,-150);
  on(700,150,150);
  cmpsturn(1,85);
  on(1500,150,150);
  cmpsturn(0,85);
  on(1800,-150,-150);
  cmpsturn(1,85); 
}

void detectobs() {  
    Serial2.write(10);
    while(Serial2.available() < 2);
    int ultra1 = Serial2.read();
    int ultra2 = Serial2.read();
    Serial.print(ultra1);
    Serial.print("   ");
    Serial.println(ultra2);
    if(ultra1 < 8 || ultra2 <8){
      if( abs(ultra1 - ultra2) >15 && abs(ultra1 - ultra2) < 150){
          if( ultra1 > ultra2){
            detectedright();
          }
          else{
            detectedleft();
          }
      }
    }
}

void ultra() {
  Serial2.write(10);
  while(Serial2.available() < 2);
   ultra1 = Serial2.read();
   ultra2 = Serial2.read();
  Serial3.write(1);
  while(Serial3.available()<3);
   ultra3 = Serial3.read();
   ultra4 = Serial3.read();
  int color = Serial3.read();
}

