// LDR VALUES CHECKING
void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  int k = analogRead(A0);
  delay(1000);
  Serial.println(k);
}
