void setup() {
  // put your setup code here, to run once:
  pinMode(12,OUTPUT);
  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  int sensorRead=analogRead(A0);
  digitalWrite(12,HIGH);
  delay(sensorRead);
  digitalWrite(12,LOW);
  delay(sensorRead);
  Serial.println(sensorRead);
 //println(sensorRead); 
}
