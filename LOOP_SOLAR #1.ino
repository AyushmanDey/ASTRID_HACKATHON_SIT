
void loop() {                                                //         Arduino Loop
  int Def = 100;
  if (Set_First == 0){
    Servo_X.write(90);//------------------------------------------------------------------------------------------------- (X_BASE ANGLE)
    Servo_Y.write(90);//------------------------------------------------------------------------------------------------- (Y_BASE ANGLE)
    delay(1000);


    SX, SY = MIN();    
    
    Set_First = 1;
  }
  else {
    XR = analogRead(A0);                                   //         XR - Right side of X-Axis (+ve)
    XL = analogRead(A1);                                   //         XY - left side of X-Axis (-ve)
    RR = analogRead(A2);                                   //         RR - Center (Origin)
    YF = analogRead(A3);                                   //         YF - Right side of X-Axis (+ve)
    YB = analogRead(A4);                                   //         YB - Right side of X-Axis (-ve)
    if (RR>YB & RR>YF & RR>XR $ RR>XL) {
      delay(10000);
    }
    else if (YB>RR & YB>YF & YB>XL & YB>XR) {
      SY = SY - 4
      Servo_Y.write(SY);
    }
    else if (YF>XY & YF>XR & YF>YB & YF>RR){
      SY = SY+4
      Servo_Y.write(SY);
    }
    else if (XR>YF & XR>YB & XR>XL & XR>RR) {
      XR = XR-4
      Servo_X.write(XR);
    }
    else if (XL>YF & XL>YB & XL>XR & XL>RR ) {
      XL + XL+4
      Servo_X.write(XL);
    }
    else if (XL<def & XR<def & RR<def & YB<def & YF<def) {
      delay(300000);
      if (XL<def & XR<def & RR<def & YB<def & YF<def) {
        delay(30000);
        if (XL<def & XR<def & RR<def & YB<def & YF<def) {
          Servo_X.write(90);
          Servo_Y.write(90);
        }
      }
      else {
        Set_First = 0;
      }

    }

  }
  
}
