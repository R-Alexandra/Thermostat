#ifndef Comp_LED_H
#define Comp_LED_H
#include "Arduino.h"

class Comp_LED
{
private:
    int pin; 
public:
    Comp_LED(int p);
    void blinking(int blinkRate);

};

#endif