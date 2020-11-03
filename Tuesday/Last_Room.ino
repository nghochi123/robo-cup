// LAST ROOM//
void room() {
  check();


  roomalive();
  roomall();
}

// Turn corner//
void cmpsturncorner(int dir, int deg) { //1 is right 0 is left for dir, use for last room or maybe 90 degree turns
  cmpsinit();
  if (dir == 0) {
    while (actualangle > 360 - deg || actualangle < 15) { //degree go clockwise so when turn left 360-90, less than 15 in case slight turn other directn.
      cmpsdeg();
      on(0, -50, 200);
    }
  }
  else if (dir == 1) {
    while (actualangle < deg || actualangle > 345) { //same as above
      cmpsdeg();
      on(0, 50, -200);
    }
  }
  on(0, 0, 0);
  cmpsinit();
  cmpsdeg();
}



//Straight and collect//
void edge() {
  //  stat();
  on(300, -100, 100);
  claw(0, -100);
  delay(500);
  on(550, 200, -200);
  edgetimer = millis();
  while ( millis() - edgetimer <=4000) { // run along edge for 3 secs or touched
    touch = digitalRead(Touch45);
    if (touch == 1) {
      prevtouch =1;
      break;
    }
    else {

      on(0, 200, 150);
//      nano2_1();
//      detectobs();
      nano();
      if (side > 30) {
        on(0, 100, 120);
      }
    }
  }
/*  on(100, 0, 0);
  nano();
  if (not(3 < front && front < 100)) {
    on(200, -100, -100);
    on(0, 0, 0);
  }
  else {
    on(200, -100, 100);
    claw(0, -100);
    delay(500);
    on(400, 200, -200);
    edgetimer = millis();
    while ( millis() - edgetimer <= 2500) { // run along edge for 3 secs or touched
      touch = digitalRead(Touch45);
      if (touch == 1) {
        prevtouch = 1;
        break;
      }
      else {

        on(0, 200, 150);
        nano();
        if (side > 30) {
          on(0, 100, 120);
        }
      }
    }
  }*/
}


void touched(int b) {
  on(50, -200, -200);
  cmpsturncorner(0, b);
  on(1000, 200, 200);
  on(50, -200, -200);
  cmpsturncorner(0, b);
}

// Corner 1 /
/*

  void corner(int a){
  if (touch == 1){
    touched();
  }
  else
  {
    on(220,-100,-100);
    on(0,0,0);
    claw(1500,100);
    on(200,-100,-100);
    cmpsturncorner(0, a);
    on(200,150,150);
    on(200,-150,-150);
    on(1000,-150,-150);

  }
  }
*/

// Corner 2 //
/*
  void corner(){
  if (touch == 1){
    touched(40);
  }
  else
  {
    on(200,-100,-100);
    on(0,0,0);
    claw(1000,100);

    on(1000,-150,-150);
    on(400,100,100);
  }
  }
*/

void dumptouched() {
  on(100, -150, -150);
  left45();
  on(350, 200, 200);
  left90();
  on(2000, -150, -150);
  alive();
  on(100, 150, 150);
  right90();
  on(350, 200, 200);
  left45();
}

void dumpalltouched() {
  on(100, -150, -150);
  left45();
  on(350, 200, 200);
  left90();
  on(2000, -150, -150);
  dump();
  on(100, 150, 150);
  right90();
  on(350, 200, 200);
  left45();
}

void dumpcorner() {
  if (touch == 1) {
    dumptouched();
  }
  else
  {
    /*   stat();
        on(200,-100,-100);
        on(0,0,0);
        claw(1000,100);
    */
    on(200, -100, -100);
    on(0, 0, 0);
    claw(1000, 100);
    delay(300);
    left90();
    on(500, -200, -200);

    /*    cmpsturn(0,l180);u
        on(1000,-150,-150);
        on(400,100,100);
        cmpsturncorner(1,r90);
    */
    /*    on(300,-150,-150);
        cmpsturncorner(0,l90);
        on(200,200,200);
        on(300,-200,-200);
    */
  }
}

void dumpallcorner() {
  if (touch == 1) {
    dumpalltouched();
  }
  else
  {
    /*   stat();
        on(200,-100,-100);
        on(0,0,0);
        claw(1000,100);
    */
    on(200, -100, -100);
    on(0, 0, 0);
    claw(1000, 100);
    delay(300);
    left90();
    on(500, -200, -200);
  }
}

//---------Detect Obstacle-------//

void detectedright() {
  on(150, -150, -150);
  on(0, 0, 0);
  claw(1500, 150);
  on(300, 150, 150);
  left90();
  align();
  on(500, 150, 150);
  right90();
  on(400, 200, 200);
  right90();
  on(300, -200, -200);
  on(0,0,0);
  claw(0,-100);
  delay(300);
  on(600,200,200);
  on(200, -100, -100);
  on(0, 0, 0);
  claw(1000, 100);
  delay(300);
  left90();
  on(100, -200, -200);
  on(0,0,0);
  claw(200,100);
  claw(200,-100);
}
/*
void detectedleft() {
  on(150, -150, -150);
  on(0, 0, 0);
  claw(1500, 150);
  on(200, 150, 150);
  left90();
  on(700, -200, -200);
  on(700, 150, 150);
  right90();
  on(800, 200, 200);
  left90();
  on(1800, -150, -150);
  right90();
  on(100, -150, -150);
}
*/

void detectobs() {
  if (ultra1 < 10 || ultra2 < 10) {
   if( abs(ultra1 - ultra2) >15 && abs(ultra1 - ultra2) < 150){
    obst = 1;
    if ( ultra1 > ultra2) {
      detectedright();
    }
   }
  }
}

// Initial Check

void check() {
  on(700, 100, 100);
  on(0, 0, 0);
  sersweep.write(180);
  delay(100);
  sersweep.write(110);
  nano();
  if (side > 20) {
    right90();
  }
}

// Room Alive
// Room All
void roomalive() {
  for (int i = 0; i < 9; i ++) {
    edge();
//    if (obst == 1){
//      edge();
//    }
//    obst = 0;
    dumpcorner();
  }
}
void roomall() {
  while (0 == 0) {
    edge();
//    if (obst == 1){
//      edge();
//   }
//    obst = 0;
    dumpallcorner();
  }
}


//CMPS Calibrate

int lcmpscal90(int a) {
  if ( 10 < a && a < 40 ) {
    return  70;
  }
  if ( 125 < a && a < 155  ) {
    return  115;
  }
  if ( 225 < a && a < 255 ) {
    return  100 ;
  }
  if ( 300 < a && a < 330 ) {
    return  75 ;
  }
  else {
    return 90;
  }
}

int lcmpscal45(int a) {
  if ( 10 < a && a < 40 ) {
    return  35;
  }
  if ( 125 < a && a < 155  ) {
    return  58;
  }
  if ( 225 < a && a < 255 ) {
    return  50 ;
  }
  if ( 300 < a && a < 330 ) {
    return  38 ;
  }
  else {
    return 90;
  }
}

int rcmpscal90(int a) {
  if ( 10 < a && a < 40 ) {
    return  115;
  }
  if ( 125 < a && a < 155  ) {
    return  100;
  }
  if ( 225 < a && a < 255 ) {
    return  75 ;
  }
  if ( 300 < a && a < 330 ) {
    return  70 ;
  }
  else {
    return 90;
  }
}

int rcmpscal45(int a) {
  if ( 10 < a && a < 40 ) {
    return  58;
  }
  if ( 125 < a && a < 155  ) {
    return  50;
  }
  if ( 225 < a && a < 255 ) {
    return  38 ;
  }
  if ( 300 < a && a < 330 ) {
    return  35 ;
  }
  else {
    return 90;
  }
}

int lcmpscal180(int a) {
  if ( 10 < a && a < 40 ) {
    return  145;
  }
  if ( 125 < a && a < 155  ) {
    return  185;
  }
  if ( 225 < a && a < 255 ) {
    return  215 ;
  }
  if ( 300 < a && a < 330 ) {
    return  175 ;
  }
  else {
    return 90;
  }
}


/*void stat(){
  dir = cmpsinita();
  l180 = lcmpscal180(dir);
  r90 = rcmpscal90(dir);
  l45 = lcmpscal45(dir);
  l90 = lcmpscal90(dir);
  }
*/

// Hardcode turn
void left90() {
  on(1550, -100, 200);
  on(0, 0, 0);
}

void right90() {
  on(1550, 200, -100);
  on(0, 0, 0);
}

void left45() {
  on(775, -100, 200);
  on(0, 0, 0);
}

//Prev Touch
int pretouch() {
  if (prevtouch == 1){
    prevtouch = 0;
    return 1000;
  }
  if (prevtouch == 0){
    prevtouch =0;
    return 2000;  
 }
}

void align(){
  on(2000,-200,-200);
}


