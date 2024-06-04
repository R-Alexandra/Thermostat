# Thermostat

This project implements an Arduino-based automated system designed to monitor, alert, and adjust room conditions based on temperature readings, ensuring optimal comfort. By automating control, the system ensures that adjustment devices are active only when necessary.

## How It Works

The system is built around an Arduino board that receives data from a DHT11 temperature and humidity sensor and processes it, acting accordingly. Temperature and humidity information (system status) is displayed on an LCD screen, providing immediate feedback to the user. The project's goal is to maintain an optimal temperature, so there are three possible scenarios:

### Scenarios

- **Measured temperature < 20 degrees Celsius:**
  - The blue LED lights up and starts blinking to alert that the temperature has dropped significantly and a heat source needs to be turned on.
  
- **Measured temperature between 20 and 26 degrees Celsius:**
  - The green LED lights up, ensuring that the temperature is optimal.
  
- **Measured temperature > 26 degrees Celsius:**
  - The red LED lights up and starts blinking to alert that the temperature is too high. Additionally, the fan module is automatically activated to help cool down the room.

At short periodic intervals, new data is retrieved from the sensor (new measurements are taken) and processed to determine if a transition from one situation to another is needed.

The entire system is powered by a 9V battery for easy portability to other rooms if needed or to be placed anywhere in the room, not relying on a fixed (static) power source.

## Materials

1. Arduino UNO R3 + Connection Cable
2. Breadboard
3. DHT11 Sensor
4. LEDs (Blue, Red, Green)
5. L9110 Fan Module
6. 16x2 I2C LCD Screen
7. 220 Ohm Resistors (one for each LED)
8. 9V Battery + Battery Connector Cable
9. Connection Wires

## Project Resources

- **Arduino Code:** Complete Arduino sketch for the project, including the main logic and custom LED library.
- **Libraries:** C++ library files for LED control.
- **Hardware Diagram:** Included in the project files to illustrate the circuit connections and component layout.
- **Photos:** Images of the project in operation, demonstrating its functionality and visual appearance.

Feel free to explore the project files for detailed implementation and instructions. Enjoy building and optimizing your Arduino-Based Automatic Thermostat System!
