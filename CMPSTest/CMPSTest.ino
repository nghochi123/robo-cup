int light[5];
int black[5]={1000,1000,1000,1000,1000};
int white[5]={0,0,0,0,0};
int thresh[5];


void setup(){
  Serial.begin(9600);
  pinMode(30, OUTPUT);
  pinMode(31, OUTPUT);
  pinMode(8, OUTPUT);
  while (millis() < 5000) { //Callibration at the start
    light[0] = analogRead(A0);
    light[1] = analogRead(A1);
    light[2] = analogRead(A2);
    light[3] = analogRead(A3);
    light[4] = analogRead(A4);
    for(int i=0;i<5;i++){
      if(light[i]>white[i]){
        white[i]=light[i];
      }
      else{
        if(light[i]<black[i]){
          black[i]=light[i];
        }
      }
    }
  }
  for(int i=0;i<5;i++){
    thresh[i]=(black[i]+white[i])/2; //Callibrated values go to thresh array
  }
}
void loop(){  
  on(
}
