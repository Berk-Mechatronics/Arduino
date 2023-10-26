#include <OneWire.h> 
#include <Wire.h> 
#include <DallasTemperature.h> 
OneWire oneWire(3);
DallasTemperature DS18B20(&oneWire);

DeviceAddress DS18B20adres;


const int analogInPin = A0; 

const int SensorValueLow = 463; 
const int SensorValueDiff = 36; 
const int TempValueDiff = 42; 
const int TempValueLow = 9;

int sensorValue = 0;
double Temp = 0;


float santigrat, fahrenheit;
void setup(void)
{

 Serial.begin(9600);

 DS18B20.begin();

 DS18B20.getAddress(DS18B20adres, 0);

 DS18B20.setResolution(DS18B20adres, 12);

}

void loop(void)

{
  sensorValue = analogRead(analogInPin);
  Temp = sensorValue-SensorValueLow;
  Temp = Temp/SensorValueDiff;
  Temp = Temp*TempValueDiff;
  Temp = Temp+TempValueLow;

 DS18B20.requestTemperatures();
 santigrat = DS18B20.getTempC(DS18B20adres);

 fahrenheit = DS18B20.toFahrenheit(santigrat);

 Serial.print(Temp); 
 Serial.print(" PT100 C  ");
 Serial.println();
 Serial.print(santigrat);
 Serial.print(" DS18 C -- ");


 delay(60000);


}
