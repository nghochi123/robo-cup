
void setup() {
  // put your setup code here, to run once:
  sercheckR.attach(SerCR);
  sercheckL.attach(SerCL);
  serswitch.attach(SerS);

  sercheckL.write(180);
  sercheckR.write(0);
  serswitch.write(180);
  
  Serial.begin(115200);
  pingTimer[0] = millis() + 75;           // First ping starts at 75ms, gives time for the Arduino to chill before starting.
  for (uint8_t i = 1; i < SONAR_NUM; i++) // Set the starting time for each sensor.
    pingTimer[i] = pingTimer[i - 1] + PING_INTERVAL;

}
