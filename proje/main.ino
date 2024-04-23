#include <Servo.h>

const int trigPin1 = 10;
const int echoPin1 = 11;
const int buzzerpin=2;
const int ledPinRed = 13;
const int ledPinGreen = 9;
long duration;
int distance1;
Servo myServo1;
float heat =0;
const int heat_pin= A0;

void setup() {
 pinMode(trigPin1, OUTPUT);
  pinMode(echoPin1, INPUT); 
  pinMode(buzzerpin, OUTPUT);
  pinMode(ledPinRed, OUTPUT);
  pinMode(ledPinGreen, OUTPUT);
  Serial.begin(9600);
  myServo1.attach(12);
  
}


void loop() { 
 
 
  for(int i=5;i<=175;i++){  
  myServo1.write(i);
  distance1 =calculateDistance_servo1();
  delay(3);
  Serial.print("Angle: ");
  Serial.println(i);
  Serial.print(" Distance1: ");
  Serial.println(distance1);
  Serial.print(" Heat: ");
  Serial.println(heat);
  
  }
  for(int i=175;i>=5;i--){  
  myServo1.write(i);
  distance1 =calculateDistance_servo1();
  delay(30);
  Serial.print(" Angle: ");
  Serial.println(i);
  Serial.print(" Distance1: ");
  Serial.println(distance1);
  Serial.print(" Heat: ");
  Serial.println(heat);
}  

}



int calculateDistance_servo1(){ 
  heat = analogRead(heat_pin);
  heat = (heat*(5000.0/1023.0))/10.0;
  digitalWrite(trigPin1, HIGH); 
  delayMicroseconds(2);
  digitalWrite(trigPin1, LOW);
  delayMicroseconds(10);  
  duration = pulseIn(echoPin1,HIGH);
  distance1 = (duration/2)/29.1;
  
  if (distance1 <=50&& distance1>=0){
    digitalWrite(buzzerpin, HIGH);
    digitalWrite(ledPinGreen, HIGH);
    digitalWrite(ledPinRed, LOW);
    if(distance1<=25&& distance1>=0){
     digitalWrite(buzzerpin, HIGH);
     digitalWrite(ledPinRed, HIGH);
     digitalWrite(ledPinGreen, LOW);
     }
   }
  else if (heat<=0.0 || heat>=50.0){
    digitalWrite(buzzerpin, HIGH);
    digitalWrite(ledPinGreen, HIGH);
    digitalWrite(ledPinRed, HIGH);
    myServo1.write(90); 
    delay(1000);
    
    }
  else{
    digitalWrite(buzzerpin,LOW);
    digitalWrite(ledPinRed, LOW);
    digitalWrite(ledPinGreen, LOW); 
    
    }
  delay(100);
  return distance1;
}
