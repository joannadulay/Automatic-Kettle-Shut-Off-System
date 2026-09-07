# Arduino Automatic Kettle Shut-Off System

An Arduino-based automatic kettle shut-off system that uses a DHT11 temperature sensor to monitor temperature and detect when the water reaches a defined threshold. When the temperature reaches 40°C, the system activates a buzzer as an alert and uses a servo motor to simulate turning off the kettle.

## Features

- Temperature monitoring using a DHT11 sensor
- Automatic detection when the temperature reaches the 40°C threshold
- Buzzer alert when the threshold is reached
- Servo motor activation to simulate turning off the kettle
- Serial Monitor output for temperature readings and system status
- Prevents repeated alerts while the temperature remains above the threshold
- Automatically resets the alert state when the temperature drops below the threshold
- Arduino-controlled coordination between sensor input and actuator outputs

## Components

- Arduino Uno or Nano
- DHT11 temperature and humidity sensor
- Servo motor
- Buzzer
- Breadboard
- Jumper wires
- USB cable
- Kettle or a setup that simulates a kettle mechanism

## Pin Connections

| **Function** | **Arduino Pins** |
| --- | --- |
| DHT11 Data | Pin 12 |
| Servo Motor | Pin 13 |
| Buzzer | Pin 11 |

## System Operation

1. The Arduino initializes the DHT11 sensor, servo motor, buzzer, and Serial Monitor.
2. The servo starts at position 0°.
3. The DHT11 sensor continuously measures the temperature.
4. The current temperature is displayed through the Serial Monitor.
5. When the temperature reaches or exceeds **40°C**, the system:
   - Activates the buzzer for 700 milliseconds.
   - Moves the servo to 90° to simulate turning off the kettle.
   - Returns the servo to 0°.
6. The system prevents the alert from being triggered repeatedly while the temperature remains at or above the threshold.
7. Once the temperature falls below 40°C, the system resets and becomes ready to detect the threshold again.
8. Temperature readings are taken approximately once every second.

## Setup

1. Connect the DHT11 sensor, servo motor, and buzzer according to the pin connection table.
2. Install the **DHT sensor library** and **Servo library** in the Arduino IDE.
3. Open the `experiment4(1).ino` sketch in the Arduino IDE.
4. Select the appropriate Arduino board and port under **Tools**.
5. Upload the sketch to the Arduino.
6. Open the Serial Monitor and set the baud rate to **9600**.
7. Monitor the temperature as the sensor detects changes.
8. When the temperature reaches 40°C, observe the buzzer and servo response.

## Threshold Configuration

The temperature threshold can be modified in the Arduino sketch:

```cpp
int temperatureThreshold = 40;
```

## Conclusion

The experiment successfully demonstrated an automated kettle shut-off system using an Arduino, DHT11 temperature sensor, buzzer, and servo motor. The system monitored the temperature and, when the temperature reached 40°C, activated an audible alert and moved the servo motor to simulate turning off the kettle.

The implementation also demonstrated the importance of coordinating sensor readings with actuator responses. The use of an alert state prevented repeated activation while the temperature remained above the threshold, while resetting the state below the threshold allowed the system to respond to a new heating cycle.

Although sensor stability and servo timing presented challenges, troubleshooting and refining the Arduino program improved the reliability of the system. The experiment reinforced concepts in microprocessor and logic circuit theory, particularly the use of sensors as inputs, programmed decision-making, and actuators as outputs.

## Video Documentation

- [Project Demonstration and Testing Videos](https://drive.google.com/drive/folders/15YuWVhxLXEzo-eac-ZgDCw8U7hlutb1O?usp=sharing)
