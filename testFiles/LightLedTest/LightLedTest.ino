void setup() {
  // put your setup code here, to run once:
  Serial.print(9600);
  Serial.print("Begin");
  pinMode(A0, INPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  lights();
  delay(5000);
  Serial.print("Loop");
}

void lights(){
  if (light()>=400){ //change that light value
    digitalWrite(10, LOW);
    Serial.print("Lights on");
  }else{
    digitalWrite(10, HIGH);
    Serial.print("Lights off");
  }
}

int light(){
  Serial.print(                                                                                                                                     analogRead(A0));
  return analogRead(A0);
  
}
