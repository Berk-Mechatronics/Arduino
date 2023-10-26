const int analogPin = A0;  // the analog pin the force sensor is connected to

void setup() {
  Serial.begin(9600);  
}

void loop() {
  int sensorValue = analogRead(analogPin); 
  float voltage = sensorValue * (5.0 / 1023.0);  
  
  Serial.print("Voltage: ");
  Serial.println(voltage);
  
  Serial.print(sensorValue);
  
  delay(1000);

  

}
