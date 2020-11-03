void on(int wait,int lpwr,int rpwr){
  if(lpwr < 0){
      digitalWrite(30,LOW); //30 High is forward left
      digitalWrite(31,HIGH);
      lpwr = abs(lpwr);
    }
  else{
      digitalWrite(30,HIGH); //30 High is forward left
      digitalWrite(31,LOW);    
  }
  if(rpwr < 0){
      digitalWrite(32,LOW);
      digitalWrite(33,HIGH);
      rpwr = abs(rpwr); 
  }
  else{
      digitalWrite(32,HIGH);
      digitalWrite(33,LOW);
  }
  analogWrite(8,lpwr);
  analogWrite(9,rpwr);
  if(wait > 0){
    delay(wait);
  }
}
