# 💧 Arduino-Based Smart Water Level Monitoring System

An Arduino UNO project that monitors water level using an **HC-SR04 ultrasonic sensor**, displays the level through four LEDs, and activates a continuous buzzer alert when the tank reaches 100%.

![Arduino Water Level Monitoring System](images/project-banner.png)

## ✨ Features

- 📏 Measures water distance using the HC-SR04 ultrasonic sensor
- 📊 Converts measured distance into a water-level percentage
- 💡 Four visual level indicators at **10%, 40%, 80%, and 100%**
- 🚨 Continuous buzzer alert at 100% until the water level falls
- 🖥️ Serial Monitor output at 9600 baud
- 🧰 Simple, low-cost prototype using Arduino UNO

## 🧠 How It Works

The HC-SR04 is mounted above the water surface and measures the distance to the water.

The project uses these calibration points:

| Calibration | Distance |
|---|---:|
| 0% water level | 11.4 cm |
| 100% water level | 5.88 cm |

The percentage is calculated using:

```text
Water Level (%) = (Empty Distance - Measured Distance)
                  / (Empty Distance - Full Distance) × 100
```

The result is constrained between 0% and 100%.

## 🔌 Components Required

- Arduino UNO
- HC-SR04 ultrasonic sensor
- 4 LEDs (include one red LED for the 100% indicator)
- 4 × 220Ω resistors (one per LED)
- Active buzzer
- Breadboard and jumper wires
- USB cable
- Water container/tank for demonstration

## 🔗 Circuit Connections

| Component | Pin | Arduino UNO |
|---|---|---|
| HC-SR04 | VCC | 5V |
| HC-SR04 | GND | GND |
| HC-SR04 | TRIG | D7 |
| HC-SR04 | ECHO | D6 |
| LED 1 | Anode (+), through 220Ω resistor | D2 |
| LED 2 | Anode (+), through 220Ω resistor | D3 |
| LED 3 | Anode (+), through 220Ω resistor | D4 |
| LED 4 (Red) | Anode (+), through 220Ω resistor | D5 |
| All LEDs | Cathode (−) | GND |
| Active buzzer | Positive (+) | D8 |
| Active buzzer | Negative (−) | GND |

> **LED wiring:** Arduino digital pin → 220Ω resistor → LED long leg (anode). LED short leg (cathode) → GND.

## 🚦 LED and Alarm Logic

| Water level | Indicators |
|---|---|
| 0–9% | All LEDs OFF; buzzer OFF |
| 10–39% | LED 1 ON |
| 40–79% | LED 1 + LED 2 ON |
| 80–99% | LED 1 + LED 2 + LED 3 ON |
| 100% | All LEDs ON + continuous buzzer |

The buzzer is assumed to be an **active buzzer**. It remains ON continuously at 100%, and turns OFF when the level drops below 100%.

## 💻 Arduino Code

The complete sketch is available here:

[`src/water_level_monitor.ino`](src/water_level_monitor.ino)

### Upload Instructions

1. Install/open the Arduino IDE.
2. Connect the Arduino UNO using USB.
3. Open `src/water_level_monitor.ino`.
4. Select **Tools → Board → Arduino UNO**.
5. Select the correct **Tools → Port**.
6. Click **Upload**.
7. Open **Tools → Serial Monitor** and select **9600 baud**.

## 🧪 Calibration

The current calibration is set to:

```cpp
const float EMPTY_DISTANCE = 11.4;  // 0%
const float FULL_DISTANCE  = 5.88;  // 100%
```

If your actual tank geometry changes, measure the distance from the sensor to the water at the desired 0% and 100% points, then update these constants.

## 📁 Repository Structure

```text
arduino-water-level-monitor/
├── README.md
├── LICENSE
├── .gitignore
├── src/
│   └── water_level_monitor.ino
├── docs/
│   ├── COMPONENTS.md
│   └── PROJECT_REPORT.md
└── images/
    └── project-banner.png
```

## 🔮 Future Improvements

- Add an LCD/OLED percentage display
- Add Wi-Fi monitoring using ESP8266/ESP32
- Add mobile notifications
- Add automatic pump control with a relay module
- Add low-water and overflow protection

## ⚠️ Safety Notes

- Use a resistor in series with **each LED**.
- Keep Arduino and exposed wiring away from water.
- Do not connect a water pump directly to an Arduino pin; use a properly rated driver/relay module and suitable isolation.
- This is an educational prototype, not a certified industrial water safety device.

## 👨‍💻 Author

**Project:** Arduino-Based Smart Water Level Monitoring System  
**Platform:** Arduino UNO  
**Language:** C++ (Arduino)
