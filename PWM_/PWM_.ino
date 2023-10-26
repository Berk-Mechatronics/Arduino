#include <TimerOne.h>
#include <LiquidCrystal.h>
LiquidCrystal lcd(12, 11, 5, 4, 3, 2);// RS,E,D4,D5,D6,D7
unsigned long t=1000,f,pulse=512;// 1000 Hz, freq, pulse 


byte frekanshesap,artisbutton,azalatmabutton,dutybuttonI,dutybuttonD;
int drive,drive0;

void setup()
{ 
  Serial.begin(9600);
  lcd.begin(16, 2);// LCD 16X2
  pinMode(9, OUTPUT);
  pinMode(6,INPUT);// - butonu
  pinMode(7,INPUT);// + butonu 
  pinMode(8,INPUT);// -duty butonu
  pinMode(13,INPUT);// +duty butonu
}
void loop()
{
  Timer1.initialize(t); // periyod   
  Timer1.pwm(9, pulse); // k nın 0-1023 arası. 
  azalatmabutton=digitalRead(6);
  artisbutton=digitalRead(7);
  dutybuttonD=digitalRead(8);
  dutybuttonI=digitalRead(13);

  if(azalatmabutton==HIGH && artisbutton==LOW){ // periyod azalatma
    drive++;
    if(drive<30){ 
      t=t-1;  
    }
    else if(drive>30 && drive<60 ){ 
      t=t-10; 
    }
    else if(drive>=60 && drive<100){
      t=t-100;
    }
    else if(drive>=100){
      t=t-1000;
    }
  }
  else{
    drive=0;
  }

  if(artisbutton==HIGH && azalatmabutton ==LOW){// periyod arttırma
    drive0++;
    if(drive0<30){
      t=t+1; 
    }
    else if(drive0>30 && drive0<60 ){ 
      t=t+10; 
    }
    else if(drive0>=60 && drive0<100){
      t=t+100;
    }
    else if(drive0>=100){
      t=t+1000;
    }
  } 
  else{
    drive0=0;
  }
  if(t==0 || t>300000){ 
    t=1;
  }
  if(t>200000 && t<300000){ 
    t=200000;
  } 
  f=1000000/t; // frekans hesabı
  frekanshesap=pulse*100/1024; // duty hesabı
  
  if(dutybuttonI==HIGH && dutybuttonD ==LOW ){//+ 
    pulse=pulse+8;}// 16 ve 8 arasında yapılabilir. 8 daha hassas olur
  if (dutybuttonD ==HIGH && dutybuttonI==LOW ){
    pulse = pulse-8;}
  if (pulse == 1024){
    lcd.setCursor(12,0);
    lcd.print("PULSE FULL");
    pulse = 1024;}

  Serial.print("Frekans: ");
  Serial.println(f);
  Serial.print("Duty: ");
  Serial.println(frekanshesap);
  lcd.setCursor(12,0);
  lcd.print(frekanshesap);
  lcd.print(" %");
  lcd.setCursor(0,1); 
  lcd.print("F=");
  lcd.print(f);
  lcd.print(" Hz");
  delay(300);
  lcd.setCursor(0,0); 
  lcd.print("                ");
  lcd.setCursor(0,1); 
  lcd.print("                ");
}
