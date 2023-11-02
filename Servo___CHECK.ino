#include <Servo.h>
Servo Serv;
void setup() {
  // put your setup code here, to run once:
   Serv.attach(3);
}

void loop() {
  // put your main code here, to run repeatedly:
  Serv.write(90);
}
