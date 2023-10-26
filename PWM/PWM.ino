#include <PWM.h>
#define pot A0
int potval= 5;
int frekpot = A1;

void setup() {
  Serial.begin(9600);
  // put your setup code here, to run once: 
  pinMode(potval,OUTPUT);
}

void loop() {
  int deger = analogRead(pot);
  int frek_deger = analogRead(frekpot)/4;
  frek_deger = map(frek_deger,0,1023,0,255);
  deger = map(deger,0,1023,0,255);
  analogWrite(potval,deger);
  delay(30);
  analogWrite(potval,frek_deger);
  delay(30);  

  // put your main code here, to run repeatedly:

}
