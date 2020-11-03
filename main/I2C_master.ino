void readNano() {
  int readVal;
  Serial2.write(1);
  while (Serial2.available()<6);
  backangle=Serial2.read();
  backstrength=Serial2.read();
  for (int i=0; i<4; i++) {
    readVal = Serial2.read();
    if (readVal!=0) ultraVals[i] = readVal;
  }
 
  
  
}
