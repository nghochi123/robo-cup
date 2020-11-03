void on(int wait,int lpwr,int rpwr){ //36/37:left 38/39:claw 40/41:right
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
  analogWrite(7,rpwr);
  analogWrite(5,lpwr);
  if(wait > 0){
    delay(wait);
  }
}
