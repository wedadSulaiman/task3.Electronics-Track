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

