void setup(){
  pinMode(LMA, OUTPUT);
  pinMode(LMB, OUTPUT);
  pinMode(LMPWM, OUTPUT);
  pinMode(RMA, OUTPUT);
  pinMode(RMB, OUTPUT);
  pinMode(RMPWM, OUTPUT);
  pinMode(CMA, OUTPUT);
  pinMode(CMB, OUTPUT);
  pinMode(CMPWM, OUTPUT);
  pinMode(SerDL, OUTPUT);
  pinMode(SerDR, OUTPUT);
  pinMode(Touch45, INPUT);

  

  serdumpR.attach(SerDR);
  serdumpL.attach(SerDL);
  sersweep.attach(Serswp);

  serdumpL.write(0);
  serdumpR.write(180);
  sersweep.write(170);

  Wire.begin();
  Serial2.begin(115200);
  Serial.begin(115200);
  Serial3.begin(115200);
  delay(1000);





}

