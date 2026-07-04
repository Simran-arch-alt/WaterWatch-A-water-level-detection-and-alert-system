# Flood Water Level Monitoring System using Arduino

## Overview

This project is an Arduino-based Flood Water Level Monitoring System that uses an HC-SR04 Ultrasonic Sensor to measure the distance between the sensor and the water surface. 
Based on the measured distance, the system indicates the water level using LEDs and activates a buzzer when the water reaches a dangerous level.

The project is suitable for learning embedded systems, IoT, and disaster monitoring applications.

---

## Features

- Real-time water level monitoring
- Three-level warning system:
  - 🟢 Safe Zone
  - 🟡 Alert Zone
  - 🔴 Danger Zone
- Audible alarm using a buzzer
- Distance displayed on the Serial Monitor
- Non-blocking buzzer timing using `millis()`

---

## Components Required

| Component | Quantity |
|-----------|----------|
| Arduino Uno | 1 |
| HC-SR04 Ultrasonic Sensor | 1 |
| Green LED | 1 |
| Yellow LED | 1 |
| Red LED | 1 |
| Active Buzzer | 1 |
| 220Ω Resistors | 3 |
| Breadboard | 1 |
| Jumper Wires | Several |

---

## Pin Connections

| Component | Arduino Pin |
|-----------|-------------|
| HC-SR04 Trigger | D9 |
| HC-SR04 Echo | D10 |
| Green LED | D3 |
| Yellow LED | D4 |
| Red LED | D5 |
| Buzzer | D6 |

---

## Water Level Thresholds

| Distance | Status | LED | Buzzer |
|----------|--------|-----|---------|
| ≥ 9 cm | Safe | Green | OFF |
| 8–9 cm | Alert | Yellow | OFF |
| < 8 cm | Danger | Red | ON (2 sec ON, 5 sec OFF) |

---

## How It Works

1. The HC-SR04 measures the distance between the sensor and the water surface.
2. The Arduino calculates the distance in centimeters.
3. Depending on the measured distance:
   - Green LED indicates a safe water level.
   - Yellow LED indicates the water is rising.
   - Red LED indicates a critical water level.
4. In the danger zone, the buzzer sounds periodically:
   - ON for 2 seconds
   - OFF for 5 seconds
5. The current distance and system status are displayed in the Serial Monitor.

---

## Serial Monitor Output

Example:

```
Distance: 10.25 cm
STATUS: SAFE
--------------------

Distance: 8.45 cm
STATUS: ALERT - Water rising!
--------------------

Distance: 7.35 cm
STATUS: DANGER - Flood level critical!
--------------------
```

---

## Installation

1. Clone the repository:

```bash
git clone https://github.com/yourusername/Flood-Water-Level-Monitoring.git
```

2. Open the project in the Arduino IDE.

3. Connect the hardware according to the wiring table.

4. Select:
   - Board: Arduino Uno
   - Correct COM Port

5. Upload the code.

6. Open the Serial Monitor (9600 baud).

---

## Future Improvements

- GSM/SMS alert notifications
- Wi-Fi/IoT monitoring
- LCD or OLED display
- Mobile application
- Data logging to cloud
- Battery backup system

---

## Technologies Used

- Arduino IDE
- C/C++
- HC-SR04 Ultrasonic Sensor

---

## License

This project is open-source and available under the MIT License.

---

## Author

**Simran Karmacharya**
