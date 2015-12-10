void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  Serial.println("Begin");
  pinMode(10, OUTPUT);
  pinMode(A0, INPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  lights();
  delay(5000);
  Serial.println("Loop");
}

void lights(){
  if (light()>=400){ //change that light value
    digitalWrite(10, LOW);
    Serial.println("Lights on");
  }else{
    digitalWrite(10, HIGH);
    Serial.println("Lights off");
  }
}

int light(){
  Serial.println(analogRead(A0));
  return analogRead(A0);
  
}
