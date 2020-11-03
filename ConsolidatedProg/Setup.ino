void setup()
{
  Wire.begin();
  Serial.begin(9600); //check all; 9600 for PC display, 115200 for communication
  Serial2.begin(115200);
  Serial3.begin(115200);
  pinMode(30, OUTPUT);
  pinMode(31, OUTPUT);
  pinMode(8, OUTPUT);
  serdumpR.attach(SerDR);
  serdumpL.attach(SerDL);
  sersweep.attach(Serswp);

  serdumpL.write(0);
  serdumpR.write(180);
  sersweep.write(170);
  while (millis() < 6000) { //Callibration at the start
    light[0] = analogRead(LDR_0);
    light[1] = analogRead(LDR_1);
    light[2] = analogRead(LDR_2);
    light[3] = analogRead(LDR_3);
    light[4] = analogRead(LDR_4); //A4 is spoilt
    for(int i=0; i<5; i++){
      if(light[i] > white[i]){
        white[i] = light[i];
      }
      else{
        if(light[i] < black[i]){
          black[i] = light[i];
        }
      }
    }
  }
  for(int i=0; i<5; i++){
    thresh[i] = (black[i] + white[i])/2; //Callibrated values go to thresh array
    thresh2[i] = (black[i] + 0.3*(white[i] - black[i]));
  }
    rampinit();
}
