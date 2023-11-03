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
