# Smart-Lighting-System-with-Motion-and-Light-Sensor
This project is a smart lighting system using an Arduino UNO, which automatically turns on an LED light when motion is detected and the ambient light is low

## Project Overview

The system uses two sensors:
- PIR sensor for motion detection
- LDR (photoresistor) for light detection

When the environment is dark and motion is detected, the LED will turn on automatically. Otherwise, it remains off.

## Components Used

| Component           | Quantity | Description                         |
|--------------------|----------|-------------------------------------|
| Arduino UNO         | 1        | Main microcontroller board          |
| PIR Sensor          | 1        | Motion detection sensor             |
| LDR (Photoresistor) | 1        | Light intensity sensor              |
| LED (Red)           | 1        | Output light indicator              |
| Resistor (10kΩ)     | 1        | Used with LDR for voltage divider  |
| Resistor (220Ω)     | 1        | Current limiter for LED            |
| Breadboard          | 1        | For prototyping circuit             |
| Jumper Wires        | -        | For connecting components           |

## Circuit Connections

### LDR:
- One leg to 5V
- Other leg to A0 and 10kΩ resistor to GND

### PIR Sensor:
- VCC to 5V
- GND to GND
- OUT to Digital Pin 2

### LED:
- Anode (long leg) to Digital Pin 4 through 220Ω resistor
- Cathode (short leg) to GND

## Code Explanation

The Arduino reads:
- The analog value from the LDR (0–1023)
- The digital value from the PIR sensor (LOW/HIGH)

If motion is detected and the light level is below 900, the LED turns on.

<img width="1944" height="967" alt="Screenshot 2025-07-18 221709" src="https://github.com/user-attachments/assets/ce29f68d-2899-4441-970e-ddf817eee326" />
<img width="1818" height="977" alt="Screenshot 2025-07-18 221601" src="https://github.com/user-attachments/assets/182254bc-1006-405f-95bd-839b22ff7032" />
<img width="499" height="155" alt="Screenshot 2025-07-18 221650" src="https://github.com/user-attachments/assets/4eb7bbd4-4e97-4999-ae91-54026d99ea2e" />




