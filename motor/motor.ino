// https://circuitmagic.com/arduino/how-to-control-dc-motor-with-l298n-driver-and-arduino/
int motor1pin1 = 2;
int motor1pin2 = 3;

int motor2pin1 = 11;
int motor2pin2 = 5;

void setup() {
  // put your setup code here, to run once:
  pinMode(motor1pin1, OUTPUT);
  pinMode(motor1pin2, OUTPUT);
  pinMode(motor2pin1, OUTPUT);
  pinMode(motor2pin2, OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:   
  for (int i =0; i<256; i++){ 
  digitalWrite(motor1pin1, HIGH);
  analogWrite(motor1pin2, i);

  digitalWrite(motor2pin2, HIGH);
  analogWrite(motor2pin1, i);
  delay(1000);
  }
 for (int i =0; i<256; i++){ 
  digitalWrite(motor1pin1, LOW);
  analogWrite(motor1pin2, (256-i));

  digitalWrite(motor2pin1, LOW);
  analogWrite(motor2pin2, (256-i));
  delay(1000);
  }
}
