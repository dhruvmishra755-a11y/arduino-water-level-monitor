# Components and Connections

## Bill of Materials

| # | Component | Quantity | Notes |
|---:|---|---:|---|
| 1 | Arduino UNO | 1 | Main controller |
| 2 | HC-SR04 ultrasonic sensor | 1 | Water-distance measurement |
| 3 | LEDs | 4 | One red LED recommended for 100% |
| 4 | 220Ω resistors | 4 | One per LED |
| 5 | Active buzzer | 1 | Continuous alarm at 100% |
| 6 | Breadboard | 1 | Prototype assembly |
| 7 | Jumper wires | As required | Connections |
| 8 | USB cable | 1 | Programming and power |

## Pin Map

| Arduino Pin | Connected Component |
|---|---|
| 5V | HC-SR04 VCC |
| GND | HC-SR04 GND, LED cathodes, buzzer negative |
| D2 | LED 1 (10%) through 220Ω resistor |
| D3 | LED 2 (40%) through 220Ω resistor |
| D4 | LED 3 (80%) through 220Ω resistor |
| D5 | LED 4 (100%, red) through 220Ω resistor |
| D6 | HC-SR04 ECHO |
| D7 | HC-SR04 TRIG |
| D8 | Active buzzer positive |

**LED polarity:** The long leg is usually the anode (+); the short leg is usually the cathode (−). Confirm component polarity before powering the circuit.
