void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(2, INPUT_PULLUP);
  pinMode(13, OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  int buttonState = digitalRead(2);
  if(buttonState == 0){
    digitalWrite(13, LOW);
    Serial.println("botton is pushed");
  }
  else{
    digitalWrite(13, HIGH);
    Serial.println("botton is NOT pushed");
  }
}
