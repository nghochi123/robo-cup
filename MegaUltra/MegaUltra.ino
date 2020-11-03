//Line Tracking program is within obstacle//

int obs = 100;
int light[5];
int black[5]={1000,1000,1000,1000,1000};
int white[5]={0,0,0,0,0};
int thresh[5];


void setup() {
 /* // put your setup code here, to run once:
  Serial.begin(115200);
  Serial3.begin(115200);
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
  }*/
}

void loop() {
/*// OBSTACLE PROGRAM START //
  Serial3.write(1);
  // put your main code here, to run repeatedly:
  if(Serial3.available()){
    obs = Serial3.read();
  }
  if(obs == 1){
    on(500,-60,-60);
    on(1000,-60,60); 
    on(1000,60,60);
    on(1000,60,-60);
    on(2500,60,60);
    on(1000,60,-60);
    //move until black replace next line
    on(1000,60,60);
    on(1000,-60,60);
  }
  else{
    // LINE TRACKING START //
  light[0] = analogRead(A0);
  light[1] = analogRead(A1);
  light[2] = analogRead(A2);
  light[3] = analogRead(A3);
  light[4] = analogRead(A4);

  if(light[0] < thresh[0]){//If left-most is black
    if(light[4] > thresh[4]){//If right-most is not black
      on(250, 50, 50);//Go forward for 250ms
      light[2] = analogRead(A2);
      while(light[2] > thresh[2]){//Spin left till middle is black
        on(0, -70, 70);
        light[2] = analogRead(A2);
      }
    }  
  }
  else if(light[4] < thresh[4]){//If right-most is black
    if(light[0] > thresh[0]){//If left-most is not black
      on(250, 50, 50);//Go forward for 250ms
      light[2] = analogRead(A2);
      while(light[2] > thresh[2]){//Spin right till middle is black
        on(0, 70, -70);
        light[2] = analogRead(A2);
      }
    } 
  }
  else if(light[1] < thresh[1]){
    if(light[3] < thresh[3]){
      on(0, 50, 50);
    }
    else{
      on(0, 0, 70);
    }  
  }
  else if(light[3] < thresh[3]){
    on(0, 70, 0);
  }
  else{
    on(0, 50, 50);
  }

// LINE TRACKING END //
  }
  
  Serial.println(obs);
// OBSTACLE PROGRAM END //*/
  on(0,60,60);
}
