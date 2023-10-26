int button1=38, button2=40;
void setup()
{ 
   pinMode(43, OUTPUT);
   pinMode(button1, INPUT_PULLUP);
   pinMode(button2, INPUT_PULLUP);
   digitalWrite(43, HIGH);
   Serial.begin(9600);
}
  
void loop()
{
  int state1= digitalRead(button1);
  int state2= digitalRead(button2);
  Serial.print("Button1= ");
  Serial.print(state1);
  Serial.print("       Button2=");
  Serial.println(state2);
  delay(1000);
  if (state1==0 && state2==0)
  {digitalWrite(43, LOW);
    }
  else
  {
    digitalWrite(43,HIGH );
  }
 
}
