void green() {
  Wire.beginTransmission(COLOUR_ADDR);
  Wire.write(COLOUR_REG);
  Wire.endTransmission();
  Wire.requestFrom(COLOUR_ADDR, 1);
  nano();
  colour1 = Wire.read();
  left = colour1;
  right = colour2;
  if (left == 3 || left == 4) { //basically the retarded green program for mindstorms but in C. Right green 1 Left green 3/4
    on(100, 60, 60);
    on(100,0,0);
    light[0] = analogRead(LDR_0);
    light[1] = analogRead(LDR_1);
    light[2] = analogRead(LDR_2);
    light[3] = analogRead(LDR_3);
    light[4] = analogRead(LDR_4);
    Wire.beginTransmission(COLOUR_ADDR);
    Wire.write(COLOUR_REG);
    Wire.endTransmission();
    Wire.requestFrom(COLOUR_ADDR, 1);
    nano();
    colour1 = Wire.read();
    left = colour1;
    right = colour2;
    if ((light[0] < thresh2[0] || light[4] < thresh2[0])){
      on(400, 100, 100);
    }
    else if (right == 3 || right == 4) {
      cmpsturn(1, 135); // 180 turn
      light[2] = analogRead(LDR_2);
      while(light[2] > thresh2[2]){
        on(0, 150, -170);
        light[2] = analogRead(LDR_2);
      }
    }
    else{
      tublk(0);
    }
    left = 0;
    right = 0;
  }
  else if (right == 3 || right == 4) {
    on(100, 60, 60);
    on(100,0,0);
    light[0] = analogRead(LDR_0);
    light[1] = analogRead(LDR_1);
    light[2] = analogRead(LDR_2);
    light[3] = analogRead(LDR_3);
    light[4] = analogRead(LDR_4);
    Wire.beginTransmission(COLOUR_ADDR);
    Wire.write(COLOUR_REG);
    Wire.endTransmission();
    Wire.requestFrom(COLOUR_ADDR, 1);
    nano();
    colour1 = Wire.read();
    left = colour1;
    right = colour2;
    if ((light[0] < thresh2[0] || light[4] < thresh2[0])){
      on(400, 100, 100);
    }
    else if ((left == 3 || left == 4)) {
      cmpsturn(1, 135); // 180 turn
      light[2] = analogRead(LDR_2);
      while(light[2] > thresh2[2]){
        on(0, 150, -170);
        light[2] = analogRead(LDR_2);
      }
    }
    else{
      tublk(1);
    }
    left = 0;
    right = 0;
  }
}
