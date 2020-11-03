//reflective tape
void tape(){
  Serial.print("Reflective Tape: ");
  if(light[1] > white [1]+10 || light[2] > white[2]+10 || light[3] > white[3]+10){
    Serial.println("YES");
  }
  else{
    Serial.println("NO");
  }
}

void LDR(){
  Serial.print("Light Array");
  for(int i = 0; i < 4; i++){
    Serial.print(i);
    Serial.print(": ");
    Serial.println(light[i]);
  }
}

void ULTRAS(){
  Serial.print("Front: ");
  Serial.print(front);
  Serial.print("     ");
  Serial.print("Side: ");
  Serial.print(side);
  Serial.print("     ");
  Serial.print("Above: ");
  Serial.print(above);
  Serial.print("     ");
  Serial.print("Front Array: ");
  Serial.print("1: ");
  Serial.print(ultra1);
  Serial.print("  2: ");
  Serial.println(ultra2);
}

void GREEN(){
  greenc();
  Serial.print("Right: ");
  Serial.print(right);
  Serial.print("    ");
  Serial.print("Left: ");
  Serial.println(left);
}

void MOTORS(){
  on(1000,50,50);
  claw(50);
  delay(1000);
  claw(50);
  delay(1000);
  on(1000,-50,-50);
  
}

