#include <Servo.h>
Servo Servo_X;
Servo Servo_Y;
int R;
int X1;
int X2;
int Y1;
int Y2;
int Right02 = A4;
int Right01 = A1;
int Center = A3;
int Left01 = A2;
int Left02 = A0;
int d = 50;
int e = 1;
int GG = 0;
int TT = 0;

void setup() {
  Servo_X.attach(8);
  Servo_Y.attach(9);
  Serial.begin(9600);
}







int FirstStep() {
  Servo_X.write(104);
  Servo_Y.write(94);
  R = analogRead(Center);
  X1 = analogRead(Right01);
  X2 = analogRead(Right02);
  Y1 = analogRead(Left01);
  Y2 = analogRead(Left02);
  if (R < d & X1 < d & X2 < d & Y1 < d & Y2 < d) {
    Servo_X.write(104);
    Servo_Y.write(94);
  }
}





int Sun_SearchX() {
  int UR = 0;
  int maxAngleRR = 0;
  delay(444);
  Servo_Y.write(0);
  Servo_X.write(104);
  for (int i = 0; i <= 180; i = i + 4) {
    R = analogRead(Center);
    X1 = analogRead(Right01);
    X2 = analogRead(Right02);
    Y1 = analogRead(Left01);
    Y2 = analogRead(Left02);
    Serial.print(Y1);
    Serial.print(" ");
    Serial.print(Y2);
    Serial.print(" ");
    Serial.print(R);
    Serial.print(" ");
    Serial.print(X2);
    Serial.print(" ");
    Serial.print(X1);
    Serial.print(" ");
    Serial.println("PIUS");
    Servo_Y.write(i);
    if (R > UR) {
      UR = R;
      TT = 1;
      maxAngleRR = i;
      Serial.println(R);
    }
    delay(180);
  }
  if (UR < d) {
    TT = 1;
  } else {
    TT = 0;
  }
  Serial.print(R);
  Serial.print(" ");
  Serial.print(maxAngleRR);
  Serial.println("THIS IS ");
  return maxAngleRR;
}








int Sun_SearchY() {
  int UR = 0;
  int maxAngleRR = 0;
  delay(444);
  Servo_X.write(20);
  for (int i = 0; i <= 180; i = i + 4) {
    R = analogRead(Center);
    X1 = analogRead(Right01);
    X2 = analogRead(Right02);
    Y1 = analogRead(Left01);
    Y2 = analogRead(Left02);
    Serial.print(Y1);
    Serial.print(" ");
    Serial.print(Y2);
    Serial.print(" ");
    Serial.print(R);
    Serial.print(" ");
    Serial.print(X2);
    Serial.print(" ");
    Serial.print(X1);
    Serial.print(" ");
    Serial.println("Rick");
    Servo_X.write(i);
    if (R > UR) {
      UR = R;
      maxAngleRR = i;
      Serial.println(R);
    }
    delay(180);
  }
  if (UR < d) {
    TT = 1;
  } else {
    TT = 0;
  }
  Serial.print("This is max,");
  Serial.print(R);
  Serial.print(" ");
  Serial.println(maxAngleRR);
  return maxAngleRR;
}



void minn() {
  int Xangle;
  int Yangle;
  if (e == 1) {
    e = 2;
    Xangle = Sun_SearchX();
    delay(200);
  }
  Servo_Y.write(Xangle);
  if (e == 2) {
    e = 3;
    Yangle = Sun_SearchY();
    delay(200);
  }
  Servo_X.write(Yangle);
}









void loop() {
  if (TT == 1) {
    minn();
    delay(60000);
    GG = GG + 1;

  } else {
    GG = 0;
    minn();
    delay(1200000);
  }
  if (GG > 3) {
    while (true) {

      TT = 0;
      GG = 0;
      Servo_X.write(104);
      Servo_Y.write(94);
      R = analogRead(Center);
      X1 = analogRead(Right01);
      X2 = analogRead(Right02);
      Y1 = analogRead(Left01);
      Y2 = analogRead(Left02);
      Serial.print(Y1);
      Serial.print(" ");
      Serial.print(Y2);
      Serial.print(" ");
      Serial.print(R);
      Serial.print(" ");
      Serial.print(X2);
      Serial.print(" ");
      Serial.print(X1);
      Serial.print(" ");
      Serial.println("PIUS");
      if (R < d & X1 < d & X2 < d & Y1 < d & Y2 < d) {
        Servo_X.write(104);
        Servo_Y.write(94);
      }
      else{
        break;
      }
      delay(3600000);
    }
  }
}

















//------------------------------------------------------------------------------------------------------------------------------------//
#include <Servo.h>                                       //         Header file for servo motor
Servo Servo_X;                                           //         Servo_X at X-Axis
Servo Servo_Y;                                           //         Servo_Y at Y-Axis
int Set_First = 0;
int SerX;
int SerY;
int SY;
int SX;
//------------------------------------------------------------------------------------------------------------------------------------//
void setup() {                                           //         Arduino Setup
  Servo_X.attach(4);                                     //         Attach Servo_X motor to pin 4
  Servo_Y.attach(13);                                    //         Attach Servo_Y motor to pin 13
  Serial.begin(9600);                                    //         Set the baud rate at 9600
}
//------------------------------------------------------------------------------------------------------------------------------------//
//           YB
//
//  XL       RR         XR
// 
//           YF
//------------------------------------------------------------------------------------------------------------------------------------//

int Sun_SearchX() {
  int Default_RR = 0;
  int MaxAngleRR = 0;
  Servo_Y.write(90);                                       //         ------------------------------------- (X_BASE ANGLE)----------- 90
  Servo_X.write(0);                                        //         ------------------------------------- (X_BASE ANGLE)------------ 0
  delay(300);                                              //         Setting the Y-Axis at 90 take 0.4s or 400ms
  for (int i = 0; i <= 180; i = i + 4) {                   //         Angle difference per check is 4
    XR = analogRead(A0);                                   //         XR - Right side of X-Axis (+ve)
    XL = analogRead(A1);                                   //         XY - left side of X-Axis (-ve)
    RR = analogRead(A2);                                   //         RR - Center (Origin)
    YF = analogRead(A3);                                   //         YF - Right side of X-Axis (+ve)
    YB = analogRead(A4);                                   //         YB - Right side of X-Axis (-ve)
    //--------------------------------------------------------------------------------------------------------------------------------//
    Serial.print("_________________________________");     //         printing the data
    Serial.print("//          ");                          //         printing the data
    Serial.println(YB);                                    //         printing the data
    Serial.println("//");                                  //         printing the data
    Serial.print("//");                                    //         printing the data
    Serial.print(XL);                                      //         printing the data
    Serial.print("        ");                              //         printing the data
    Serial.print(RR);                                      //         printing the data
    Serial.print("        ");                              //         printing the data
    Serial.println(XR);                                    //         printing the data
    Serial.println("//");                                  //         printing the data
    Serial.print("//          ");                          //         printing the data
    Serial.println(YF);                                    //         printing the data
    Serial.print("_________________________________");     //         printing the data
    //--------------------------------------------------------------------------------------------------------------------------------//
    if (RR > Default_RR) {
      Default_RR = RR;
      MaxAngleRR = i;
    }
    Servo_X.write(i);
    delay(150);
  }


  Serial.print(Default_RR);
  Serial.print(" , ");
  Serial.print(MaxAngleRR);
  Serial.println(",   THIS IS THE MAXIMUM ANGLE");
  return maxAngleRR;
}

int Sun_SearchY() {
  int Default_RR = 0;
  int MaxAngleRR = 0;
  Servo_Y.write(0);                                        //         ------------------------------------- (X_BASE ANGLE)----------- 90
  delay(300);                                              //         Setting the Y-Axis at 90 take 0.4s or 400ms
  for (int i = 0; i <= 180; i = i + 4) {                   //         Angle difference per check is 4
    XR = analogRead(A0);                                   //         XR - Right side of X-Axis (+ve)
    XL = analogRead(A1);                                   //         XY - left side of X-Axis (-ve)
    RR = analogRead(A2);                                   //         RR - Center (Origin)
    YF = analogRead(A3);                                   //         YF - Right side of X-Axis (+ve)
    YB = analogRead(A4);                                   //         YB - Right side of X-Axis (-ve)
    //--------------------------------------------------------------------------------------------------------------------------------//
    Serial.print("_________________________________");     //         printing the data
    Serial.print("//          ");                          //         printing the data
    Serial.println(YB);                                    //         printing the data
    Serial.println("//");                                  //         printing the data
    Serial.print("//");                                    //         printing the data
    Serial.print(XL);                                      //         printing the data
    Serial.print("        ");                              //         printing the data
    Serial.print(RR);                                      //         printing the data
    Serial.print("        ");                              //         printing the data
    Serial.println(XR);                                    //         printing the data
    Serial.println("//");                                  //         printing the data
    Serial.print("//          ");                          //         printing the data
    Serial.println(YF);                                    //         printing the data
    Serial.print("_________________________________");     //         printing the data
    //--------------------------------------------------------------------------------------------------------------------------------//
    if (RR > Default_RR) {
      Default_RR = RR;
      MaxAngleRR = i;
    }
    Servo_Y.write(i);
    delay(150);
  }
  Serial.print(Default_RR);
  Serial.print(" , ");
  Serial.print(MaxAngleRR);
  Serial.println(",   THIS IS THE MAXIMUM ANGLE");
  return maxAngleRR;
}



// void minn() {
//   int Xangle;
//   int Yangle;
//   if (e == 1) {
//     e = 2;
//     Xangle = Sun_SearchX();
//     delay(200);
//   }
//   Servo_Y.write(Xangle);
//   if (e == 2) {
//     e = 3;
//     Yangle = Sun_SearchY();
//     delay(200);
//   }
//   Servo_X.write(Yangle);
// }




// void loop() {
//   if (TT == 1) {
//     minn();
//     delay(60000);
//     GG = GG + 1;

//   } else {
//     GG = 0;
//     minn();
//     delay(1200000);
//   }
//   if (GG > 3) {
//     while (true) {

//       TT = 0;
//       GG = 0;
//       if (R < d & X1 < d & X2 < d & Y1 < d & Y2 < d) {
//         Servo_X.write(104);
//         Servo_Y.write(94);
//       }
//       else{
//         break;
//       }
//       delay(3600000);
//     }
//   }
// }











void MIN() {
  
  SerX = Sun_SearchX();                                           //         Arduino Loop
  Servo_X.write(SerX);
  SerY = Sun_SearchY();
  return SerX, SerY;
}





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










