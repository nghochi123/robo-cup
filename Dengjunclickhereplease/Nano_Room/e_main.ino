void loop() {
 /* servocheck();
  conduct();
*/
  distance1 = sonar1.ping_cm();
  distance3 = sonar3.ping_cm();
  Serial.print("Distance1 ");
  Serial.print(distance1);
  Serial.print(" Distance3 ");
  Serial.println(distance3);
}

