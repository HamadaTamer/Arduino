https://www.tinkercad.com/things/7ASYP6IimZE-bodacious-sango-blad/editel?sharecode=suGk-Z4G8aaLJZaHcMG_wK-ow5oTbXVRV7Vk3TCnUiQ
#include <Servo.h>
Servo servo1;
int servopin=11;
int vres=A0;

void setup()
{
  servo1.attach(servopin);
  pinMode(vres, INPUT);
  Serial.begin(9600);
}

void loop()
{
  
  int val=analogRead(vres);
  int angle =map(val, 0,1023, 0,180);
  servo1.write(angle);
  Serial.println(angle);
}
