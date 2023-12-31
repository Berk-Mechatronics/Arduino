#define CW  0
#define CCW 1
 
//motor control pin
#define motorDirPin 10
#define motorPWMPin 9
#define enablePin 8
 
//encoder pin
#define encoderPinA 2
#define encoderPinB 3
 
//encoder var
int encoderPos = 0;
 
//P control
float Kp          = 20;
float Ki          = 0;
float Kd          = 0;
int   targetPos;
int   error;
int   prevError;
float   integral;
float   derivative;
float   dt = 0.01;//10 milisecond
int   control;
int   velocity;
 
//external interrupt encoder
void doEncoderA() {
  if (digitalRead(encoderPinB) == HIGH) {
    encoderPos++;
  }
  else {
    encoderPos--;
  }
}
 
void setup()
{
   //Serial.begin(9600);


  //setup interrupt
    pinMode(encoderPinA, INPUT_PULLUP);
    pinMode(encoderPinB, INPUT_PULLUP);
    attachInterrupt(digitalPinToInterrupt(encoderPinA), doEncoderA,RISING);
   
    //setup motor driver
    pinMode(motorDirPin, OUTPUT);
    pinMode(enablePin, OUTPUT);
    digitalWrite(enablePin, HIGH);
   
   
}
 
void loop()
{
    targetPos =analogRead(A0)/10;//ADC max 1023
    error   = targetPos - encoderPos;
    integral += error * dt;
    derivative = (error - prevError)/dt;
    control = (Kp*error) + (Ki*integral) + (Kd*derivative);
   
    velocity = min(max(control, -255), 255);
    if(velocity >= 0)
    {
        digitalWrite(motorDirPin, CW);
        analogWrite(motorPWMPin, velocity); 
    }
    else
    {
        digitalWrite(motorDirPin, CCW);
        analogWrite(motorPWMPin, 255+velocity);
    }
    //Serial.println(encoderPos);
    prevError = error;
    
    delay(dt*1000);      
          
}

