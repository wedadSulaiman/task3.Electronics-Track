## ReadMe file for all qestion in task 3:

# q1:
# latching-power-switch-auto-off
Control an LED and the Arduino with a single button, using two PNP transistors and a PIR motion sensor.   The system automatically shuts down (turns off the LED and simulates Arduino power off) after 5 seconds of no motion or button press.

---

## Components

- Arduino Uno  
- 2 x PNP Transistors (e.g., TIP127)  
- Push Button  
- LED (Main indicator)  
- LED (Shutdown indicator)  
- PIR Motion Sensor  
- Appropriate resistors and jumper wires

---

## Wiring

- Button to pin D3 (INPUT_PULLUP)  
- PIR sensor to pin D2  
- Main LED to pin D4  
- Shutdown indicator LED to pin D6  
- PNP transistor #1 controls Arduino power  
- PNP transistor #2 controls the LED
<img width="1454" height="1059" alt="Screenshot 2025-07-18 183142" src="https://github.com/user-attachments/assets/8fcff3d0-3e26-46e6-93d8-971d9d702d81" />

---

## Code Behavior

- Pressing the button or detecting motion turns on the LED and “powers” the Arduino.  
- After 5 seconds of inactivity, the LED turns off and the shutdown indicator LED turns on.  
- Since Arduino cannot truly power off in simulation (e.g., Tinkercad), the code includes a **Serial message** that prints when auto shutdown is triggered, indicating the intended Arduino power-off.

<img width="911" height="1001" alt="Screenshot 2025-07-18 184036" src="https://github.com/user-attachments/assets/680b43e1-c5ba-42d5-911d-c3ce14d3c2df" />


## Images

- LED ON after pressing the button
- <img width="1592" height="1067" alt="Screenshot 2025-07-18 183746" src="https://github.com/user-attachments/assets/733cfe31-662b-475b-8564-5d00508205e8" />

- LED OFF after 5 seconds with shutdown indicator ON
- <img width="1500" height="1073" alt="Screenshot 2025-07-18 183808" src="https://github.com/user-attachments/assets/dfb2e11c-da41-47e6-8828-0c6a727e7f65" />


---


# q2:
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






