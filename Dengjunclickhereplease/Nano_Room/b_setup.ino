
void setup() {
  // put your setup code here, to run once:
  sercheckR.attach(SerCR);
  sercheckL.attach(SerCL);
  serswitch.attach(SerS);

  sercheckL.write(180);
  sercheckR.write(0);
  serswitch.write(180);
  
  Serial.begin(9600);

}
