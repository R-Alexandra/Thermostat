#include "Comp_LED.h"           // include LED class
#include <LiquidCrystal_I2C.h>  // library for I2C 16x2 LCD screen
#include "DHT.h"                // library for DHT11 sensor

// define DHT sensor pin and type
#define DHTPIN 2
#define DHTTYPE DHT11

// initialize LED pins (automatically calls LED constructor)
Comp_LED blueLED(9);

Comp_LED redLED(10);
Comp_LED greenLED(11);

// fan pins
int INA = 12;
int INB = 13;

LiquidCrystal_I2C lcd(0x27, 16, 2);  // address 0x27 for I2C 16x2 LCD screen
DHT dht(DHTPIN, DHTTYPE);

void setup() {
  dht.begin();           // initialize temperature and humidity sensor
  lcd.init();            // initialize LCD screen
  lcd.backlight();       // turn on LCD backlight
  pinMode(INA, OUTPUT);  // set fan pins INA(12) and INB(13) as output
  pinMode(INB, OUTPUT);
}

void loop() {
  delay(200);  // delay between measurements

  float humi = dht.readHumidity();      // read humidity from sensor
  float tempC = dht.readTemperature();  // read temperature

  lcd.clear();
  // check if any readings failed, display a message if so
  if (isnan(humi) || isnan(tempC)) {
    lcd.setCursor(0, 0);
    lcd.print("Failed");
  } else {
    lcd.setCursor(0, 0);  // start displaying on the first row
    lcd.print("Temp: ");
    lcd.print(tempC);      // display temperature value
    lcd.print((char)223);  // display ° character for temperature
    lcd.print("C");        // display C to indicate Celsius

    lcd.setCursor(0, 1);  // continue displaying on the second row
    lcd.print("Humi: ");
    lcd.print(humi);  // display humidity value in percentage
    lcd.print("%");
    // if temperature is below 20°C, blink blue LED
    if (tempC < 20)
      blueLED.blinking(700);
    // if temperature is between 20°C and 26°C, blink green LED
    else if (tempC < 26)
      greenLED.blinking(700);
    // if temperature is above 26°C, blink red LED and turn on the fan
    else {
      redLED.blinking(500);
      // turn on the fan
      analogWrite(INA, 255);
      digitalWrite(INB, LOW);
      delay(2000);  // how long to keep it on
      // turn off the fan to resume the loop and check if the system state has changed
      digitalWrite(INA, LOW);
      digitalWrite(INB, LOW);
      delay(0);
    }
  }
}