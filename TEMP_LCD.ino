/*
  Autor: Edgard José Díaz  Tipacamú
  Date: Oct 2019
  
  This code reads the temperature and humidity sensor DCH 11. 
  In addition, the configuration of an LCD screen is carried out in 
  which the data obtained from the above-mentioned sensor are shown.

*/

#include<LiquidCrystal.h>
const int rs = 12, en = 11, d4 = 5, d5 = 4, d6 = 3, d7 = 2;

LiquidCrystal lcd(rs,en, d4,d5,d6,d7);

#include "DHT.h"
#define DHTPIN 8
#define DHTTYPE DHT11
DHT Sensor(DHTPIN,DHTTYPE);
#define led 9

void setup()
{
  lcd.begin(16,2);
  pinMode(led,OUTPUT);
}

void loop()
{
  while(1)
  {
    float h, t;

    h = Sensor.readHumidity();
    t = Sensor.readTemperature();

    temperatura(t);
    humedad(h);

    delay(2000);
    digitalWrite(led,HIGH);
    delay(100);
    digitalWrite(led,LOW);
  } 
}

float temperatura(float temp)
{
  lcd.setCursor(0,1);
  lcd.print("Temp: ");
  lcd.print(temp);
  lcd.print(" c");
  return 0;
}

float humedad(float Humedad)
{
  lcd.setCursor(0,0);
  lcd.print("Humedad: ");
  lcd.print(Humedad);
  lcd.print("%");

  return 0;
}
