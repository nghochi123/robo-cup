void on(int wait,int lpwr,int rpwr){ //36/37:left 38/39:claw 40/41:right
  /*lpwr = min(max(lpwr,-150),150);
  rpwr = min(max(rpwr,-150),150);*/
  if(lpwr > 0){
      digitalWrite(36,LOW); 
      digitalWrite(37,HIGH);
    }
  else{
      digitalWrite(36,HIGH);
      digitalWrite(37,LOW);
      lpwr = abs(lpwr);    
    }
  if(rpwr > 0){
      digitalWrite(40,LOW);
      digitalWrite(41,HIGH); 
    }
  else{
      digitalWrite(40,HIGH);
      digitalWrite(41,LOW);
      rpwr = abs(rpwr);
    }
  analogWrite(5,lpwr);
  analogWrite(7,rpwr);
  if(wait > 0){
    delay(wait);
  }
}

void claw(int power){ //positive is up
  power = min(max(power,-150),150);
  if(power < 0){
    digitalWrite(38,LOW);
    digitalWrite(39,HIGH);
    analogWrite(6, abs(power));
  }
  else{
    digitalWrite(38,HIGH);
    digitalWrite(39,LOW);
    analogWrite(6, power);
  }
}
