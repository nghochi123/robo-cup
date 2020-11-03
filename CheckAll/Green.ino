void greenc(){
  Wire.beginTransmission(COLOUR_ADDR);
  Wire.write(COLOUR_REG);
  Wire.endTransmission();
  Wire.requestFrom(COLOUR_ADDR, 1);
  nano();
  colour1 = Wire.read();
  left = colour1;
  right = colour2;
  if (left == 3 || left == 4) { //basically the retarded green program for mindstorms but in C. Right green 1 Left green 3/4
    on(100, 0, 0);
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
}
}
