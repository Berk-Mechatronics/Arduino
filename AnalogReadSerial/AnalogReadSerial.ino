int PWM_Pin = 3; /* give PWM_Pin name to D3 pin */
#define potpin A0;
// Perform initialization inside setup()
void setup()
{
pinMode(PWM_Pin,OUTPUT);  /*declare D3 pin as an output pin */ 
TCCR2B = TCCR2B & B11111000 | B00000111;
 /*set 30.64Hz Frequency */
}
void loop()
{
  if (Serial.available()){
     int PWM_FREQ = Serial.read();
    Serial.print("Freq: ");
    int PWM_Freq_cal = (PWM_FREQ/255)*100; 
    analogWrite(PWM_Pin,PWM_Freq_cal);
  }
}
