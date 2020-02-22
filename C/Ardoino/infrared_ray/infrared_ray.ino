void setup() {
  // put your setup code here, to run once:
  pinMode(12,OUTPUT);
  pinMode(11,OUTPUT);
  pinMode(2,INPUT_PULLUP);
}

void loop() {
  // put your main code here, to run repeatedly:
  digitalWrite(11,HIGH);
  if(digitalRead(2) == LOW)
  {
    noTone(12);
  }
  else if(digitalRead(2) == HIGH)
  {
    tone(12,271);
  }
}
