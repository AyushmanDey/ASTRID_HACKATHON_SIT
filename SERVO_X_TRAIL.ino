#include <Servo.h>
Servo Servo_X;
Servo Servo_Y;
int XR, RR, XL, YB, YF, SerX, Default_RR, MaxAngleRR, SeraX, SeraY, SY, SX;
int Set_First = 0;
void setup() {
  Serial.begin(9600);
  Servo_X.attach(8);
  Servo_Y.attach(9);
}
int SER_X() {
  Default_RR = 0;
  MaxAngleRR = 0;
  delay(500);
  Servo_Y.write(90);
  Servo_X.write(0);
  for (int i = 0; i <= 180; i = i + 4) {
    RR = analogRead(A0);                                   //         XR - Right side of X-Axis (+ve)
    YB = analogRead(A1);                                   //         XY - left side of X-Axis (-ve)
    XL = analogRead(A2);                                   //         RR - Center (Origin)
    XR = analogRead(A3);                                   //         YF - Right side of X-Axis (+ve)
    YF = analogRead(A4);                                   //         YB - Right side of X-Axis (-ve)
    //--------------------------------------------------------------------------------------------------------------------------------//
    Serial.println("_________________________________");     //         printing the data
    Serial.print(RR);                                      //         printing the data
    Serial.print("_________________________________");     //         printing the data
    if (RR > Default_RR) {
      Default_RR = RR;
      MaxAngleRR = i;
    }
    Servo_X.write(i);
    delay(150);
  }
  return MaxAngleRR;
}

int SER_Y() {
  Default_RR = 0;
  MaxAngleRR = 0;
  Servo_Y.write(0);
  for (int i = 0; i <= 180; i = i + 4) {
    RR = analogRead(A0);                                   //         XR - Right side of X-Axis (+ve)
    YB = analogRead(A1);                                   //         XY - left side of X-Axis (-ve)
    XL = analogRead(A2);                                   //         RR - Center (Origin)
    XR = analogRead(A3);                                   //         YF - Right side of X-Axis (+ve)
    YF = analogRead(A4);                                   //         YB - Right side of X-Axis (-ve)
    //--------------------------------------------------------------------------------------------------------------------------------//
    Serial.println("_________________________________");     //         printing the data
    Serial.print(RR);                                      //         printing the data
    Serial.print("_________________________________");     //         printing the data
    //--------------------------------------------------------------------------------------------------------------------------------//
    if (RR > Default_RR) {
      Default_RR = RR;
      MaxAngleRR = i;
    }
    Servo_Y.write(i);
    delay(150);
  }
  return MaxAngleRR;
}

int minp() {
  
  SeraX = SER_X();
  Servo_X.write(SeraX);

  SeraY = SER_Y();
  Servo_Y.write(SeraY);
  delay(2000);

  return SeraX, SeraY;
}





void loop() {                                                //         Arduino Loop





  SeraX = SER_X();
  Servo_X.write(SeraX);

  SeraY = SER_Y();
  Servo_Y.write(SeraY);
  delay(2000);



  // int def = 50;
  // if (Set_First == 0){
  //   Servo_X.write(90);//------------------------------------------------------------------------------------------------- (X_BASE ANGLE)
  //   Servo_Y.write(90);//------------------------------------------------------------------------------------------------- (Y_BASE ANGLE)
  //   delay(1000);

  //   SX, SY = minp();    
  //   Set_First = 1;
  // }
  // else {
    // RR = analogRead(A0);                                   //         XR - Right side of X-Axis (+ve)
    // YB = analogRead(A1);                                   //         XY - left side of X-Axis (-ve)
    // XL = analogRead(A2);                                   //         RR - Center (Origin)
    // XR = analogRead(A3);                                   //         YF - Right side of X-Axis (+ve)
    // YF = analogRead(A4);                                   //         YB - Right side of X-Axis (-ve)
    // if (RR>YB & RR>YF & RR>XR & RR>XL) {
    //   delay(10000);
    // }
    // else if (YB>RR & YB>YF & YB>XL & YB>XR) {
    //   SY = SY - 4;
    //   Servo_Y.write(SY);
    // }
    // else if (YF>XL & YF>XR & YF>YB & YF>RR){
    //   SY = SY+4;
    //   Servo_Y.write(SY);
    // }
    // else if (XR>YF & XR>YB & XR>XL & XR>RR) {
    //   XR = XR-4;
    //   Servo_X.write(XR);
    // }
    // else if (XL>YF & XL>YB & XL>XR & XL>RR ) {
    //   XL + XL+4;
    //   Servo_X.write(XL);
    // }
    // else if (XL<def & XR<def & RR<def & YB<def & YF<def) {
    //   delay(30000);
    //   RR = analogRead(A0);                                   //         XR - Right side of X-Axis (+ve)
    //   YB = analogRead(A1);                                   //         XY - left side of X-Axis (-ve)
    //   XL = analogRead(A2);                                   //         RR - Center (Origin)
    //   XR = analogRead(A3);                                   //         YF - Right side of X-Axis (+ve)
    //   YF = analogRead(A4);                                   //         YB - Right side of X-Axis (-ve)
    //   if (XL<def & XR<def & RR<def & YB<def & YF<def) {
    //     delay(30000);
    //     RR = analogRead(A0);                                   //         XR - Right side of X-Axis (+ve)
    //     YB = analogRead(A1);                                   //         XY - left side of X-Axis (-ve)
    //     XL = analogRead(A2);                                   //         RR - Center (Origin)
    //     XR = analogRead(A3);                                   //         YF - Right side of X-Axis (+ve)
    //     YF = analogRead(A4);                                   //         YB - Right side of X-Axis (-ve)
    //     if (XL<def & XR<def & RR<def & YB<def & YF<def) {
    //       Servo_X.write(90);
    //       Servo_Y.write(90);
    //       delay(60000);
    //     }
    //     else {
    //       Set_First = 0;
    //     }
    //   }
    //   else {
    //     Set_First = 0;
    //   }

    // }
    // else {
    //   Set_First = 0;
    // }

  
  // }
  // delay(5000);
}

