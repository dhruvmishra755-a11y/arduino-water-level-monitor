# Project Report: Arduino-Based Smart Water Level Monitoring System

## 1. Introduction

Water-level monitoring is useful in homes, laboratories, agriculture, and storage systems. Overflow can waste water, while insufficient water can interrupt daily activities. This project demonstrates a low-cost electronic system that estimates the water level and provides visual and audible alerts.

## 2. Objective

- Measure the distance between a sensor and the water surface.
- Convert the distance into a percentage.
- Indicate selected water-level thresholds with LEDs.
- Trigger a continuous buzzer when the tank reaches the calibrated 100% level.

## 3. Hardware Used

The prototype uses an Arduino UNO, HC-SR04 ultrasonic sensor, four LEDs, four 220Ω resistors, an active buzzer, breadboard, jumper wires, and a USB cable.

## 4. Working Principle

The HC-SR04 emits an ultrasonic pulse and measures the time taken for its echo to return. The Arduino converts this time into distance. Because the sensor is mounted above the water, a smaller measured distance means a higher water level.

The prototype is calibrated with:
- 11.4 cm representing 0%
- 5.88 cm representing 100%

The Arduino maps the measured distance linearly between these two calibration points and limits the result to 0–100%.

## 5. Output Logic

| Level | Output |
|---|---|
| Below 10% | All LEDs and buzzer OFF |
| 10% | LED 1 ON |
| 40% | LED 1 and LED 2 ON |
| 80% | LED 1, LED 2, and LED 3 ON |
| 100% | All LEDs ON and continuous buzzer |

Each threshold LED remains ON as the level rises above its threshold.

## 6. Procedure

1. Assemble the circuit according to the pin map in `COMPONENTS.md`.
2. Mount the HC-SR04 above the water surface, facing downward.
3. Upload `src/water_level_monitor.ino` to the Arduino UNO.
4. Open the Serial Monitor at 9600 baud.
5. Test the system at different water levels.
6. Adjust the calibration constants if the physical tank dimensions require it.

## 7. Expected Outcome

The Serial Monitor displays measured distance and estimated water-level percentage. LEDs provide a quick visual indication, and the active buzzer continuously alerts when the calibrated maximum level is reached.

## 8. Limitations

- The percentage estimate assumes a linear tank geometry.
- Ultrasonic readings can be affected by turbulence, angled surfaces, condensation, or obstructions.
- The calibration values are specific to the current prototype.
- This prototype is not a certified industrial safety system.

## 9. Future Scope

Possible improvements include an LCD/OLED, Wi-Fi dashboard, mobile alerts, data logging, and automatic pump control using a properly rated relay or motor driver.

## 10. Conclusion

The project demonstrates a practical application of embedded systems and sensor interfacing. It provides a simple, low-cost method to monitor water level and alert users to a full tank.
