int checkLight() {
  for (int i=0; i<9; i++){
    ldr[i] = analogRead(i);
    //Serial.print(ldr[i]);
    //Serial.print(" ");
    if (ldr[i]>lightThresh[i]){
      //Serial.println(i);
      return i+1;
    }
  }
  // Serial.println();
  return 0;
}
int goalLight() {
  for (int i=0; i<9; i++){
    ldr[i] = analogRead(i);
    //Serial.print(ldr[i]);
    //Serial.print(" ");
    if (ldr[i]<goalThresh[i]){
      
      return i+1;
    }
  }
  // Serial.println();
  return 0;
}



