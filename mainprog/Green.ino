void green() {
  Wire.beginTransmission(COLOUR_ADDR);
  Wire.write(COLOUR_REG);
  Wire.endTransmission();
  Wire.requestFrom(COLOUR_ADDR, 1);
  colour1 = Wire.read();
  left = colour1;
  right = colour2;
    if (left == 3 || left == 4) { //basically the retarded green program for mindstorms but in C. Right green 1 Left green 3/4
      on(100, 0, 0);
      if (right == 3 || right == 4) {
        cmpsturn(1, 180); // 180 turn
      }
      else{
        on(200, 90, 90);
        on(10, 0, 0);
        tublk(0);
      }
      left = 0;
      right = 0;
    }
    else if (right == 3 || right == 4) {
      on(100, 0, 0);
      if ((left == 3 || left == 4)) {
        cmpsturn(1, 180); // 180 turn
      }
      else{
        on(200, 90, 90);
        on(10, 0, 0);
        tublk(1);
      }
      left = 0;
      right = 0;
    }
  }
