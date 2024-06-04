#include "Comp_LED.h"

Comp_LED::Comp_LED(int p) 
{
  pin = p;
  pinMode(pin, OUTPUT);
}

void Comp_LED::blinking(int blinkRate) 
{
    digitalWrite(pin, HIGH);
    delay(blinkRate);
    digitalWrite(pin, LOW);
    delay(0);
}