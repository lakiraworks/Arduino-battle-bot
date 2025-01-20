# Arduino Analog Voltage Reader and LED Control

This Arduino sketch reads analog voltage values from four input pins (`A0`, `A1`, `A2`, `A3`) and outputs these values to the serial monitor. Additionally, it controls an LED connected to digital pin 13 based on the voltage value from `A0`.

## Features
- Reads voltage values from analog pins: `A0`, `A1`, `A2`, and `A3`.
- Outputs the voltage readings to the serial monitor.
- Turns an LED ON or OFF based on the voltage value from `A0`.

## Circuit Diagram
1. Connect analog sensors or voltage sources to the following pins:
   - `A0`
   - `A1`
   - `A2`
   - `A3`
2. Connect an LED to digital pin `13` with a current-limiting resistor.

## Code Explanation
- **Pin Initialization**: 
  - Analog pins `A0`, `A1`, `A2`, `A3` are set as inputs.
  - Digital pin `13` is set as output for the LED.
- **Serial Communication**:
  - The serial monitor is initialized at `9600` baud rate.
  - Voltage readings are printed as `Variable_1`, `Variable_2`, `Variable_3`, and `Variable_4`.
- **LED Control**:
  - The LED on pin `13` is turned ON if the voltage read from `A0` is below 10. Otherwise, it is turned OFF.

## Code

```cpp
int led = 13;

int voltage = A0;
int voltage1 = A1;
int voltage2 = A2;
int voltage3 = A3;

int vol = 0;
int vol2 = 0;
int vol3 = 0;
int vol4 = 0;

void setup() {
  pinMode(voltage, INPUT);
  pinMode(voltage1, INPUT);
  pinMode(voltage2, INPUT);
  pinMode(voltage3, INPUT);

  pinMode(13, OUTPUT);

  Serial.begin(9600);
}

void loop() {
  vol = analogRead(voltage);
  Serial.print("Variable_1: ");
  Serial.println(vol);

  vol2 = analogRead(voltage1);
  Serial.print("Variable_2: ");
  Serial.println(vol2);
  delay(99);

  vol3 = analogRead(voltage2);
  Serial.print("Variable_3: ");
  Serial.println(vol3);
  delay(99);

  vol4 = analogRead(voltage3);
  Serial.print("Variable_4: ");
  Serial.println(vol4);
  delay(99);

  if (vol < 10) {
    digitalWrite(led, HIGH);
  } else {
    digitalWrite(led, LOW);
  }
}

